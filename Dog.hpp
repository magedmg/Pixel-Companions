#pragma once
#include "Pet.hpp"
#include "Poop.hpp"
class Dog : public Pet {
    protected:
        int movementSpeedDog; //maybe breed can affect movement speed?
        std::vector<Poop> poops;

    public:
        Dog();
        int calc_dogHunger(time_t lastFed);
        int calc_dogThirst(time_t lastDrunk);
        int calc_dogHappiness(time_t lastPetted);

        std::vector<Poop> get_poops();


};
