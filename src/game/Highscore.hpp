#pragma once
#include <fstream>

class Highscore {
    private:
        std::string shibaScore;
        std::string pinkCatScore;
        std::string greyCatScore;

    public:
        Highscore();

        void addHighscore(std::string score, std::string petBreed);
        std::string getShibaScore();
        std::string getPinkCatScore();
        std::string getGreyCatScore();
};

