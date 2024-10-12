#include "CoinUnitTest.hpp"
#include "FoodUnitTest.hpp"
#include "PettingUnitTest.hpp"
#include "PoopUnitTest.hpp"
#include "WaterUnitTest.hpp"

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
    return 0;
}