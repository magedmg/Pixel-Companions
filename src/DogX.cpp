#include "DogX.hpp"

#include <raylib.h>

#include <iostream>
using namespace std;

void createAnimation(int, int[2], Texture2D*, const char*);

DogX::DogX() {
  // Initial position
  position = {250, 480};

  // Load all the images for left and right movements, as well as standing still
  createAnimation(4, catSize, standTextures, "cat/1");
  createAnimation(6, catSize, runRightTextures, "cat/2");
  createAnimation(6, catSize, runLeftTextures, "cat/3");

  // DEFINE VARIABLES TO USE IN LOOP
  Vector2 catPosition = {250, 480};
  Vector2 targetPosition = catPosition;
  int curFrame = 0;
  float frameSpeed = 0.1f;
  float frameTime = 0.0f;
  float moveSpeed = 100.0f;
  bool isRunning = false;
  bool movingRight = true;

  // setting last poop time
  lastPooTime = GetTime();

  currentPooCount = 0;
  poos = new Poop*[5];
  for (int i = 0; i < 5; i++) {
    poos[i] = new Poop({0, 0});
  }

  randomPooInterval = GetRandomValue(5, 10);
}

void DogX::Draw() {
  float deltaTime = GetFrameTime();

  frameTime += deltaTime;
  if (frameTime >= frameSpeed) {
    frameTime = 0.0f;
    if (isRunning) {
      curFrame = (curFrame + 1) % 6;
    } else {
      curFrame = (curFrame + 1) % 4;
    }
  }

  if (isRunning) {
    if (movingRight) {
      DrawTexture(runRightTextures[curFrame], (int)catPosition.x,
                  (int)catPosition.y, WHITE);
    } else {
      DrawTexture(runLeftTextures[curFrame], (int)catPosition.x,
                  (int)catPosition.y, WHITE);
    }
  } else {
    DrawTexture(standTextures[curFrame], (int)catPosition.x, (int)catPosition.y,
                WHITE);
  }
}

void DogX::Update() {
  float deltaTime = GetFrameTime();

  frameTime += deltaTime;
  if (frameTime >= frameSpeed) {
    frameTime = 0.0f;
    if (isRunning) {
      curFrame = (curFrame + 1) % 6;
    } else {
      curFrame = (curFrame + 1) % 4;
    }
  }

  // CAT RUNNING PART
  if (isRunning) {
    if (movingRight) {
      catPosition.x += moveSpeed * deltaTime;
      if (catPosition.x >= targetPosition.x) {
        catPosition.x = targetPosition.x;
        isRunning = false;
        curFrame = 0;
      }
    } else {
      catPosition.x -= moveSpeed * deltaTime;
      if (catPosition.x <= targetPosition.x) {
        catPosition.x = targetPosition.x;
        isRunning = false;
        curFrame = 0;
      }
    }
  }
}

DogX::~DogX() {
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
}

void DogX::Poo1() {
  if (GetTime() - lastPooTime >= randomPooInterval && currentPooCount < 5) {
    poos[currentPooCount]->position = {position.x - image.width - 30,
                                       position.y + 40};
    poos[currentPooCount]->Spawn();
    lastPooTime = GetTime();
    currentPooCount++;
    randomPooInterval = GetRandomValue(5, 10);
  }
}

Rectangle DogX::getRect() {
  Rectangle rect;
  rect.x = position.x;
  rect.y = position.y;
  rect.height = 95;
  rect.width = 85;
  return rect;
}

void createAnimation(int numLoop, int sizes[2], Texture2D* textures,
                     const char* path) {
  for (int i = 0; i < numLoop; i++) {
    const char* filename = TextFormat("resources/%s%d.png", path, i + 1);
    Image targetImage = LoadImage(filename);
    ImageResize(&targetImage, sizes[0], sizes[1]);
    textures[i] = LoadTextureFromImage(targetImage);
    UnloadImage(targetImage);
  }
}
