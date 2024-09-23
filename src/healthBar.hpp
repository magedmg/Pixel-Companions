#pragma once
#include "pRow.hpp"
#include <raylib.h>
#include <vector>

class healthBar {
private:
  Vector2 position;
  int health;

public:
  healthBar();

  std::vector<pRow> rows;

  void Draw();

  void takeDamage(int damage);

  void healDamage(int heal);
};