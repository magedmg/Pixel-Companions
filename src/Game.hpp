#pragma once

#include "Coin.hpp"
#include "DogX.hpp"
#include "Poop.hpp"
#include "raylib.h"
#include <vector>
class Game {
private:
  int windowWidth = 1000;
  int windowHeight = 700;
  Image bgImage;

  Texture2D bgImageTexture;

  DogX dog;

  Image healthBarImage;
  Texture2D healthBarTexture;

  Image hungerBarImage;
  Texture2D hungerBarTexture;

  Image coinBarImage;
  Texture2D coinBarTexture;

  std::vector<Coin> coins;
  int randomCoinInterval;

  int lastCoinTime;

  int coinCounter;

  int scoreValue;

  int scoreTimer;

public:
  Game();

  void updateAll();

  int flag;
  void loadCoins();

  void checkCollisions();
};
