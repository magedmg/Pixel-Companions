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
  DrawText(std::to_string(shibaInu.currentHunger).c_str(), 370, 20, 30, RED);
  DrawTextureV(hungerTexture, {330, 20}, WHITE);

  DrawText(std::to_string(shibaInu.currentThirst).c_str(), 500, 20, 30, BLUE);
  DrawTextureV(waterTexture, {460, 20}, WHITE);

  DrawText(std::to_string(shibaInu.currentHappiness).c_str(), 630, 20, 30, PINK);
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

  shibaInu.Draw();
  shibaInu.Poo1();

  for (int i = 0; i < shibaInu.currentPooCount; i++) {
    shibaInu.poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle mouseRect = {mousePos.x, mousePos.y, 1, 1};

    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < shibaInu.currentPooCount; i++) {
      if (CheckCollisionRecs(shibaInu.poos[i]->getRect(), collisionRect)) {
        shibaInu.poos[i]->deactivate();
        scoreValue += 30;
        flag = 1;
      }
    }

    // Checks if the pet has been petted
    if (CheckCollisionRecs(mouseRect, shibaInu.getRect())) {
      if (GetTime() - lastTimePetted > 4) {
        pet.Update(shibaInu.position);
        lastTimePetted = GetTime(); // reset the last time petted
        if (shibaInu.currentHappiness + 25 > 100) {
          shibaInu.currentHappiness = 100;
        } else {
          shibaInu.currentHappiness += 25;
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
    shibaInu.Update();
  }

  pet.Draw();

  shibaInu.Draw();
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
  food.update(shibaInu.position, shibaInu.targetPosition, shibaInu.isRunning,
              shibaInu.movingRight);

  // Health
  health.Draw();

  // if status bars are not replenished, deplete them
  shibaInu.updateStatus();

  // if any status bar is 0, take damage every second the status bar is 0
  if (shibaInu.currentHappiness == 0 || shibaInu.currentHunger == 0 ||
      shibaInu.currentThirst == 0) {
    if (GetTime() - lastTimeDamaged > 1.5) {
      for (int i = 0; i < 5; i++) {
        health.takeDamage(1);
      }
      lastTimeDamaged = GetTime();
      if (health.getHealth() == 0) {
        if (petAlive == true) {
          petAlive = false;
          shibaInu.isRunning = false;
          shibaInu.isDead = true;
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
    if (CheckCollisionRecs(coin.getRect(), shibaInu.getRect())) {
      if (coin.collision == false) {
        coinCounter += 1;
        scoreValue += 20;
      }
      coin.collision = true;
      coin.collisionTime = GetTime();
    }
  }

  // if cat rectangle collides with water bowl rectangle, empty the water bowl
  if (CheckCollisionRecs(water.getRect(), shibaInu.getRect())) {
    water.drink();
    shibaInu.lastDrankTime = GetTime();
    if (shibaInu.currentThirst + 25 > 100) {
      shibaInu.currentThirst = 100;
    } else {
      shibaInu.currentThirst += 25;
    }
  }

  // if cat rectangle collides with fish rectangle, consume fish
  if (CheckCollisionRecs(food.getRect(), shibaInu.getRect())) {
    food.eat();
    shibaInu.lastFedTime = GetTime();
    if (shibaInu.currentHunger + 50 > 100) {
      shibaInu.currentHunger = 100;
    } else {
      shibaInu.currentHunger += 50;
    }
  }
}

/*void Game::replayGame() {
  DrawText("You died!", 500, 135, 35, WHITE);
  DrawText("Play again?", 500, 135, 35, WHITE);
}
*/
