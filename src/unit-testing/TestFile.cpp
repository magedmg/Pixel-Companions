#include "CoinUnitTest.hpp"
#include "FoodUnitTest.hpp"
#include "PettingUnitTest.hpp"
#include "PoopUnitTest.hpp"
#include "WaterUnitTest.hpp"

#include "GreyCatUnitTest.hpp"
#include "CatUnitTest.hpp"
#include "PetUnitTest.hpp"
#include "HealthBarUnitTest.hpp"

#include "PinkCatUnitTest.hpp"
#include "DogUnitTest.hpp"
#include "ShibaInuUnitTest.hpp"
#include "GameUnitTest.hpp"

using namespace std;

int main() {
    CoinUnitTest coinTest;
    coinTest.runTests();

    FoodUnitTest foodTest;
    foodTest.runTests();

    PettingUnitTest pettingTest;
    pettingTest.runTests();

    PoopUnitTest poopTest;
    poopTest.runTests();

    WaterUnitTest waterTest;
    waterTest.runTests();

    GreyCatUnitTest greyCatTest;
    greyCatTest.runTests();

    CatUnitTest catTest;
    catTest.runTests();

    PettingUnitTest petTest;
    petTest.runTests();

    HealthBarUnitTest healthTest;
    healthTest.runTests();

    PinkCatUnitTest pinkCatTest;
    pinkCatTest.runTests();

    DogUnitTest dogTest;
    dogTest.runTests();

    ShibaInuUnitTest shibaTest;
    shibaTest.runTests();

    GameUnitTest gameTest;
    gameTest.runTests();

    return 0;
}