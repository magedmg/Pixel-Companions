#include "Game.hpp"

#include <raylib.h>

#include <iostream>
#include <string>

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

  levelText = "LVL ";

  petAlive = true;

  petBreed = "pinkCat";
  createPet(petBreed);
}

void Game::updateAll() {

  DrawTextureV(bgImageTexture, {0, 0}, WHITE);
  DrawText(std::to_string(coinCounter).c_str(), 915, 655, 30, WHITE);
  DrawText(std::to_string(scoreValue + scoreTimer).c_str(), 30, 648, 50, WHITE);

  // display status values
  DrawText(std::to_string(currentPet->currentHunger).c_str(), 370, 20, 30, RED);
  DrawTextureV(hungerTexture, {330, 20}, WHITE);

  DrawText(std::to_string(currentPet->currentThirst).c_str(), 500, 20, 30,
           BLUE);
  DrawTextureV(waterTexture, {460, 20}, WHITE);

  // display current pet level
  DrawText("LVL ", 13, 75, 40, BLACK);
  DrawText(std::to_string(currentPet->level).c_str(), 106, 75, 40, BLACK);

  if (currentPet->petType == "cat") {
    DrawText(std::to_string(currentPet->currentHappiness).c_str(), 630, 20, 30,
             PINK);
    DrawTextureV(happinessTexture, {590, 20}, WHITE);
  }

  // displays cost for food
  DrawTextureV(coinBarTexture, {885, 130}, WHITE);
  DrawText("2", 930, 135, 35, WHITE);

  // displays cost for water
  DrawTextureV(coinBarTexture, {770, 130}, WHITE);
  DrawText("1", 815, 135, 35, WHITE);

  int scoreTimer = GetTime(); // current time elapsed in seconds
  flag = 0;

  // Water
  water.draw();
  if (petAlive) {
    water.update();
    currentPet->Poo1();
  }

  currentPet->Draw();

  for (int i = 0; i < currentPet->currentPooCount; i++) {
    currentPet->poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle mouseRect = {mousePos.x, mousePos.y, 1, 1};

    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < currentPet->currentPooCount; i++) {
      if (CheckCollisionRecs(currentPet->poos[i]->getRect(), collisionRect)) {
        currentPet->poos[i]->deactivate();
        scoreValue += 30;
        flag = 1;
      }
    }

    if (currentPet->petType == "cat") {
      // Checks if the pet has been petted
      if (CheckCollisionRecs(mouseRect, currentPet->getRect())) {
        if (GetTime() - lastTimePetted > 4) {
          pet.Update(currentPet->position);
          lastTimePetted = GetTime(); // reset the last time petted
          if (currentPet->currentHappiness + 25 > 100) {
            currentPet->currentHappiness = 100;
          } else {
            currentPet->currentHappiness += 25;
          }
        }
        flag = 1; // so that the cat doesnt move
      }
    }
    // If the user clicks the food and water buttons dont move the pet
    if (CheckCollisionRecs(mouseRect, food.foodButtonRect) ||
        CheckCollisionRecs(mouseRect, water.waterButtonRect)) {
      flag = 1;
    }
  }

  if (flag == 0) {
    currentPet->Update();
  }

  pet.Draw();

  currentPet->Draw();
  DrawTextureV(healthBarTexture, {10, 10}, WHITE);
  DrawTextureV(coinBarTexture,
               {static_cast<float>(windowWidth - coinBarImage.width) - 20,
                static_cast<float>(windowHeight - coinBarImage.height) - 10},
               WHITE);

  if (petAlive) {
    loadCoins();

    for (auto &coin : coins) {
      coin.Draw();
    }

    checkCollisions();
  }

  // Drawing food on the screen and updating it each frame
  food.draw();
  if (petAlive) {
    food.update(currentPet->position, currentPet->targetPosition,
                currentPet->isRunning, currentPet->movingRight);
  }
  // Health
  health.Draw();

  // if status bars are not replenished, deplete them
  currentPet->updateStatus();

  // if any status bar is 0, take damage every second the status bar is 0
  if (currentPet->currentHappiness == 0 || currentPet->currentHunger == 0 ||
      currentPet->currentThirst == 0) {
    if (GetTime() - lastTimeDamaged > 1.5) {
      for (int i = 0; i < 5; i++) {
        health.takeDamage(1);
      }
      lastTimeDamaged = GetTime();
      if (health.getHealth() == 0) {
        if (petAlive == true) {
          petAlive = false;
          currentPet->isRunning = false;
          currentPet->isDead = true;
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
        GetRandomValue(5, 10); // Get a new interval for the next coin to spawn
    float randomSpawn = GetRandomValue(
        20, 980); // set to float so that it can be passed in the pushback

    coins.push_back(Coin({randomSpawn, 525}));
  }
}

void Game::checkCollisions() {
  for (auto &coin : coins) { // if pet touches with coin, consume coin
    if (CheckCollisionRecs(coin.getRect(), currentPet->getRect())) {
      if (coin.collision == false) {
        coinCounter += 1;
        scoreValue += 20;
      }
      coin.collision = true;
      coin.collisionTime = GetTime();
    }
  }

  // if pet rectangle collides with water bowl rectangle, empty the water bowl
  if (CheckCollisionRecs(water.getRect(), currentPet->getRect())) {
    water.drink();
    currentPet->lastDrankTime = GetTime();
    if (currentPet->currentThirst + 25 > 100) {
      currentPet->currentThirst = 100;
    } else {
      currentPet->currentThirst += 25;
    }
  }

  // if pet rectangle collides with fish rectangle, consume fish
  if (CheckCollisionRecs(food.getRect(), currentPet->getRect())) {
    food.eat();
    currentPet->lastFedTime = GetTime();
    if (currentPet->currentHunger + 50 > 100) {
      currentPet->currentHunger = 100;
    } else {
      currentPet->currentHunger += 50;
    }
  }
}

void Game::createPet(std::string petBreed) {

  //  creates pet breed
  if (petBreed == "pinkCat") {
    currentPet = new pinkCat();
  } else if (petBreed == "greyCat") {
    currentPet = new greyCat();
  } else if (petBreed == "shibaInu") {
    currentPet = new shibaInu();
  }
}

/*void Game::replayGame() {
  DrawText("You died!", 500, 135, 35, WHITE);
  DrawText("Play again?", 500, 135, 35, WHITE);
}
*/
