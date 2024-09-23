#include "Petting.hpp"
#include <raylib.h>

#include <iostream>
using namespace std;

void createAnimation2(int numLoop, int sizes[2], Texture2D *textures,
                      const char *path) {
  for (int i = 0; i < numLoop; i++) {
    const char *filename = TextFormat("resources/%s%d.png", path, i + 1);
    Image targetImage = LoadImage(filename);
    ImageResize(&targetImage, sizes[0], sizes[1]);
    textures[i] = LoadTextureFromImage(targetImage);
    UnloadImage(targetImage);
    SetTextureFilter(textures[i], TEXTURE_FILTER_POINT);
  }
}

Petting::Petting(Vector2 position) {
  int imageSize[2] = {20, 20};
  createAnimation2(5, imageSize, heartTextures, "hearts/h");

  currentFrame = 0;
  frameTime = 0;
  frameSpeed = 0.25;

  this->position = position;
  active = true;

  time = GetTime();
}

Petting::Petting() {}

void Petting::Draw() {

  if (active) {
    float deltaTime = GetFrameTime();

    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0f;

      currentFrame = (currentFrame + 1) % 5;
    }
    position.y -= deltaTime * 30;

    cout << position.y << endl;

    cout << "bomboclatt" << endl;

    DrawTexture(heartTextures[currentFrame], (int)position.x + 20,
                (int)position.y, WHITE);

    // If it has been longer than 1 seconds since the hearts spawned, despawn
    // them
    float currentTime = GetTime();

    if (currentTime - time > 1) {
      active = false;
    }
  } else {
    for (int i = 0; i < 5; i++) {
      UnloadTexture(heartTextures[i]);
    }
  }
}

bool Petting::Status() { return active; }
