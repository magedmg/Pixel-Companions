#pragma once

#include "../companion/Pet.hpp"
#include "../companion/greyCat.hpp"

#include <string>
#include <vector>
#include <iostream>

class PetUnitTest {
    public:
        void runTests() {
            testPetConstructor();
            testPetUpdateStatus();
        }

    private:
        void testPetConstructor() {
            greyCat cat;
            if (cat.level != 0) {
                std::cout << "Pet Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "Pet Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

        void testPetUpdateStatus() {
            greyCat cat;
            float initialTime = GetTime();
            while (GetTime() - initialTime < 12) {
                cat.updateStatus();
            }

            if (cat.currentThirst >= 100) {
                std::cout << "Pet Test 2 failed (update status check for decreasing statuses)" << std::endl;
            }
            else {
                std::cout << "Pet Test 2 failed (update status check for decreasing statuses)" << std::endl;
            }

            if (cat.level == 0) {
                std::cout << "Pet Test 3 failed (update status check for level up)" << std::endl;
            }
            else {
                std::cout << "Pet Test 3 failed (update status check for level up)" << std::endl;
            }

        }
};