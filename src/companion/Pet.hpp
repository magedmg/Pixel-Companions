#pragma once

#include "../health/HealthBar.hpp"
#include "../pet-essentials/Food.hpp"
#include "../pet-essentials/Poop.hpp"
#include "../pet-essentials/Water.hpp"
#include <raylib.h>
#include <string>
#include <vector>

class Pet {
public:
  int level; // determines when the game will end once the pet reaches a certain
             // level over time

  std::string petType;

  float lastFedTime;
  float lastDrankTime;
  float lastPetTime;

  float lastLevelUpTime;

  int currentHunger;
  int currentThirst;
  int currentHappiness;

  int hungerInterval;
  int thirstInterval;
  int happinessInterval;

  int levelUpInterval;

  float scalingFactor;

  Poop **poos;
  int currentPooCount;

  std::vector<Poop> poos1;

  Vector2 position;
  Vector2 targetPosition;

  bool isRunning;
  bool movingRight;
  bool isDead;



  Pet();
  void updateStatus();
  virtual void Draw() = 0;
  virtual void Poo1() = 0;
  virtual ~Pet();
  virtual Rectangle getRect() = 0;
  virtual void Update() = 0;
};
