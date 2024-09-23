#pragma once

#include "raylib.h"

class Food {
private:
  Texture2D foodbuttonTexture;
  Texture2D foodbuttonClickedTexture;
  Texture2D fishTexture;

  Rectangle foodRect;

  Vector2 foodPosition;
  bool foodFalling;
  float foodSpeed;
  bool isfoodbuttonPressed;
  int* currCoins;

public:
  Food();
  ~Food();
  void update(Vector2 &catPosition, Vector2 &targetPosition, bool &isRunning,
              bool &movingRight);
  void draw();
  void unloadTextures();
  Rectangle foodButtonRect;
  Rectangle getRect();
  void eat();

  void getCoins(int* currentCoins);
};