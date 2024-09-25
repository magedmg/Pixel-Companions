#pragma once
#include <raylib.h>
#include "Pet.hpp"
#include <vector>
#include "Pet.cpp"

#include "Poop.hpp"

class DogX : public Pet {
private:
  Texture2D image;
  Image deathImage;

  Texture2D standTextures[4];
  Texture2D runRightTextures[6];
  Texture2D runLeftTextures[6];
  Texture2D deathTexture;

  float frameSpeed;
  float frameTime;
  float moveSpeed;
  int curFrame;

  float lastPooTime;

  int randomPooInterval;

public:
  DogX();
  ~DogX();
  void Draw();
  void Update();
  void Poo1();

  Poop **poos;
  int currentPooCount;

  std::vector<Poop> poos1;

  Rectangle getRect();

  // Create getters and setters for these in the futore
  Vector2 position;
  Vector2 targetPosition;
  bool isRunning;
  bool isDead;
  bool movingRight;

};