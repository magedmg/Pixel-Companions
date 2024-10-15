#include "Petting.hpp"
#include <raylib.h>

#include <iostream>
using namespace std;

void createAnimation2(int numLoop, int sizes[2], Texture2D *textures,
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

Petting::Petting() {
  int imageSize[2] = {55, 65};
  createAnimation2(5, imageSize, heartTextures, "hearts/h");

  currentFrame = 0;
  frameTime = 0;
  frameSpeed = 0.3;

  this->position = {0, 0};
  active = false;

  time = GetTime();
}

void Petting::Draw() {

  if (active) {
    // calculates next frame
    float deltaTime = GetFrameTime();

    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0f;

      currentFrame = (currentFrame + 1) % 5;
    }
    position.y -= deltaTime * 30; // calculates y position of floating heart

    DrawTexture(heartTextures[currentFrame], (int)position.x + 20,
                (int)position.y - 55, WHITE);

    // If it has been longer than 1 seconds since the hearts spawned, despawn
    // them
    float currentTime = GetTime();

    if (currentTime - time > 1.1) {
      active = false;
    }
  }
  // do nothing if the petting is not active
}

bool Petting::Status() { return active; }

Petting::~Petting() {
  for (int i = 0; i < 5; i++) {
    UnloadTexture(heartTextures[i]);
  }
}

void Petting::Update(Vector2 position) {
  this->position = position;
  active = true;
  time = GetTime(); // reset the time
  currentFrame = 0; // resets the current frame
}