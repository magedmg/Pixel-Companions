#include "Coin.hpp"
#include "raylib.h"
#include <filesystem>
#include <iostream>
#include <string>

Coin::Coin(Vector2 position) {
  for (int i = 1; i < 7; i++) {
    std::cout << i << std::endl;
    coinImage[i - 1] = LoadImage(TextFormat("../resources/Coins/c%d.png", i));

    if (coinImage[i - 1].data == nullptr) {
      std::cerr << "Error: coinImage[" << (i - 1) << "] is not initialized."
                << std::endl;
    } else {
      std::cout << "Working all fine: " << i << std::endl;
    }
    // Texture2D texture = LoadTexture("path/to/texture.png");
    std::cout << i << std::endl;
    ImageResize(&coinImage[i - 1], 15, 35);

    std::cout << i << std::endl;

    coinTextures[i - 1] = LoadTextureFromImage(coinImage[i - 1]);

    std::cout << i << std::endl;

    if (coinTextures[i - 1].id == 0) {
      std::cerr << "Failed to load texture: path/to/texture.png" << std::endl;
    } else {
      std::cout << "Texture loaded successfully!" << std::endl;
    }

    // UnloadImage(coinImage); // Unload image after converting to texture
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
    rect.height = coinImage[0].height;
    rect.width = coinImage[0].width;
    return rect;
  }
}