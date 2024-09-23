#include "pBlock.hpp"
#include "raylib.h"

pBlock::pBlock(Vector2 position) { this->position = position; }

void pBlock::Draw() {
  // Draws a rectangle for each poop pixel
  DrawRectangle(position.x, position.y, 3, 3, {136, 8, 8, 255});
}
