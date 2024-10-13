#pragma once


#include "../companion/Dog.hpp"

#include <string>
#include <vector>
#include <iostream>

class DogUnitTest {

    public:
        void runTests() {
            testDogConstructor();
            testDogUpdate();
            testDogGetRect();
        }

    private:
        void testDogConstructor() {
            Dog dog;
            // tests if data members are initialised correctly in constructor
            if (dog.levelUpInterval != 10 || dog.position.x != 250 || dog.position.y != 480 ||
            dog.isRunning != false || dog.isDead != false) {
                std::cout << "Dog Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "Dog Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

        void testDogUpdate() {
            Dog dog;
            SetMousePosition(300, 480);
            dog.Update();
            // tests if dog starts running
            if (dog.isRunning != true) {
                std::cout << "Dog Test 2 failed (dog update, running check)" << std::endl;
            }
            else {
                std::cout << "Dog Test 2 succeeded (dog update, running check)" << std::endl;
            }

            dog.Update();
            // tests if dog position is different to initial position
            if (dog.getRect().x == 250 || dog.getRect().y == 480) {
                std::cout << "Dog Test 3 failed (dog update, position check)" << std::endl;
            }
            else {
                std::cout << "Dog Test 3 succeeded (dog update, position check)" << std::endl;
            }
        }

        void testDogGetRect() {
            Dog dog;
            // tests if correct rectangle is returned
            if (dog.getRect().height != 95 || dog.getRect().width != 85 ||
            dog.getRect().x != 250 || dog.getRect().y != 480) {
                std::cout << "Dog Test 4 failed (getRect)" << std::endl;
            }
            else {
                std::cout << "Dog Test 4 succeeded (getRect)" << std::endl;
            }
        }
};

