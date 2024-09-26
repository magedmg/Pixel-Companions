#include "shibaInu.hpp"

void createAnimation5(int numLoop, int sizes[2], Texture2D *textures,
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

shibaInu::shibaInu() {
  int dogSize[2] = {90, 100};

  // Load all the images for left and right movements, as well as standing
  // still
  createAnimation5(4, dogSize, standTextures, "dog/2");
  createAnimation5(6, dogSize, runRightTextures, "dog/1");
  createAnimation5(6, dogSize, runLeftTextures, "dog/3");

  // Load death image and resize it
  deathImage = LoadImage("resources/dog/114.png");
  ImageResize(&deathImage, dogSize[0], dogSize[1]);
  deathTexture = LoadTextureFromImage(deathImage);

  moveSpeed = 100.0f; // Speed at which the dog moves (pixels per second)

  hungerInterval = 15;
  thirstInterval = 3;
  happinessInterval = 20;

  randomPooInterval = GetRandomValue(3, 8);
}

void shibaInu::Draw() {
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

shibaInu::~shibaInu() {
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
}