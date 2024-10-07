#include "Pet.hpp"

Pet::Pet() {
  this->level = 0;
}

void Pet::updateStatus() {
  // decreases status bars over time if respective needs are not met
  if ((GetTime() - this->lastFedTime >= this->hungerInterval) && !isDead) {
    if (this->currentHunger - (25*this->scaleFactor*this->level) < 0) {
      this->currentHunger = 0;
    } else {
      this->currentHunger -= (25*this->scaleFactor*this->level);
    }
    this->lastFedTime = GetTime();
  }

  if ((GetTime() - this->lastDrankTime >= this->thirstInterval && !isDead)) {
    if (this->currentThirst - (25*this->scaleFactor*this->level) < 0) {
      this->currentThirst = 0;
    } else {
      this->currentThirst -= (25*this->scaleFactor*this->level);
    }
    this->lastDrankTime = GetTime();
  }

  if ((GetTime() - this->lastPetTime >= this->happinessInterval && !isDead)) {
    if (this->currentHappiness - (25*this->scaleFactor*this->level) < 0) {
      this->currentHappiness = 0;
    } else {
      this->currentHappiness -= (25*this->scaleFactor*this->level);
    }
    this->lastPetTime = GetTime();
  }

  if ((GetTime() - this->lastLevelUpTime >= this-> levelUpInterval && !isDead)) {
    this->level += 1;
    this->lastLevelUpTime = GetTime();
  }
}

Pet::~Pet() {}