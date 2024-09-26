#pragma once
#include "Pet.hpp"
#include <raylib.h>
#include <vector>

class Dog : public Pet {
protected:
  Texture2D image;

  float frameSpeed;
  float frameTime;
  float moveSpeed;
  int curFrame;

  float lastPooTime;

  int randomPooInterval;

public:
  Dog();
  ~Dog();
  virtual void Draw();
  void Update();
  void Poo1();
  void createAnimation(int, int[2], Texture2D *, const char *);

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