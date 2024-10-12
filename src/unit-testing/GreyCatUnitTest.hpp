#pragma once

#include "../companion/greyCat.hpp"

#include <string>
#include <vector>
#include <iostream>

class GreyCatUnitTest {
    public:
        void runTests() {
            testGreyCatConstructor();
        }

    private:
        void testGreyCatConstructor() {
            greyCat cat;
            // tests if constructor correctly initialises data members
            if (cat.hungerInterval != 20 || cat.thirstInterval != 12 || cat.happinessInterval != 25 ||
            cat.scalingFactor != 0.5) {
                std::cout << "GreyCat Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "GreyCat Test 2 succeeded (constructor initialisations)" << std::endl;
            }
        }

};

