#pragma once

#include "DogX.hpp"
#include "Poop.hpp"
#include "raylib.h"
class Game {
private:
  int windowWidth = 1000;
  int windowHeight = 700;
  Image bgImage;

  Texture2D bgImageTexture;

  DogX dog;

  Image healthBarImage;
  Texture2D healthBarTexture;

public:
  Game();

  void updateAll();

  int flag;
};
