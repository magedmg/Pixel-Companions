#pragma once

#include "../health/healthBar.hpp"
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

  float lastFedTime;
  float lastDrankTime;
  float lastPetTime;

  int currentHunger;
  int currentThirst;
  int currentHappiness;

  int hungerInterval;
  int thirstInterval;
  int happinessInterval;

  Pet();
  void updateStatus();
  virtual void Draw() = 0;
  virtual ~Pet();
};
