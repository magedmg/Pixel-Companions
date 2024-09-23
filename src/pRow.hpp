#pragma once
#include "pBlock.hpp"
#include <raylib.h>
#include <vector>

class pRow {

public:
  void Draw();

  pRow(Vector2 position);

  std::vector<pBlock> blocks;
};