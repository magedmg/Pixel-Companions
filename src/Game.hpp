#pragma once

#include <vector>

#include "Coin.hpp"
#include "DogX.hpp"
#include "Food.hpp"
#include "Pet.hpp"
#include "Petting.hpp"
#include "Poop.hpp"
#include "Water.hpp"
#include "healthBar.hpp"
#include <raylib.h>
class Game {
private:
  int windowWidth = 1000;
  int windowHeight = 700;
  Image bgImage;

  Texture2D bgImageTexture;

  DogX dog;

  Image healthBarImage;
  Texture2D healthBarTexture;

  Image coinBarImage;
  Texture2D coinBarTexture;

  Image hungerImage;
  Texture2D hungerTexture;

  Image waterImage;
  Texture2D waterTexture;

  Image happinessImage;
  Texture2D happinessTexture;

  int catSize[2], fishSize[2], buttonSize[2];
  Texture2D fishTexture, foodbuttonTexture, foodbuttonClickedTexture;
  Texture2D waterbuttonTexture, waterbuttonClickedTexture;
  Texture2D standTextures[4], runRightTextures[6], runLeftTextures[6];

  Vector2 catPosition, targetPosition, foodPosition;
  int curFrame;
  float frameSpeed, frameTime, moveSpeed;
  bool isRunning, movingRight, foodFalling;
  float foodSpeed;
  Rectangle foodButtonRect, waterButtonRect;
  bool isfoodbuttonPressed, iswaterbuttonPressed;

  std::vector<Coin> coins;
  int randomCoinInterval;

  int lastCoinTime;
  int coinCounter;
  int scoreValue;
  int scoreTimer;

  Food food;
  Water water;
  healthBar health;

  int lastTimeDamaged;
  int lastTimeHealed;

  std::vector<Petting> pettings;

public:
  Game();

  void updateAll();

  int flag;
  void loadCoins();

  void checkCollisions();

  void DrawUI();

  Petting p;
};
