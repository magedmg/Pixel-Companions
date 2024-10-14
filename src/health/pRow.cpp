#include "pRow.hpp"
#include "pBlock.hpp"
#include "raylib.h"

void pRow::Draw() {
  for (auto &block : blocks) {
    block.Draw();
  }
}

pRow::pRow(Vector2 position) {
  // creates a column of pBlocks
  for (int i = 0; i < 5; i++) {
    Vector2 positionDraw;
    positionDraw.x = position.x;
    positionDraw.y = position.y + (i * 3);
    blocks.push_back(pBlock{positionDraw});
  }
}