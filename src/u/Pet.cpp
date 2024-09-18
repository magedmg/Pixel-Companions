#include "Pet.hpp"

Pet::Pet() {}

void Pet::set_name(std::string name) {
    this->name = name;
}

std::string Pet::get_name() {
    return this->name;
}

void Pet::set_level(int level) {
    this->level = level;
}

int Pet::get_level() {
    return this->level;
}

void Pet::set_hungerLevel(int hunger) {
    this->hungerLevel = hunger;
}

int Pet::get_hungerLevel() {
    return this->hungerLevel;
}

void Pet::set_thirstLevel(int thirst) {
    this->thirstLevel = thirst;
}

int Pet::get_thirstLevel() {
    return this->thirstLevel;
}

void Pet::set_happinessLevel(int happiness) {
    this->happinessLevel = happiness;
}

int Pet::get_happinessLevel() {
    return this->happinessLevel;
}
