#pragma once
#include "Dog.hpp"

class ShibaInu : public Dog {
private:
  Texture2D standTextures[4];
  Texture2D runRightTextures[6];
  Texture2D runLeftTextures[6];
  Image deathImage;
  Texture2D deathTexture;

public:
  ShibaInu();
  ~ShibaInu();
  void Draw();
};