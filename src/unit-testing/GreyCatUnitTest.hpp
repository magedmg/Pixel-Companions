#pragma once

#include "../companion/GreyCat.hpp"

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
            GreyCat cat;
            // tests if constructor correctly initialises data members
            if (cat.hungerInterval != 18 || cat.thirstInterval != 10 || cat.happinessInterval != 21 ||
            cat.scalingFactor != 0.5) {
                std::cout << "GreyCat Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "GreyCat Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

};

