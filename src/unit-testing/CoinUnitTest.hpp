#pragma once

#include "../pet-essentials/Coin.hpp"

#include <iostream>
#include <string>
#include <vector>
class CoinUnitTest {

public:
  void runTests() {
    testCoinConstructor();
    testCoinGetRect();
  }

private:
  void testCoinGetRect() {
    Vector2 startPos = {10, 40};
    Coin coin1(startPos);

    // testing for rectangle with no collision
    Rectangle rectangle = coin1.getRect();
    if (rectangle.width <= 15 || rectangle.height <= 35 || rectangle.x != 10 ||
        rectangle.y != 40) {
      std::cout << "Coin Test 1 failed (getRect with no collision)"
                << std::endl;
    } else {
      std::cout << "Coin Test 1 succeeded (getRect with no collision)"
                << std::endl;
    }

    // testing for rectangle with collision
    coin1.collision = true;
    rectangle = coin1.getRect();
    if (rectangle.width != 0 || rectangle.height != 0 || rectangle.x != 0 ||
        rectangle.y != 0) {
      std::cout << "Coin Test 2 failed (getRect with collision)" << std::endl;
    } else {
      std::cout << "Coin Test 2 succeeded (getRect with collision)"
                << std::endl;
    }
  }

  void testCoinConstructor() {
    Vector2 startPos = {20, 30};
    Coin coin2(startPos);

    // testing if coin position is correct
    if (coin2.position.x != 20 || coin2.position.y != 30) {
      std::cout << "Coin Test 3 failed (position initialised)" << std::endl;
    } else {
      std::cout << "Coin Test 3 succeeded (position initialised)" << std::endl;
    }

    // testing if coin data members are correct
    if (coin2.active != true || coin2.collision != false) {
      std::cout << "Coin Test 4 failed (data members initialised)" << std::endl;
    } else {
      std::cout << "Coin Test 4 succeeded (data members initialised)"
                << std::endl;
    }
  }
};