#pragma once

#include "raylib.h"

class Water {
private:
  Texture2D waterbuttonTexture;
  Texture2D waterbuttonClickedTexture;
  Texture2D emptyWaterBowlTexture;
  Texture2D fullWaterBowlTexture;

  Rectangle waterBowlRect;
  bool iswaterbuttonPressed;
  bool isBowlFull;
  int *currCoins;

public:
  Water();
  ~Water();
  void update();
  void draw();
  void unloadTextures();
  void drink();
  Rectangle getRect();

  Rectangle waterButtonRect;

  void getCoins(int *currentCoins);
};