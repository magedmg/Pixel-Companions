#include "Highscore.hpp"

using namespace std;

Highscore::Highscore() {
    // opens text file
    ifstream HighscoreFile("Highscore.txt");
    string textPlaceHolder;

    // reads each line of file and inserts into data members
    getline(HighscoreFile, textPlaceHolder);
    getline(HighscoreFile,greyCatScore);
    getline(HighscoreFile, textPlaceHolder);
    getline(HighscoreFile,pinkCatScore);
    getline(HighscoreFile, textPlaceHolder);
    getline(HighscoreFile,shibaScore);
}


void Highscore::addHighscore(string score, string petBreed) {
    // checks if incoming score is higher than current scores/number of entries, and inserts it
    if (petBreed == "shibaInu") {
        if (stoi(score) > stoi(this->shibaScore)) {
            shibaScore = score;
        }
    }

    if (petBreed == "pinkCat") {
        if (stoi(score) > stoi(this->pinkCatScore)) {
            pinkCatScore = score;
        }
    }

    if (petBreed == "greyCat") {
        if (stoi(score) > stoi(this->greyCatScore)) {
            greyCatScore = score;
        }
    }

    // rewrites new values into file
    ofstream newHighscoreFile("Highscore.txt");
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