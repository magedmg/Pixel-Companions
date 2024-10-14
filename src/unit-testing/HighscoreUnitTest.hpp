#pragma once


#include "../game/Highscore.hpp"

#include <string>
#include <vector>
#include <iostream>

class HighscoreUnitTest {
    public:
        void runTests() {
            testHighscoreConstructor();
            testAddHighscore();
        }
    
    private:
        void testHighscoreConstructor() {
            Highscore highscore;
            if (highscore.getGreyCatScore() == "" || highscore.getPinkCatScore() == "" ||
            highscore.getShibaScore() == "") {
                std::cout << "Highscore Test 1 failed (highscore constructor)" << std::endl;
            }
            else {
                std::cout << "Highscore Test 1 succeeded (highscore constructor)" << std::endl;
            }
        }

        void testAddHighscore() {
            Highscore highscore;
            int score = 123;
            std::string petBreed = "pinkCat";
            highscore.addHighscore(score, petBreed);
            if (highscore.getPinkCatScore() != "123") {
                std::cout << "Highscore Test 2 failed (adding highscore)" << std::endl;
            }
            else {
                std::cout << "Highscore Test 2 succeeded (adding highscore)" << std::endl;
            }
        }

};



