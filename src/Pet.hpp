#pragma once

#include <vector>
#include "Food.hpp"
#include "Poop.hpp"
#include "Water.hpp"
#include "healthBar.hpp"
#include <raylib.h>
#include <string>

class Pet {
    public:
        int level; // determines when the game will end once the pet reaches a certain level over time
        
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
        virtual ~Pet();

        
};

