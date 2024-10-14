#pragma once

#include "../companion/Cat.hpp"

#include <iostream>

#include <string>
#include <vector>

class CatUnitTest {

public:
  void runTests() {
    testCatConstructor();
    testCatUpdate();
    testCatGetRect();
  }

private:
  void testCatConstructor() {
    Cat cat;
    // tests if data members are initialised correctly in constructor
    if (cat.levelUpInterval != 10 || cat.position.x != 250 ||
        cat.position.y != 480 || cat.isRunning != false ||
        cat.isDead != false) {
      std::cout << "Cat Test 1 failed (constructor initialisations)"
                << std::endl;
    } else {
      std::cout << "Cat Test 1 succeeded (constructor initialisations)"
                << std::endl;
    }
  }

  void testCatUpdate() {
    Cat cat;
    SetMousePosition(300, 480);
    cat.Update();
    // tests if cat starts running
    if (cat.isRunning != true) {
      std::cout << "Cat Test 2 failed (cat update, running check)" << std::endl;
    } else {
      std::cout << "Cat Test 2 succeeded (cat update, running check)"
                << std::endl;
    }

    cat.Update();
    // tests if cat position is different to initial position
    if (cat.getRect().x == 250 || cat.getRect().y == 480) {
      std::cout << "Cat Test 3 failed (cat update, position check)"
                << std::endl;
    } else {
      std::cout << "Cat Test 3 succeeded (cat update, position check)"
                << std::endl;
    }
  }

  void testCatGetRect() {
    Cat cat;
    // tests if correct rectangle is returned
    if (cat.getRect().height != 95 || cat.getRect().width != 85 ||
        cat.getRect().x != 250 || cat.getRect().y != 480) {
      std::cout << "Cat Test 4 failed (getRect)" << std::endl;
    } else {
      std::cout << "Cat Test 4 succeeded (getRect)" << std::endl;
    }
  }
};
