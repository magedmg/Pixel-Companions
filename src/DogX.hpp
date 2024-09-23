#pragma once
#include <raylib.h>

#include <vector>

#include "Poop.hpp"

class DogX {
private:
  Texture2D image;

  Texture2D standTextures[4];
  Texture2D runRightTextures[6];
  Texture2D runLeftTextures[6];

  int curFrame;
  float frameSpeed;
  float frameTime;
  float moveSpeed;

  float lastPooTime;

  int randomPooInterval;

public:
  DogX();
  ~DogX();
  void Draw();
  void Update();
  void Poo1();

  int currentHunger;
  int currentThirst;
  int currentHappiness;

  int hungerInterval;
  int thirstInterval;
  int happinessInterval;

  float lastFedTime;
  float lastDrankTime;
  float lastPetTime;


  Poop **poos;
  int currentPooCount;

  std::vector<Poop> poos1;

  Rectangle getRect();

  // Create getters and setters for these in the futore
  Vector2 position;
  Vector2 targetPosition;
  bool isRunning;
  bool movingRight;
};