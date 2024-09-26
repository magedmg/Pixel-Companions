#pragma once
#include "Cat.hpp"

class pinkCat : public Cat {
private:
  Texture2D standTextures[4];
  Texture2D runRightTextures[6];
  Texture2D runLeftTextures[6];
  Image deathImage;
  Texture2D deathTexture;

public:
  pinkCat();
  ~pinkCat();
  void Draw();
};