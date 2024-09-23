#pragma once

#include "raylib.h"

class Water {
private:
  Texture2D waterbuttonTexture;
  Texture2D waterbuttonClickedTexture;
  Texture2D emptyWaterBowlTexture;
  Texture2D fullWaterBowlTexture;

  Rectangle waterButtonRect;
  Rectangle waterBowlRect;
  bool iswaterbuttonPressed;
  bool isBowlFull;
  int* currCoins;

public:
  Water();
  ~Water();
  void update();
  void draw();
  void unloadTextures();
  void drink();
  Rectangle getRect();

  void getCoins(int* currentCoins);
};