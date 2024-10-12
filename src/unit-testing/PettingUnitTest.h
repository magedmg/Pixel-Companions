#pragma once

#include "../pet-essentials/Petting.hpp"

#include <string>
#include <vector>
#include <iostream>

class PettingUnitTest {
    public:
        void runTests() {
            testPettingConstructor();
            testPettingStatus();
        }


    private:
        void testPettingConstructor() {
            Petting pets;
            // testing if data members are correctly initialised when constructed
            if (pets.Status() != false) {
                std::cout << "Petting Test 1 failed (constructor)" << endl;
            }
            else {
                std::cout << "Petting Test 1 succeeded (constructor)" << endl;
            }

        }
        void testPettingStatus() {
            Petting pets;
            // testing if correct status is set
            if (pets.Status() != false) {
                std::cout << "Petting Test 2 failed (status before update)" << endl;
            }
            else {
                std::cout << "Petting Test 2 succeeded (status before update)" << endl;
            }

            // testing if status is updated
            pets.Update({100,20});
            if (pets.Status() == false) {
                std::cout << "Petting Test 3 failed (status after update)" << endl;
            }
            else {
                std::cout << "Petting Test 3 succeeded (status after update)" << endl;
            }
        }

};
