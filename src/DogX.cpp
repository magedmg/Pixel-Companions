#include "DogX.hpp"

#include <raylib.h>

#include <iostream>
using namespace std;

void createAnimation(int, int[2], Texture2D *, const char *);

DogX::DogX() {
  // Initial position
  position = {250, 480};

  int catSize[2] = {85, 95};

  // Load all the images for left and right movements, as well as standing
  // still
  createAnimation(4, catSize, standTextures, "cat/1");
  createAnimation(6, catSize, runRightTextures, "cat/2");
  createAnimation(6, catSize, runLeftTextures, "cat/3");
  createAnimation(4, catSize, dieTextures, "cat/11");

  // DEFINE VARIABLES TO USE IN LOOP
  targetPosition = position;
  isRunning = false; // Indicates whether the cat is running
  movingRight = true;
  targetPosition = position;
  curFrame = 0;       // Index of the current frame
  frameSpeed = 0.2f;  // Speed at which frames change (seconds per frame)
  frameTime = 0.0f;   // Time accumulator
  moveSpeed = 100.0f; // Speed at which the cat moves (pixels per second)

  // setting last poop time
  lastPooTime = GetTime();
  lastFedTime = GetTime();
  lastDrankTime = GetTime();
  lastPetTime = GetTime();

  currentHunger = 100;
  currentThirst = 100;
  currentHappiness = 100;

  hungerInterval = 20;
  thirstInterval = 15;
  happinessInterval = 25;

  currentPooCount = 0;
  poos = new Poop *[5];
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
      curFrame = (curFrame + 1) % 5;
    } else {
      curFrame = (curFrame + 1) % 4;
    }
  }

  if (isRunning) {
    if (movingRight) {
      DrawTexture(runRightTextures[curFrame], (int)position.x, (int)position.y,
                  WHITE);
    } else {
      DrawTexture(runLeftTextures[curFrame], (int)position.x, (int)position.y,
                  WHITE);
    }
  } else {
    DrawTexture(standTextures[curFrame], (int)position.x, (int)position.y,
                WHITE);
  }

  if (isDying) {
    DrawTexture(dieTextures[curFrame], (int)position.x, (int)position.y,
                WHITE);
  }
}

void DogX::Update() {
  float deltaTime = GetFrameTime();
  // Make sure the cat cant go off the screen
  if (position.x > (1000 - 85)) {
    position.x = 915;
    isRunning = false;
  } else if (position.x < 20) {
    position.x = 20;
    isRunning = false;
  }

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
      position.x += moveSpeed * deltaTime;
      if (position.x >= targetPosition.x) {
        position.x = targetPosition.x;
        isRunning = false;
        // curFrame = 0;
      }
    } else {
      position.x -= moveSpeed * deltaTime;
      if (position.x <= targetPosition.x) {
        position.x = targetPosition.x;
        isRunning = false;
        // curFrame = 0;
      }
    }
  }

  // CAT DYING PART
  if (isDying) {
    
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    targetPosition = GetMousePosition();
    isRunning = true;
    // Determine direction based on mouse position
    if (targetPosition.x > position.x) {
      movingRight = true;
    } else if (targetPosition.x < position.x) {
      movingRight = false;
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

void createAnimation(int numLoop, int sizes[2], Texture2D *textures,
                     const char *path) {
  for (int i = 0; i < numLoop; i++) {
    const char *filename = TextFormat("resources/%s%d.png", path, i + 1);
    Image targetImage = LoadImage(filename);
    ImageResize(&targetImage, sizes[0], sizes[1]);
    textures[i] = LoadTextureFromImage(targetImage);
    UnloadImage(targetImage);
    SetTextureFilter(textures[i],
                     TEXTURE_FILTER_POINT); // makes the pixel art look clearer
  }
}
