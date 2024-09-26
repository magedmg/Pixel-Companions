#include "Food.hpp"

#include <filesystem>

#include "raylib.h"
#include <iostream>

void createImage(float sizes[2], Texture2D &ImgTexture, const char *path);

Food::Food() {
  float buttonSize[2] = {95, 95};
  float fishSize[2] = {55, 65};

  createImage(buttonSize, foodbuttonTexture, "buttons/foodbutton");
  createImage(buttonSize, foodbuttonClickedTexture,
              "buttons/foodbuttonclicked");
  createImage(fishSize, fishTexture, "food/fish");

  foodButtonRect = {870, 16, buttonSize[0], buttonSize[1]};
  foodPosition = {0, -100};
  foodFalling = false;
  foodSpeed = 200.0f;
  isfoodbuttonPressed = false;
}

Food::~Food() { unloadTextures(); }

void Food::update(Vector2 &catPosition, Vector2 &targetPosition,
                  bool &isRunning, bool &movingRight) {
  float deltaTime = GetFrameTime();
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !foodFalling) {
    Vector2 mousePosition = GetMousePosition();

    if (CheckCollisionPointRec(mousePosition, foodButtonRect)) {
      if (*currCoins >= 2) {
        isfoodbuttonPressed = true;

        foodPosition.x = catPosition.x + (float)GetRandomValue(-300, 300);
        while (foodPosition.x < 0 || foodPosition.x > 950) {
          foodPosition.x = catPosition.x + (float)GetRandomValue(-300, 300);
        }
        foodPosition.y = 0;
        foodFalling = true;
        *currCoins -= 2;
      }
    } else {
      isfoodbuttonPressed = false;
    }
  }

  if (foodFalling) {
    float fishSize[2] = {55, 65};
    foodPosition.y += foodSpeed * deltaTime;
    foodRect = {foodPosition.x, foodPosition.y, fishSize[0], fishSize[1]};
    if (foodPosition.y >= 480) {
      foodFalling = false;
    }
  }
}

void Food::draw() {
  if (foodFalling) {
    DrawTexture(fishTexture, (int)foodPosition.x, (int)foodPosition.y, WHITE);
  }

  if (isfoodbuttonPressed) {
    DrawTexture(foodbuttonClickedTexture, 870, 16, WHITE);
  } else {
    DrawTexture(foodbuttonTexture, 870, 16, WHITE);
  }
}

void Food::unloadTextures() {
  UnloadTexture(fishTexture);
  UnloadTexture(foodbuttonTexture);
  UnloadTexture(foodbuttonClickedTexture);
}

void createImage(float sizes[2], Texture2D &ImgTexture, const char *path) {
  const char *filename = TextFormat("resources/%s.png", path);
  Image targetImage = LoadImage(filename);
  ImageResize(&targetImage, sizes[0], sizes[1]);
  ImgTexture = LoadTextureFromImage(targetImage);
  UnloadImage(targetImage);
}

void Food::getCoins(int *currentCoins) { this->currCoins = currentCoins; }

Rectangle Food::getRect() { return foodRect; }

void Food::eat() {
  foodRect = {0, 0, 0, 0};
  foodFalling = false;
}