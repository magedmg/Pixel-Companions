#include "Game.hpp"
#include "Food.hpp"
#include "raylib.h"
#include <iostream>
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

  // Coin in the menu
  coinBarImage = LoadImage("resources/Coins/c1.png");
  ImageResize(&coinBarImage, 35, 40);
  coinBarTexture = LoadTextureFromImage(coinBarImage);

  randomCoinInterval = GetRandomValue(5, 10);
  lastCoinTime = GetTime();
}

void Game::updateAll() {
  flag = 0;

  DrawTextureV(bgImageTexture, {0, 0}, WHITE);

  dog.Draw();

  dog.Poo1();

  for (int i = 0; i < dog.currentPooCount; i++) {
    dog.poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle mouseRect = {mousePos.x, mousePos.y, 1, 1};

    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < dog.currentPooCount; i++) {
      if (CheckCollisionRecs(dog.poos[i]->getRect(), collisionRect)) {
        dog.poos[i]->deactivate();
        flag = 1;
      }
    }
  }
  if (flag == 0) {
    Vector2 mousePos = GetMousePosition();
    Rectangle mouseRect = {mousePos.x, mousePos.y, 1, 1};
    if (!CheckCollisionRecs(mouseRect, food.foodButtonRect)) {
      dog.Update();
    }
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

  // Drawing food on the screen and updating it each frame
  food.draw();
  food.update(dog.position, dog.targetPosition, dog.isRunning, dog.movingRight);

  // Water
  water.draw();
  water.update();
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
      coin.collision = true;
      coin.collisionTime = GetTime();
    }
  }
}
