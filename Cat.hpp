#pragma once
#include "Pet.hpp"

class Cat : public Pet {
    protected:
        int movementSpeedCat; //maybe breed can affect movement speed?

    public:
        Cat();

        int calc_catHunger(time_t lastFed);
        int calc_catThirst(time_t lastDrunk);
        int calc_catHappiness(time_t lastPetted);


};
