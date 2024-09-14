#include "Cat.hpp"

Cat::Cat() {
    this->pet_type = "dog";
    this->movementSpeedCat = 10;
}

int Cat::calc_catHunger(time_t lastFed) { // if 10 or more seconds pass after last being fed, reduce hunger by 20
    if (time(0) - lastFed >= 15) {
        int newHunger = this->get_hungerLevel() - 5;
        this->lastFed = time(0); // reset timer
        return newHunger;
    }
    else {
        return this->get_hungerLevel(); // hunger level is the same
    }
}


int Cat::calc_catThirst(time_t lastDrunk) { // if 5 or more seconds pass after last drinking water, reduce thirst by 30
    if (time(0) - lastDrunk >= 10) {
        int newThirst = this->get_thirstLevel() - 15;
        this->lastDrunk = time(0); // reset timer
        return newThirst;
    }
    else {
        return this->get_thirstLevel(); // thirst level is the same
    }
}


int Cat::calc_catHappiness(time_t lastPetted) { // if 20 or more seconds pass after last being pet, reduce happiness by 10
    if (time(0) - lastPetted >= 25) {
        int newHappiness = this->get_happinessLevel() - 10;
        this->set_happinessLevel(newHappiness);
        this->lastPetted = time(0); // reset timer
        return newHappiness;
    }
    else {
        return this->get_happinessLevel(); // happiness level is the same
    }
}
        
