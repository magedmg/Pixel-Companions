#include "Game.hpp"
#include <iostream>
#include <raylib.h>
#include <string>
using namespace std;

Game::Game() {
  // Load and resize background image
  bgImage = LoadImage("resources/bg.png");
  ImageResize(&bgImage, windowWidth, windowHeight);
  bgImageTexture = LoadTextureFromImage(bgImage);

  // Load health bar image and resize it
  healthBarImage = LoadImage("resources/health bar.png");
  ImageResize(&healthBarImage, 300, 40);
  healthBarTexture = LoadTextureFromImage(healthBarImage);

  // Load fish hunger image and resize it
  hungerImage = LoadImage("resources/food/fish.png");
  ImageResize(&hungerImage, 30, 30);
  hungerTexture = LoadTextureFromImage(hungerImage);

  // Load water image and resize it
  waterImage = LoadImage("resources/water.png");
  ImageResize(&waterImage, 30, 30);
  waterTexture = LoadTextureFromImage(waterImage);

  // Load heart happiness image and resize it
  happinessImage = LoadImage("resources/happiness.png");
  ImageResize(&happinessImage, 30, 30);
  happinessTexture = LoadTextureFromImage(happinessImage);

  // Coin in the menu
  coinBarImage = LoadImage("resources/Coins/c1.png");
  ImageResize(&coinBarImage, 35, 40);
  coinBarTexture = LoadTextureFromImage(coinBarImage);

  randomCoinInterval = GetRandomValue(5, 10);
  lastCoinTime = GetTime();
  lastTimeDamaged = GetTime();
  lastTimeHealed = GetTime();
  lastTimePetted = GetTime();

  coinCounter = 0;
  scoreValue = 0;

  food.getCoins(&coinCounter);
  water.getCoins(&coinCounter);

  petAlive = true;
}

void Game::updateAll() {
  int scoreTimer = GetTime(); // current time elapsed in seconds
  flag = 0;

  DrawTextureV(bgImageTexture, {0, 0}, WHITE);
  DrawText(to_string(coinCounter).c_str(), 915, 655, 30, WHITE);
  DrawText(to_string(scoreValue + scoreTimer).c_str(), 30, 648, 50, WHITE);

  // display status values
  DrawText(std::to_string(greyCat.currentHunger).c_str(), 370, 20, 30, RED);
  DrawTextureV(hungerTexture, {330, 20}, WHITE);

  DrawText(std::to_string(greyCat.currentThirst).c_str(), 500, 20, 30, BLUE);
  DrawTextureV(waterTexture, {460, 20}, WHITE);

  DrawText(std::to_string(greyCat.currentHappiness).c_str(), 630, 20, 30, PINK);
  DrawTextureV(happinessTexture, {590, 20}, WHITE);

  // displays cost for food
  DrawTextureV(coinBarTexture, {885, 130}, WHITE);
  DrawText("2", 930, 135, 35, WHITE);

  // displays cost for water
  DrawTextureV(coinBarTexture, {770, 130}, WHITE);
  DrawText("1", 815, 135, 35, WHITE);

  // Water
  water.draw();
  water.update();

  greyCat.Draw();
  greyCat.Poo1();

  for (int i = 0; i < greyCat.currentPooCount; i++) {
    greyCat.poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle mouseRect = {mousePos.x, mousePos.y, 1, 1};

    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < greyCat.currentPooCount; i++) {
      if (CheckCollisionRecs(greyCat.poos[i]->getRect(), collisionRect)) {
        greyCat.poos[i]->deactivate();
        scoreValue += 30;
        flag = 1;
      }
    }

    // Checks if the pet has been petted
    if (CheckCollisionRecs(mouseRect, greyCat.getRect())) {
      if (GetTime() - lastTimePetted > 4) {
        pet.Update(greyCat.position);
        lastTimePetted = GetTime(); // reset the last time petted
        if (greyCat.currentHappiness + 25 > 100) {
          greyCat.currentHappiness = 100;
        } else {
          greyCat.currentHappiness += 25;
        }
      }
      flag = 1; // so that the cat doesnt move
    }
    // If the user clicks the food and water buttons dont move the pet
    if (CheckCollisionRecs(mouseRect, food.foodButtonRect) ||
        CheckCollisionRecs(mouseRect, water.waterButtonRect)) {
      flag = 1;
    }
  }
  if (flag == 0) {
    greyCat.Update();
  }

  pet.Draw();

  greyCat.Draw();
  DrawTextureV(healthBarTexture, {10, 10}, WHITE);
  DrawTextureV(coinBarTexture,
               {static_cast<float>(windowWidth - coinBarImage.width) - 20,
                static_cast<float>(windowHeight - coinBarImage.height) - 10},
               WHITE);

  loadCoins();

  for (auto &coin : coins) {
    coin.Draw();
  }

  checkCollisions();

  // Drawing food on the screen and updating it each frame
  food.draw();
  food.update(greyCat.position, greyCat.targetPosition, greyCat.isRunning,
              greyCat.movingRight);

  // Health
  health.Draw();

  // if status bars are not replenished, deplete them
  greyCat.updateStatus();

  // if any status bar is 0, take damage every second the status bar is 0
  if (greyCat.currentHappiness == 0 || greyCat.currentHunger == 0 ||
      greyCat.currentThirst == 0) {
    if (GetTime() - lastTimeDamaged > 1.5) {
      for (int i = 0; i < 5; i++) {
        health.takeDamage(1);
      }
      lastTimeDamaged = GetTime();
      if (health.getHealth() == 0) {
        if (petAlive == true) {
          petAlive = false;
          greyCat.isRunning = false;
          greyCat.isDead = true;
          // replayGame();
        }
      }
    }
  } else {
    if (GetTime() - lastTimeHealed > 2) {
      for (int i = 0; i < 5; i++) {
        health.healDamage(1);
      }
      lastTimeHealed = GetTime();
    }
  }
}
void Game::loadCoins() {
  if (GetTime() - lastCoinTime >= randomCoinInterval) {
    lastCoinTime = GetTime(); // Reset the last time a coin was spawned
    randomCoinInterval =
        GetRandomValue(5, 12); // Get a new interval for the next coin to spawn
    float randomSpawn = GetRandomValue(
        20, 980); // set to float so that it can be passed in the pushback

    coins.push_back(Coin({randomSpawn, 525}));
  }
}

void Game::checkCollisions() {
  for (auto &coin : coins) { // if pet touches with coin, consume coin
    if (CheckCollisionRecs(coin.getRect(), greyCat.getRect())) {
      if (coin.collision == false) {
        coinCounter += 1;
        scoreValue += 20;
      }
      coin.collision = true;
      coin.collisionTime = GetTime();
    }
  }

  // if cat rectangle collides with water bowl rectangle, empty the water bowl
  if (CheckCollisionRecs(water.getRect(), greyCat.getRect())) {
    water.drink();
    greyCat.lastDrankTime = GetTime();
    if (greyCat.currentThirst + 25 > 100) {
      greyCat.currentThirst = 100;
    } else {
      greyCat.currentThirst += 25;
    }
  }

  // if cat rectangle collides with fish rectangle, consume fish
  if (CheckCollisionRecs(food.getRect(), greyCat.getRect())) {
    food.eat();
    greyCat.lastFedTime = GetTime();
    if (greyCat.currentHunger + 50 > 100) {
      greyCat.currentHunger = 100;
    } else {
      greyCat.currentHunger += 50;
    }
  }
}

/*void Game::replayGame() {
  DrawText("You died!", 500, 135, 35, WHITE);
  DrawText("Play again?", 500, 135, 35, WHITE);
}
*/
