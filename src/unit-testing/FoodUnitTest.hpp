#pragma once

#include "../pet-essentials/Food.hpp"

#include <string>
#include <vector>
#include <iostream>


class FoodUnitTest {

    public: 
        void runTests() {
            testFoodConstructor();
            testFoodEat();
            testFoodUpdate();
        }

    private:
        void testFoodConstructor() {
            Food food;
            Rectangle rectangle = food.getRect();

            // testing if food sizes is correct
            if (food.foodButtonRect.x != 870 || food.foodButtonRect.y != 16 || 
            food.foodButtonRect.height != 95 || food.foodButtonRect.width != 95) {
                std::cout << "Food Test 1 failed (sizes initialised)" << std::endl;
            }
            else {
                std::cout << "Food Test 1 succeeded (sizes initialised)" << std::endl;
            }

        }

        void testFoodEat() {
            Food food;
            food.eat();
            // testing if rectangle is reset to 0
            if (food.getRect().x != 0 || food.getRect().y != 0 || 
            food.getRect().height != 0 || food.getRect().width != 0) {
                std::cout << "Food Test 2 failed (rect size when eaten)" << std::endl;
            }
            else {
                std::cout << "Food Test 2 succeeded (rect size when eaten)" << std::endl;
            }
        }
        void testFoodUpdate() {
            Food food;
            Vector2 catPosition = {10,30};
            Vector2 targetPosition = {20, 50};
            bool isRunning = true;
            bool movingRight = true;
            int coins = 2;
            food.getCoins(&coins);
            SetMousePosition(875, 20);

            food.update(catPosition, targetPosition, isRunning, movingRight);
            // testing if food starts falling 
            if (food.getRect().y != 0) {
                std::cout << "Food Test 3 failed (food falling)" << std::endl;
            }
            else {
                std::cout << "Food Test 3 succeeded (food falling)" << std::endl;
            }

        }



};