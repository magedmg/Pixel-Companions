#pragma once

#include "../health/HealthBar.hpp"

#include <string>
#include <vector>
#include <iostream>

class HealthBarUnitTest {
    public:
        void runTests() {
            testHealthConstructor();
            testHealthTakeDamage();
            testHealthHealDamage();
            testGetHealth();
        }

    private:
        void testHealthConstructor() {
            HealthBar health;
            // tests if constructor sets the health data member to the correct value
            if (health.getHealth() != 97) {
                std::cout << "Healthbar Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "Healthbar Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

        void testHealthTakeDamage() {
            HealthBar health;
            health.takeDamage(50);
            // tests if damage is taken correctly
            if (health.getHealth() != 47) {
                std::cout << "Healthbar Test 2 failed (taking damage with health above 0)" << std::endl;
            }
            else {
                std::cout << "Healthbar Test 2 succeeded (taking damage with health above 0)" << std::endl;
            }

            // tests if health never goes below 0
            health.takeDamage(100);
            if (health.getHealth() != 0) {
                std::cout << "Healthbar Test 3 failed (taking damage with health less than 0)" << std::endl;
            }
            else {
                std::cout << "Healthbar Test 3 succeeded (taking damage with health less than 0)" << std::endl;
            }

        }
        
        void testHealthHealDamage() {
            HealthBar health;
            health.takeDamage(50);
            health.healDamage(30);
            // tests healing function
            if (health.getHealth() != 77) {
                std::cout << "Healthbar Test 4 failed (healing with health below 97)" << std::endl;
            }
            else {
                std::cout << "Healthbar Test 4 succeeded (healing with health below 97)" << std::endl;
            }

            health.healDamage(100);
            // tests if healing function surpasses max of 97
            if (health.getHealth() != 97) {
                std::cout << "Healthbar Test 5 failed (healing with health above 97)" << std::endl;
            }
            else {
                std::cout << "Healthbar Test 5 succeeded (healing with health above 97)" << std::endl;
            }
        }

        void testGetHealth() {
            HealthBar health;
            // tests if correct health is returned
            if (health.getHealth() != 97) {
                std::cout << "Healthbar Test 6 failed (getHealth)" << std::endl;
            }
            else {
                std::cout << "Healthbar Test 6 succeeded (getHealth)" << std::endl;
            }
        }


};

