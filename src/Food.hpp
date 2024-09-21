#pragma once

#include "raylib.h"

class Food {
 private:
  Texture2D foodbuttonTexture;
  Texture2D foodbuttonClickedTexture;
  Texture2D fishTexture;
  Rectangle foodButtonRect;
  Vector2 foodPosition;
  bool foodFalling;
  float foodSpeed;
  bool isfoodbuttonPressed;

 public:
  Food();
  ~Food();
  void update(float deltaTime, Vector2& catPosition, Vector2& targetPosition,
              bool& isRunning, bool& movingRight);
  void draw();
  void unloadTextures();
};