#pragma once

#include "../companion/Cat.hpp"
#include "../companion/Dog.hpp"
#include "../companion/GreyCat.hpp"
#include "../companion/Pet.hpp"
#include "../companion/PinkCat.hpp"
#include "../companion/ShibaInu.hpp"
#include "../health/HealthBar.hpp"
#include "../pet-essentials/Coin.hpp"
#include "../pet-essentials/Food.hpp"
#include "../pet-essentials/Petting.hpp"
#include "../pet-essentials/Poop.hpp"
#include "../pet-essentials/Water.hpp"
#include "Highscore.hpp"

#include <raylib.h>

#include <string>
#include <vector>

class Game {
private:
  int windowWidth = 1000;
  int windowHeight = 700;

  Image bgImage;
  Texture2D bgImageTexture;

  Image openingImage;
  Texture2D openingImageTexture;

  std::string petBreed;
  std::string levelText;

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

  Image deathbgImage;
  Texture2D deathbgTexture;

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

  int UITimer;
  int endingTimer;
  int endCounter;
  int timeTracker;

  Food food;
  Water water;
  HealthBar health;

  Highscore highscore;

  int lastTimeDamaged;
  int lastTimeHealed;

  Petting pet;
  bool petAlive;

  float lastTimePetted;

  Pet *currentPet;

  // Images and Texures for the UI

  Image startButton;
  Texture2D startTexture;

  Image UIpets;
  Texture2D UIpetsTexture;

  Image instructions;
  Texture2D instructionsTexture;
  Image instructionsButton;
  Texture2D instructionsButtonTexture;

  Rectangle instructionsRect;

  int UIstate;
  int playingState;

  Rectangle petRects[3];
  std::string petOptions[3];

  // location of the yellow rectangle appearing around the pet
  int boxLocation;

public:
  Game();

  void updateAll();

  int flag;
  void loadCoins();

  void checkCollisions();

  void DrawUI();

  void createPet(std::string petBreed);

  void activeGame();
  void startUI();
  void deathScreen();
  void playingGame();

  void pickPet();
  void instructionsUI();

  void Reset();

  // Game state for switching to the UI
  int gameState;

  ~Game();
};
