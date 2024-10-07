#include "Pet.hpp"

Pet::Pet() {
  this->petWin = false;
  this->level = 0;
}

void Pet::updateStatus() {
  // decreases status bars over time if respective needs are not met
  if (GetTime() - this->lastFedTime >= this->hungerInterval) {
    if (this->currentHunger - 25 < 0) {
      this->currentHunger = 0;
    } else {
      this->currentHunger -= 25;
    }
    this->lastFedTime = GetTime();
  }

  if (GetTime() - this->lastDrankTime >= this->thirstInterval) {
    if (this->currentThirst - 25 < 0) {
      this->currentThirst = 0;
    } else {
      this->currentThirst -= 25;
    }
    this->lastDrankTime = GetTime();
  }

  if (GetTime() - this->lastPetTime >= this->happinessInterval) {
    if (this->currentHappiness - 25 < 0) {
      this->currentHappiness = 0;
    } else {
      this->currentHappiness -= 25;
    }
    this->lastPetTime = GetTime();
  }

  if (GetTime() - this->lastLevelUpTime >= this-> levelUpInterval) {
    if (this->level + 1 == 10) {
      petWin = true;
    } else {
      this->level += 1;
    }
    this->lastLevelUpTime = GetTime();
  }
}

Pet::~Pet() {}