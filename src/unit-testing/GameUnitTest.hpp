#pragma once

#include "../game/Game.hpp"

#include <string>
#include <vector>
#include <iostream>

class GameUnitTest {
    public:
        void runTests() {
            testGameConstructor();
            testActiveGame();
            testResetGame();
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

        void testActiveGame() {
            Game game;
            game.activeGame();
            if (game.flag != 0 || game.gameState != 1) {
                std::cout << "Game Test 2 failed (active game initialisations)" << std::endl;
            }
            else {
                std::cout << "Game Test 2 succeeded (active game initialisations)" << std::endl;
            }
        }

        void testResetGame() {
            Game game;
            game.activeGame();
            game.Reset();
            if (game.gameState != 0) {
                std::cout << "Game Test 3 failed (reset game initialisations)" << std::endl;
            }
            else {
                std::cout << "Game Test 3 succeeded (reset game initialisations)" << std::endl;
            }
        }
};