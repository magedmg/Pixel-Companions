#include "Highscore.hpp"
#include <iostream>

using namespace std;

Highscore::Highscore() {
    // opens text file
    ifstream HighscoreFile("src/game/Highscore.txt");
    string textPlaceHolder;

    // reads each line of file and inserts into data members
    getline(HighscoreFile, textPlaceHolder);
    getline(HighscoreFile,greyCatScore);
    getline(HighscoreFile, textPlaceHolder);
    getline(HighscoreFile,pinkCatScore);
    getline(HighscoreFile, textPlaceHolder);
    getline(HighscoreFile,shibaScore);
}


void Highscore::addHighscore(int score, string petBreed) {
    std::cout << "Grey Cat Score: " << greyCatScore << std::endl;
    std::cout << "Pink Cat Score: " << pinkCatScore << std::endl;
    std::cout << "Shiba Score: " << shibaScore << std::endl;

    // checks if incoming score is higher than current scores/number of entries, and inserts it
    if (petBreed == "shibaInu") {
        if (score > stoi(shibaScore)) {
            shibaScore = to_string(score);
        }
    } 

    if (petBreed == "pinkCat") {
        if (score > stoi(pinkCatScore)) {
            pinkCatScore = to_string(score);
        }
    }

    if (petBreed == "greyCat") {
        if (score > stoi(greyCatScore)) {
            greyCatScore = to_string(score);
        }
    }

    // rewrites new values into file
    ofstream newHighscoreFile("src/game/Highscore.txt");
    newHighscoreFile << "Grey Cat Highscore:" << endl;
    newHighscoreFile << greyCatScore << endl;
    newHighscoreFile << "Pink Cat Highscore:" << endl;
    newHighscoreFile << pinkCatScore << endl;
    newHighscoreFile << "Shiba Inu Highscore:" << endl;
    newHighscoreFile << shibaScore << endl;
}

string Highscore::getShibaScore() {
    return shibaScore;
}

string Highscore::getPinkCatScore() {
    return pinkCatScore;
}

string Highscore::getGreyCatScore() {
    return greyCatScore;
}

// Text file should look like

//Grey Cat Highscore:
// 50
//Pink Cat Highscore:
// 10
//Shiba Highscore:
//100