#pragma once
#include <raylib.h>

class Petting {
private:
  Texture2D heartTextures[5];
  int currentFrame;
  float frameTime;
  float frameSpeed;

  Vector2 position;

  bool active;

  float time;

public:
  Petting();

  void Draw();

  bool Status();

  void Update(Vector2 position);

  ~Petting();
};