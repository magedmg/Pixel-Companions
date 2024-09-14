#pragma once

#include <string>
#include <ctime>

class Pet {
    protected:
        int level; // determines when the game will end once the pet reaches a certain level over time
        int hungerLevel;
        int thirstLevel;
        int happinessLevel;
        int poopCount;

        std::string name;
        std::string pet_type;

        time_t lastFed;
        time_t lastDrunk;
        time_t lastPetted;

    public:
        Pet();

        void set_name(std::string name);
        std::string get_name();

        void set_level(int level);
        int get_level();

        void set_hungerLevel(int hunger);
        int get_hungerLevel();

        void set_thirstLevel(int thirst);
        int get_thirstLevel();

        void set_happinessLevel(int happiness);
        int get_happinessLevel();

        void set_poopCount(int poopCount);
        int get_poopCount();
};

