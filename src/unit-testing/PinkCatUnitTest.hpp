#pragma once

#include "../companion/pinkCat.hpp"

#include <string>
#include <vector>
#include <iostream>

class PinkCatUnitTest {
    public:
        void runTests() {
            testPinkCatConstructor();
        }

    private:
        void testPinkCatConstructor() {
            pinkCat cat;
            // tests if constructor correctly initialises data members
            if (cat.hungerInterval != 18 || cat.thirstInterval != 11 || cat.happinessInterval != 23 ||
            cat.scalingFactor != 0.4) {
                std::cout << "PinkCat Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "PinkCat Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }





};

