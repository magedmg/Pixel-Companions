#include "pBlock.hpp"
#include "raylib.h"

pBlock::pBlock(Vector2 position) { this->position = position; }

void pBlock::Draw() {
  // Draws a rectangle for each poop pixel
  DrawRectangle(position.x, position.y, 3, 3, {92, 64, 51, 255});
}

Rectangle pBlock::getrect() {
  Rectangle rect;
  rect.x = position.x;
  rect.y = position.y;
  rect.width = 3;
  rect.height = 3;
  return rect;
}