#pragma once

#include "../pet-essentials/Water.hpp"
#include "raylib.h"

#include <string>
#include <vector>
#include <iostream>

class WaterUnitTest {
    public:
        void runTests() {
            testWaterConstructor();
            testWaterDrink();
            testWaterGetRect();
        }

    private:
        void testWaterConstructor() {
            Water water;
            // test if data members are initialised correctly in constructor
            if (water.waterButtonRect.x != 750 || water.waterButtonRect.y != 16 ||
            water.waterButtonRect.height != 95 || water.waterButtonRect.width != 95) {
                std::cout << "Water Test 1 failed (constructor initialisation)" << std::endl;
            }
            else {
                std::cout << "Water Test 1 succeeded (constructor initialisation)" << std::endl;
            }
        }

        void testWaterDrink() {
            Water water;
            int coins = 2;
            water.getCoins(&coins);
            SetMousePosition(750, 16);
            water.update();
            water.drink();
            // test if the rectangle changes correctly after drinking water
            if (water.getRect().x != 0 || water.getRect().y != 0) {
                std::cout << "Water Test 2 failed (drink water)" << std::endl;
            }
            else {
                std::cout << "Water Test 2 succeeded (drink water)" << std::endl;
            }   
        }

        void testWaterGetRect() {
            Water water;
            Rectangle rectangle = water.getRect();
            // tests if correct rectangle dimensions are returned
            if (rectangle.x != 0 || rectangle.y != 0 || rectangle.width != 0 || rectangle.height != 0) {
                std::cout << "Water Test 3 failed (getRect with empty water bowl" << std::endl;
            }
            else {
                std::cout << "Water Test 3 succeeded (getRect with empty water bowl)" << std::endl;
            }
        }

};