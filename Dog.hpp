#pragma once
#include "Pet.hpp"
class Dog : public Pet {
    protected:
        int movementSpeedDog; //maybe breed can affect movement speed?

    public:
        Dog();
        int calc_dogHunger(time_t lastFed);
        int calc_dogThirst(time_t lastDrunk);
        int calc_dogHappiness(time_t lastPetted);


};
