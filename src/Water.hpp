#pragma once

#include "raylib.h"

class Water {
private:
  Texture2D waterbuttonTexture;
  Texture2D waterbuttonClickedTexture;
  Rectangle waterButtonRect;
  bool iswaterbuttonPressed;

public:
  Water();
  ~Water();
  void update();
  void draw();
  void unloadTextures();
};