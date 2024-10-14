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
            testFoodGetRect();
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

            // testing if food initial position is correct
            if (rectangle.x != 0 || rectangle.y != -100) {
                std::cout << "Food Test 2 failed (position initialised)" << std::endl;
            }
            else {
                std::cout << "Food Test 2 succeeded (position initialised)" << std::endl;
            }
        }

        void testFoodEat() {
            Food food;
            food.eat();
            // testing if rectangle is reset to 0
            if (food.getRect().x != 0 || food.getRect().y != 0 || 
            food.getRect().height != 0 || food.getRect().width != 0) {
                std::cout << "Food Test 3 failed (rect size when eaten)" << std::endl;
            }
            else {
                std::cout << "Food Test 3 succeeded (rect size when eaten)" << std::endl;
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
                std::cout << "Food Test 4 failed (food falling)" << std::endl;
            }
            else {
                std::cout << "Food Test 4 succeeded (food falling)" << std::endl;
            }

        }

        void testFoodGetRect() {
            Food food;
            Rectangle rectangle = food.getRect();
            // testing if rectangle is at correct starting position
            if (rectangle.x != 0 || rectangle.y != -100) {
                std::cout << "Food Test 5 failed (getRect with no food falling)" << std::endl;
            }
            else {
                std::cout << "Food Test 5 succeeded (getRect with no food falling)" << std::endl;
            }

            Vector2 catPosition = {10,30};
            Vector2 targetPosition = {20, 50};
            bool isRunning = true;
            bool movingRight = true;
            int coins = 2;
            food.getCoins(&coins);
            SetMousePosition(875, 20);

            food.update(catPosition, targetPosition, isRunning, movingRight);
            // testing is rectangle has started falling
            if (food.getRect().y == 0) {
                std::cout << "Food Test 6 failed (getRect with food falling)" << std::endl;
            }
            else {
                std::cout << "Food Test 6 succeeded (getRect with food falling)" << std::endl;
            }
        }


};