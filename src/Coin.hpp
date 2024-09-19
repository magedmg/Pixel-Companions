#pragma once

#include <raylib.h>
#include <string>

class Coin {
private:
  Texture2D coinTextures[6];
  bool active;
  float frameTime;
  int currentFrame;
  float frameSpeed;
  int moveSpeed;
  Image coinImage;

public:
  bool collision;
  Coin(Vector2 position);
  //~Coin();
  Vector2 position;
  void Draw();
  void Update();
  Rectangle getRect();
  int collisionTime;
  bool collected;
};