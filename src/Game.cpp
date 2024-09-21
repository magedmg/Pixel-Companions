#include "Game.hpp"
#include "DogX.hpp"
#include "Poop.hpp"
#include "raylib.h"
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

  // Coin in the menu
  coinBarImage = LoadImage("resources/Coins/c1.png");
  ImageResize(&coinBarImage, 35, 40);
  coinBarTexture = LoadTextureFromImage(coinBarImage);

  randomCoinInterval = GetRandomValue(5, 10);
  lastCoinTime = GetTime();

  coinCounter = 0;
  scoreValue = 0;
}

void Game::updateAll() {
  int scoreTimer = GetTime(); //current time elapsed in seconds
  flag = 0;

  DrawTextureV(bgImageTexture, {0, 0}, WHITE);
  DrawText(std::to_string(coinCounter).c_str(), 915, 655, 30, WHITE);
  DrawText(std::to_string(scoreValue + scoreTimer).c_str(), 30, 648, 50, WHITE);

  DrawText(std::to_string(dog.currentHunger).c_str(), 30, 60, 30, RED);
  DrawText(std::to_string(dog.currentThirst).c_str(), 30, 100, 30, BLUE);
  DrawText(std::to_string(dog.currentHappiness).c_str(), 30, 140, 30, PINK);
  dog.Draw();
  
  dog.Poo1();

  for (int i = 0; i < dog.currentPooCount; i++) {
    dog.poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < dog.currentPooCount; i++) {
      if (CheckCollisionRecs(dog.poos[i]->getRect(), collisionRect)) {
        dog.poos[i]->deactivate();
        scoreValue += 30;
        flag = 1;
      }
    }
  }
  if (flag == 0) {
    dog.Update();
  }
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

// decreases status bars over time if respective needs are not met
  if (GetTime() - dog.lastFedTime >= dog.hungerInterval) {
    dog.currentHunger -= 25;
    dog.lastFedTime = GetTime();
  }

  if (GetTime() - dog.lastDrankTime >= dog.thirstInterval) {
    dog.currentThirst -= 25;
    dog.lastDrankTime = GetTime();
  }

  if (GetTime() - dog.lastPetTime >= dog.happinessInterval) {
    dog.currentHappiness -= 25;
    dog.lastPetTime = GetTime();
  }
}

void Game::loadCoins() {
  if (GetTime() - lastCoinTime >= randomCoinInterval) {
    lastCoinTime = GetTime(); // Reset the last time a coin was spawned
    randomCoinInterval =
        GetRandomValue(10, 25); // Get a new interval for the next coin to spawn
    float randomSpawn = GetRandomValue(
        20, 980); // set to float so that it can be passed in the pushback

    coins.push_back(Coin({randomSpawn, 525}));
  }
}

void Game::checkCollisions() {
  for (auto &coin : coins) {
    if (CheckCollisionRecs(coin.getRect(), dog.getRect())) {
      if (coin.collision == false) {
        coinCounter += 1;
        scoreValue += 20;
      }
      coin.collision = true;
      coin.collisionTime = GetTime();
    }
    
  }
}
