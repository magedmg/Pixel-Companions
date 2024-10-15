#include "CoinUnitTest.hpp"

#include "FoodUnitTest.hpp"
#include "PettingUnitTest.hpp"
#include "PoopUnitTest.hpp"
#include "WaterUnitTest.hpp"

#include "CatUnitTest.hpp"
#include "GreyCatUnitTest.hpp"
#include "HealthBarUnitTest.hpp"
#include "PetUnitTest.hpp"

#include "DogUnitTest.hpp"
#include "GameUnitTest.hpp"
#include "HighscoreUnitTest.hpp"
#include "PinkCatUnitTest.hpp"
#include "ShibaInuUnitTest.hpp"

#include "CoinUnitTest.hpp"
#include <raylib.h>

int main() {
  SetTraceLogLevel(LOG_WARNING); // only prints out errors in terminal
  InitWindow(800, 600, "Test Window");

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

  HighscoreUnitTest highscoreTest;
  highscoreTest.runTests();

  CloseWindow();

  return 0;
}


