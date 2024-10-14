#include "HealthBar.hpp"
#include "pRow.hpp"
#include "raylib.h"

HealthBar::HealthBar() {
  position = {14, 22};
  health = 97;
  for (int i = 0; i < health; i++) {
    Vector2 positionCol;
    positionCol.x = position.x + (i * 3);
    positionCol.y = position.y;
    rows.push_back(pRow({positionCol}));
  }
}

void HealthBar::Draw() {
  for (auto &row : rows) {
    row.Draw();
  }
}

void HealthBar::takeDamage(int damage) {
  health -= damage;
  if (health >= 0) {
    for (int i = 0; i < damage; i++) {
      rows.pop_back();
    }
  } else {
    health = 0;
  }
}

void HealthBar::healDamage(int heal) {

  int previoushealth = health;
  if (heal + health > 96) {
    health = 97;
  } else {
    health += heal;
  }

  for (int i = previoushealth; i < health; i++) {
    Vector2 positionCol;
    positionCol.x = position.x + (i * 3);
    positionCol.y = position.y;
    rows.push_back(pRow({positionCol}));
  }
}

int HealthBar::getHealth() { return health; }
