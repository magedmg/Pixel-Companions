#pragma once
#include <raylib.h>

class Poop {
public:
  Poop(Vector2 position);

  void Draw();
  void Update();

  ~Poop();

  void Spawn();
  Vector2 position;

  Rectangle getRect();
  void deactivate();

  bool active;

private:
  Image pooImage;

  Texture2D pooTexture;
};