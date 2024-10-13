#pragma once

#include "../companion/ShibaInu.hpp"

#include <string>
#include <vector>
#include <iostream>

class ShibaInuUnitTest {
    public:
        void runTests() {
            testShibaInuConstructor();
        }

    private:
        void testShibaInuConstructor() {
            ShibaInu shiba;
            // tests if constructor correctly initialises data members
            if (shiba.hungerInterval != 20 || shiba.thirstInterval != 12 || shiba.happinessInterval != 25 ||
            shiba.scalingFactor != 0.2) {
                std::cout << "ShibaInu Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "ShibaInu Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

};

