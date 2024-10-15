#include "Coin.hpp"
#include "raylib.h"
#include <filesystem>
#include <iostream>
#include <string>

Coin::Coin(Vector2 position) {
  for (int i = 1; i < 7; i++) {
    coinImage = LoadImage(TextFormat("../resources/Coins/c%d.png", i));
    ImageResize(&coinImage, 15, 35);
    coinTextures[i - 1] = LoadTextureFromImage(coinImage);

    UnloadImage(coinImage); // Unload image after converting to texture
  }
  collision = false;
  active = true;
  frameTime = 0.0;
  currentFrame = 0;
  frameSpeed = 0.2;
  this->position = position;
  moveSpeed = 70;
}

void Coin::Draw() {

  if (active && !collision) {
    float deltaTime = GetFrameTime();
    // Update frametime and change frames
    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0; // Reset frame time

      currentFrame = (currentFrame + 1) % 6;
    }
    if (currentFrame > 6) {
      currentFrame = 0;
    }
    DrawTexture(coinTextures[currentFrame], position.x, position.y, WHITE);
  } else if (active && collision) {
    float deltaTime = GetFrameTime();
    // Update frametime and change frames
    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0; // Reset frame time

      currentFrame = (currentFrame + 1) % 6;
    }
    if (currentFrame > 6) {
      currentFrame = 0;
    }
    position.y -=
        deltaTime * moveSpeed; // moves the coin up because the cat touched it
    DrawTexture(coinTextures[currentFrame], position.x, position.y, WHITE);
    if (GetTime() - collisionTime >= 3) {
      active = false; // after 3 seconds stop drawing the coin on the screen
    }
  }
}

Rectangle Coin::getRect() {
  // returns coin collision rectangle, no rectagle when coin has been touched
  if (collision == true) {
    return {0, 0, 0, 0};
  } else {
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.height = coinImage.height;
    rect.width = coinImage.width;
    return rect;
  }
}