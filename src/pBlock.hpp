#pragma once

#include <raylib.h>

class pBlock {
public:
  pBlock(Vector2 position);

  void Draw();

private:
  Vector2 position;
};