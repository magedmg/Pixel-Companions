#pragma once


#include "../companion/Dog.hpp"

#include <string>
#include <vector>
#include <iostream>

class DogUnitTest {

    public:
        void runTests() {
            testDogConstructor();
            testDogGetRect();
        }

    private:
        void testDogConstructor() {
            Dog dog;
            // tests if data members are initialised correctly in constructor
            if (dog.levelUpInterval != 12 || dog.position.x != 250 || dog.position.y != 480 ||
            dog.isRunning != false || dog.isDead != false) {
                std::cout << "Dog Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "Dog Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

        void testDogGetRect() {
            Dog dog;
            // tests if correct rectangle is returned
            if (dog.getRect().height != 95 || dog.getRect().width != 85 ||
            dog.getRect().x != 250 || dog.getRect().y != 480) {
                std::cout << "Dog Test 2 failed (getRect)" << std::endl;
            }
            else {
                std::cout << "Dog Test 2 succeeded (getRect)" << std::endl;
            }
        }
};

