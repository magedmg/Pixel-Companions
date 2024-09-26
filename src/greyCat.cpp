#include "greyCat.hpp"


greyCat::greyCat() {
      int catSize[2] = {85, 95};

  // Load all the images for left and right movements, as well as standing
  // still
  createAnimation(4, catSize, standTextures, "cat/1");
  createAnimation(6, catSize, runRightTextures, "cat/2");
  createAnimation(6, catSize, runLeftTextures, "cat/3");

  // Load death image and resize it
  deathImage = LoadImage("resources/cat/114.png");
  ImageResize(&deathImage, catSize[0], catSize[1]);
  deathTexture = LoadTextureFromImage(deathImage);

  moveSpeed = 100.0f; // Speed at which the cat moves (pixels per second)

  hungerInterval = 20;
  thirstInterval = 3;
  happinessInterval = 25;

  randomPooInterval = GetRandomValue(5, 10);
}

void greyCat::Draw() {
  float deltaTime = GetFrameTime();

  frameTime += deltaTime;
  if (!isDead && frameTime >= frameSpeed) {
    frameTime = 0.0f;
    if (isRunning) {
      curFrame = (curFrame + 1) % 5;
    } else {
      curFrame = (curFrame + 1) % 4;
    }
  }

  if (isDead) {
      DrawTexture(deathTexture, (int)position.x, (int)position.y, WHITE);
  } 
  else if (isRunning) {
      if (movingRight) {
          DrawTexture(runRightTextures[curFrame], (int)position.x, (int)position.y, WHITE);
      } else {
          DrawTexture(runLeftTextures[curFrame], (int)position.x, (int)position.y, WHITE);
      }
  } 
  else {
      DrawTexture(standTextures[curFrame], (int)position.x, (int)position.y, WHITE);
  }

}

greyCat::~greyCat() {
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
}