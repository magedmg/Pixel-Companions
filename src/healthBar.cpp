#include "healthBar.hpp"
#include "raylib.h"

healthBar::healthBar() {
  position = {14, 22};
  health = 97;
  for (int i = 0; i < health; i++) {
    Vector2 positionCol;
    positionCol.x = position.x + (i * 3);
    positionCol.y = position.y;
    rows.push_back(pRow({positionCol}));
  }
}

void healthBar::Draw() {
  for (auto &row : rows) {
    row.Draw();
  }
}

void healthBar::takeDamage(int damage) {
  health -= damage;
  if (health >= 0) {
    for (int i = 0; i < damage; i++) {
      rows.pop_back();
    }
  }
}