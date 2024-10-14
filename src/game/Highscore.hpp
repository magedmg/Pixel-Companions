#pragma once
#include <fstream>
#include <string>
class Highscore {
    private:
        std::string shibaScore;
        std::string pinkCatScore;
        std::string greyCatScore;

    public:
        Highscore();

        void addHighscore(int score, std::string petBreed);
        std::string getShibaScore();
        std::string getPinkCatScore();
        std::string getGreyCatScore();
};


