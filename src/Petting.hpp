#pragma once
#include <raylib.h>

class Petting {
private:
  Texture2D heartTextures[5];
  Image loveImage;
  int currentFrame;
  float frameTime;
  float frameSpeed;

  Vector2 position;

  bool active;

  float time;

public:
  Petting(Vector2 position);
  void Draw();
};