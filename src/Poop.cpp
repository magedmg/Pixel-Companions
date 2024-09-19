#include "Poop.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;

Poop::Poop(Vector2 position) {

  active = false;
  pooImage = LoadImage("resources/poo.png");
  ImageResize(&pooImage, 35, 35);
  pooTexture = LoadTextureFromImage(pooImage);

  this->position = position;
  Spawn();
}

void Poop::Spawn() { active = true; }

void Poop::Draw() {
  if (active) {
    DrawTextureV(pooTexture, position, WHITE);
  }
}

Poop::~Poop() { UnloadTexture(pooTexture); }

Rectangle Poop::getRect() {
  if (active == false) {
    return {};
  }
  else {
  return {position.x, position.y, float{static_cast<float>(pooImage.width)},
          float{static_cast<float>(pooImage.height)}};
  }
}

void Poop::deactivate() { active = false; }