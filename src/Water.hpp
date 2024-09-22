#pragma once

#include "raylib.h"

class Water {
private:
  Texture2D waterbuttonTexture;
  Texture2D waterbuttonClickedTexture;
  Rectangle waterButtonRect;
  bool iswaterbuttonPressed;
  int* currCoins;

public:
  Water();
  ~Water();
  void update();
  void draw();
  void unloadTextures();

  void getCoins(int* currentCoins);
};