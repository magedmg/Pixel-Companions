#include "CoinUnitTest.hpp"
#include "FoodUnitTest.hpp"
#include "PettingUnitTest.hpp"
#include "PoopUnitTest.hpp"
#include "WaterUnitTest.hpp"

#include "GreyCatUnitTest.hpp"
#include "CatUnitTest.hpp"
#include "PetUnitTest.hpp"
#include "HealthBarUnitTest.hpp"

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

    return 0;
}