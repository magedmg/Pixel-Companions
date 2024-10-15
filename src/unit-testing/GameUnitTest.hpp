#pragma once

#include "../game/Game.hpp"

#include <string>
#include <vector>
#include <iostream>

class GameUnitTest {
    public:
        void runTests() {
            testGameConstructor();
        }

    private:
        void testGameConstructor() {
            Game game;
            if (game.gameState != 0) {
                std::cout << "Game Test 1 failed (constructor initialisations)" << std::endl;
            }
            else {
                std::cout << "Game Test 1 succeeded (constructor initialisations)" << std::endl;
            }
        }

};