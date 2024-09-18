#pragma once

#include <raylib.h>

class pBlock {
public:
  pBlock(Vector2 position);

  void Draw();

  Rectangle getrect();

private:
  Vector2 position;
};