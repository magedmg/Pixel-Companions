#pragma once

#include <string>
#include <vector>

#include "../companion/Cat.hpp"
#include "../companion/Pet.hpp"
#include "../companion/greyCat.hpp"
#include "../health/healthBar.hpp"
#include "../pet-essentials/Coin.hpp"
#include "../pet-essentials/Food.hpp"
#include "../pet-essentials/Petting.hpp"
#include "../pet-essentials/Poop.hpp"
#include "../pet-essentials/Water.hpp"
#include <raylib.h>
#include "../companion/pinkCat.hpp"
#include "../companion/shibaInu.hpp"
#include "../companion/Dog.hpp"

class Game {
private:
  int windowWidth = 1000;
  int windowHeight = 700;
  Image bgImage;

  Texture2D bgImageTexture;
  std::string petType;

   Dog dog;
   Cat cat;
   greyCat greyCat;
   pinkCat pinkCat;
   shibaInu shibaInu;

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

  Petting pet;
  bool petAlive;

  float lastTimePetted;

public:
  Game();

  void updateAll();

  int flag;
  void loadCoins();
  void replayGame();

  void checkCollisions();

  void DrawUI();
};
