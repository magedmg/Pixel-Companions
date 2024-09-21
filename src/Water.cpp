#include "Water.hpp"

#include <filesystem>

#include "raylib.h"

void createImage(int sizes[2], Texture2D& ImgTexture, const char* path);

Water::Water() {
  int buttonSize[2] = {95, 95};
  createImage(buttonSize, waterbuttonTexture, "buttons/waterbutton");
  createImage(buttonSize, waterbuttonClickedTexture,
              "buttons/waterbuttonclicked");

  waterButtonRect = {750, 16, (float)buttonSize[0], (float)buttonSize[1]};
  iswaterbuttonPressed = false;
}

Water::~Water() { unloadTextures(); }

void Water::update() {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePosition = GetMousePosition();

    if (CheckCollisionPointRec(mousePosition, waterButtonRect)) {
      iswaterbuttonPressed = true;
    }
  } else {
    iswaterbuttonPressed = false;
  }
}

void Water::draw() {
  if (iswaterbuttonPressed) {
    DrawTexture(waterbuttonClickedTexture, 750, 16, WHITE);
  } else {
    DrawTexture(waterbuttonTexture, 750, 16, WHITE);
  }
}

void Water::unloadTextures() {
  UnloadTexture(waterbuttonTexture);
  UnloadTexture(waterbuttonClickedTexture);
}