#include "Dog.hpp"

#include <raylib.h>

#include <iostream>
using namespace std;

Dog::Dog() {
  levelUpInterval = 5;
  // Initial position
  position = {250, 480};

  poos = new Poop *[5];
  for (int i = 0; i < 5; i++) {
    poos[i] = new Poop({0, 0});
  }
  // setting last poop time
  lastPooTime = GetTime();
  lastFedTime = GetTime();
  lastDrankTime = GetTime();
  lastPetTime = GetTime();
  petType = "dog";

  // DEFINE VARIABLES TO USE IN LOOP
  targetPosition = position;
  isRunning = false; // Indicates whether the cat is running
  isDead = false;
  movingRight = true;
  targetPosition = position;
  curFrame = 0;       // Index of the current frame
  frameSpeed = 0.25f; // Speed at which frames change (seconds per frame)
  frameTime = 0.0f;   // Time accumulator

  currentHunger = 100;
  currentThirst = 100;
  currentHappiness = 100;

  currentPooCount = 0;
}

void Dog::Draw() {
  float deltaTime = GetFrameTime();

  frameTime += deltaTime;
  if (!isDead && frameTime >= frameSpeed) {
    frameTime = 0.0f;
    if (isRunning) {
      curFrame = (curFrame + 1) % 5;
    } else {
      curFrame = (curFrame + 1) % 4;
    }
  }
}
// Updates position
void Dog::Update() {
  float deltaTime = GetFrameTime();
  // Make sure the dog cant go off the screen
  if (!isDead) {
    if (position.x > (1000 - 85)) {
      position.x = 915;
      isRunning = false;
    } else if (position.x < 20) {
      position.x = 20;
      isRunning = false;
    }

    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0f;
      if (isRunning) {
        curFrame = (curFrame + 1) % 6;
      } else {
        curFrame = (curFrame + 1) % 4;
      }
    }

    // DOG RUNNING PART
    if (isRunning) {
      if (movingRight) {
        position.x += moveSpeed * deltaTime;
        if (position.x >= targetPosition.x) {
          position.x = targetPosition.x;
          isRunning = false;
          // curFrame = 0;
        }
      } else {
        position.x -= moveSpeed * deltaTime;
        if (position.x <= targetPosition.x) {
          position.x = targetPosition.x;
          isRunning = false;
          // curFrame = 0;
        }
      }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      targetPosition = GetMousePosition();
      isRunning = true;
      // Determine direction based on mouse position
      if (targetPosition.x > position.x) {
        movingRight = true;
      } else if (targetPosition.x < position.x) {
        movingRight = false;
      }
    }
  }
}
// Deletes the heap allocated poops
Dog::~Dog() {
  for (int i = 0; i < 5; i++) {
    delete poos[i];
  }
  delete[] poos;
}

void Dog::Poo1() {
  if (GetTime() - lastPooTime >= randomPooInterval && currentPooCount < 5) {
    poos[currentPooCount]->position = {position.x - image.width - 30,
                                       position.y + 40};
    poos[currentPooCount]->Spawn();
    lastPooTime = GetTime();
    currentPooCount++;
    randomPooInterval = GetRandomValue(3, 8); // Dog poos more often than cat
  }
}

Rectangle Dog::getRect() {
  Rectangle rect;
  rect.x = position.x;
  rect.y = position.y;
  rect.height = 95;
  rect.width = 85;
  return rect;
}
