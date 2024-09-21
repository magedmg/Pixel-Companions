#pragma once
#include <raylib.h>

#include <vector>

#include "Poop.hpp"

class DogX {
private:
  Texture2D image;
  Vector2 position;
  Texture2D standTextures[4];
  Texture2D runRightTextures[6];
  Texture2D runLeftTextures[6];
  Vector2 targetPosition;
  int curFrame;
  float frameSpeed;
  float frameTime;
  float moveSpeed;
  bool isRunning;
  bool movingRight;

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
};