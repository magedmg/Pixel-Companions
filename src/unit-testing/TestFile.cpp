#include "CoinUnitTest.h"
#include "FoodUnitTest.h"
#include "PettingUnitTest.h"
#include "PoopUnitTest.h"
#include "WaterUnitTest.h"

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