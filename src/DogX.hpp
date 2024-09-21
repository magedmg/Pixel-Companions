#pragma once
#include "Poop.hpp"
#include <raylib.h>
#include <vector>

class DogX {

public:
  DogX();
  ~DogX();
  void Draw();
  void Update();

  void Poo1();

  Poop **poos;
  int currentPooCount;
  int currentHunger;
  int currentThirst;
  int currentHappiness;

  int hungerInterval;
  int thirstInterval;
  int happinessInterval;

  float lastFedTime;
  float lastDrankTime;
  float lastPetTime;

  std::vector<Poop> poos1;

  Rectangle getRect();

private:
  Texture2D image;
  Vector2 position;
  Texture2D standTextures[4];
  Texture2D runRightTextures[6];
  Texture2D runLeftTextures[6];
  Vector2 targetPosition;
  int currentFrame; // Index of the current frame
  float frameSpeed; // Speed at which frames change (seconds per frame)
  float frameTime;  // Time accumulator
  float moveSpeed;  // Speed at which the cat moves (pixels per second)
  bool isRunning;   // Indicates whether the cat is running
  bool movingRight; // Direction of movement (right by default)

  float lastPooTime;

  int randomPooInterval;
};