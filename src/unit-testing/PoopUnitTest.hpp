#pragma once

#include "../pet-essentials/Poop.hpp"

#include <string>
#include <vector>
#include <iostream>

class PoopUnitTest {
    public:
        void runTests() {
            testPoopConstructor();
            testPoopSpawn();
            testPoopGetRect();
            testPoopDeactivate();
        }

    private:
        void testPoopConstructor() {
            Poop poo({10,20});

            // testing if data members are initialised correctly when constructed
            if (poo.position.x != 10 || poo.position.y != 20) {
                std::cout << "Poop Test 1 failed (constructor initialisation)" << std::endl;
            }
            else {
                std::cout << "Poop Test 1 succeeded (constructor initialisation)" << std::endl;
            }
        }

        void testPoopSpawn() {
            Poop poo({10, 20});
            poo.Spawn();
            // testing if spawn correctly changes data member
            if (poo.active != true) {
                std::cout << "Poop Test 2 failed (spawn)" << std::endl;
            }
            else {
                std::cout << "Poop Test 2 succeeded (spawn)" << std::endl;
            }
        }

        void testPoopGetRect() {
            // testing if correct rectangle is returned 
            Poop poo({10, 20});
            Rectangle rectangle = poo.getRect();
            if (rectangle.x != 10 || rectangle.y != 20) {
                std::cout << "Poop Test 3 failed (getRect when active)" << std::endl;
            }
            else {
                std::cout << "Poop Test 3 succeeded (getRect when active)" << std::endl;
            }

            poo.deactivate();
            rectangle = poo.getRect();
            Rectangle emptyRec = {};
            // testing if empty rectangle is returned when deactivated
            if (rectangle.x != emptyRec.x || rectangle.y != emptyRec.y) {
                std::cout << "Poop Test 4 failed (getRect when not active)" << std::endl;
            }
            else {
                std::cout << "Poop Test 4 succeeded (getRect when not active)" << std::endl;
            }

        }

        void testPoopDeactivate() {
            Poop poo({10,20});
            poo.deactivate();
            // testing if poop is not active when deactivated
            if (poo.active != false) {
                std::cout << "Poop Test 5 failed (deactivate)" << std::endl;
            }
            else {
                std::cout << "Poop Test 5 succeeded (deactivate)" << std::endl;
            }
        }
};




 
