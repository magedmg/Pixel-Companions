#pragma once
#include "pRow.hpp"
#include <raylib.h>
#include <vector>

class HealthBar {
private:
  Vector2 position;
  int health;

public:
  HealthBar();

  std::vector<pRow> rows;

  void Draw();

  void takeDamage(int damage);

  void healDamage(int heal);

  int getHealth();
};
