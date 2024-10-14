#pragma once
#include <fstream>
#include <string>
class Highscore {
    private:
        std::string shibaScore;
        std::string pinkCatScore;
        std::string greyCatScore;

        int shibaIntScore;
        int pinkCatIntScore;
        int greyCatIntScore;

    public:
        Highscore();

        void addHighscore(int score, std::string petBreed);
        std::string getShibaScore();
        std::string getPinkCatScore();
        std::string getGreyCatScore();

};


