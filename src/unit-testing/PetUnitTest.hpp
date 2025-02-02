#pragma once

#include "../companion/Pet.hpp"
#include "../companion/GreyCat.hpp"

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
            GreyCat cat;
            // tests if constructor correctly initialises data members
            if (cat.level != 0) {
                std::cout << "Pet Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "Pet Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

        void testPetUpdateStatus() {
            GreyCat cat;
            float initialTime = GetTime();
            // update status over 12 seconds (for grey cat)
            float lastPrintTime = GetTime();
            while (GetTime() - initialTime < 12) {
                cat.updateStatus();
                float currentTime = GetTime();
                if (currentTime - lastPrintTime >= 1) { 
                    // print statement while 12 seconds pass
                    std::cout << "Simulating frames for pet status check..." << std::endl;
                    lastPrintTime = currentTime; 
        }
            }
            // tests if thirst status has changed

            if (cat.currentThirst >= 100) {
                std::cout << "Pet Test 2 failed (update status check for decreasing statuses)" << std::endl;
            }
            else {
                std::cout << "Pet Test 2 failed (update status check for decreasing statuses)" << std::endl;
            }

            // tests if pet has levelled up
            if (cat.level == 0) {
                std::cout << "Pet Test 3 failed (update status check for level up)" << std::endl;
            }
            else {
                std::cout << "Pet Test 3 failed (update status check for level up)" << std::endl;
            }

        }
};