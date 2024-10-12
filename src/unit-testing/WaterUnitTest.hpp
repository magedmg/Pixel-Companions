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
            testWaterUpdate();
            testWaterDrink();
            testWaterGetRect();
        }

    private:
        void testWaterConstructor() {
            Water water;
            if (water.waterButtonRect.x != 750 || water.waterButtonRect.y != 16 ||
            water.waterButtonRect.height != 95 || water.waterButtonRect.width != 95) {
                std::cout << "Water Test 1 failed (constructor initialisation)" << std::endl;
            }
            else {
                std::cout << "Water Test 1 succeeded (constructor initialisation)" << std::endl;
            }
        }

        void testWaterUpdate() {
            Water water;
            int coins = 2;
            water.getCoins(&coins);
            SetMousePosition(750, 16);
            water.update();
            if (water.getRect().x != 700 || water.getRect().y != 470) {
                std::cout << "Water Test 2 failed (water update)" << std::endl;
            }
            else {
                std::cout << "Water Test 2 succeeded (water update)" << std::endl;
            }
        }

        void testWaterDrink() {
            Water water;
            int coins = 2;
            water.getCoins(&coins);
            SetMousePosition(750, 16);
            water.update();
            water.drink();
            if (water.getRect().x != 0 || water.getRect().y != 0) {
                std::cout << "Water Test 3 failed (drink water)" << std::endl;
            }
            else {
                std::cout << "Water Test 3 succeeded (drink water)" << std::endl;
            }   
        }
        void testWaterGetRect() {
            Water water;
            Rectangle rectangle = water.getRect();
            if (rectangle.x != 0 || rectangle.y != 0 || rectangle.width != 0 || rectangle.height != 0) {
                std::cout << "Water Test 4 failed (getRect with empty water bowl" << std::endl;
            }
            else {
                std::cout << "Water Test 4 succeeded (getRect with empty water bowl)" << std::endl;
            }

            int coins = 2;
            water.getCoins(&coins);
            SetMousePosition(750, 16);
            water.update();
            rectangle = water.getRect();
            if (rectangle.x != 700 || rectangle.y != 470 || rectangle.width != 110 || rectangle.height != 90) {
                std::cout << "Water Test 5 failed (getRect with full water bowl" << std::endl;
            }
            else {
                std::cout << "Water Test 5 succeeded (getRect with full water bowl)" << std::endl;
            }
        }

};