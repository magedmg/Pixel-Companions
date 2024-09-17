#pragma once
#include "Pet.hpp"
#include "Poop.hpp"
class Cat : public Pet {
    protected:
        int movementSpeedCat; //maybe breed can affect movement speed?
        std::vector<Poop> poops;

    public:
        Cat();

        int calc_catHunger(time_t lastFed);
        int calc_catThirst(time_t lastDrunk);
        int calc_catHappiness(time_t lastPetted);

        std::vector<Poop> get_poops();


};
