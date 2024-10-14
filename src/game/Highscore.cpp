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

    greyCatIntScore = stoi(greyCatScore);
    pinkCatIntScore = stoi(pinkCatScore);
    shibaIntScore = stoi(shibaScore);
}


void Highscore::addHighscore(int score, string petBreed) {

    // checks if incoming score is higher than current scores/number of entries, and inserts it
    if (petBreed == "shibaInu") {
        if (score > shibaIntScore) {
            shibaScore = to_string(score);
            shibaIntScore = score;
        }
    } 

    if (petBreed == "pinkCat") {
        if (score > pinkCatIntScore) {
            pinkCatScore = to_string(score);
            pinkCatIntScore = score;
        }
    }

    if (petBreed == "greyCat") {
        if (score > greyCatIntScore) {
            greyCatScore = to_string(score);
            greyCatIntScore = score;
        }
    }

    // rewrites new values into file
    ofstream newHighscoreFile("src/game/Highscore.txt");
    newHighscoreFile << "Grey Cat Highscore:" << endl;
    newHighscoreFile << greyCatIntScore << endl;
    newHighscoreFile << "Pink Cat Highscore:" << endl;
    newHighscoreFile << pinkCatIntScore << endl;
    newHighscoreFile << "Shiba Inu Highscore:" << endl;
    newHighscoreFile << shibaIntScore << endl;
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