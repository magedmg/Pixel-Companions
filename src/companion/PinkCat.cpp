#include "PinkCat.hpp"

void createAnimation6(int numLoop, int sizes[2], Texture2D *textures,
                      const char *path) {
  for (int i = 0; i < numLoop; i++) {
    const char *filename = TextFormat("../resources/%s%d.png", path, i + 1);
    Image targetImage = LoadImage(filename);
    ImageResize(&targetImage, sizes[0], sizes[1]);
    textures[i] = LoadTextureFromImage(targetImage);
    UnloadImage(targetImage);
    SetTextureFilter(textures[i],
                     TEXTURE_FILTER_POINT); // makes the pixel art look clearer
  }
}

PinkCat::PinkCat() : Cat() {
  scalingFactor = 0.4;
  int catSize[2] = {85, 95};

  // Load all the images for left and right movements, as well as standing
  // still
  createAnimation6(4, catSize, standTextures, "cat/4");
  createAnimation6(6, catSize, runRightTextures, "cat/5");
  createAnimation6(6, catSize, runLeftTextures, "cat/6");

  // Load death image and resize it
  deathImage = LoadImage("../resources/cat/214.png");
  ImageResize(&deathImage, catSize[0], catSize[1]);
  deathTexture = LoadTextureFromImage(deathImage);

  moveSpeed = 100.0f; // Speed at which the cat moves (pixels per second)

  hungerInterval = 18;
  thirstInterval = 11;
  happinessInterval = 23;

  randomPooInterval = GetRandomValue(5, 10);
}

void PinkCat::Draw() { // calculates next frame
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

  if (isDead) { // draws textures
    DrawTexture(deathTexture, (int)position.x, (int)position.y, WHITE);
  } else if (isRunning) {
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
}

PinkCat::~PinkCat() {
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
}
