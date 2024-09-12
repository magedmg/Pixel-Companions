#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <raylib.h>
#include <raymath.h>

class Game {
    private:
        std::string petType;

    public:
        Game();
        Game(std::string petType);
        void loadImages();
        void runGame();
};

#endif