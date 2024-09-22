#include "Water.hpp"

#include "raylib.h"

void createImage2(float sizes[2], Texture2D &ImgTexture, const char *path) {
  const char *filename = TextFormat("resources/%s.png", path);
  Image targetImage = LoadImage(filename);
  ImageResize(&targetImage, sizes[0], sizes[1]);
  ImgTexture = LoadTextureFromImage(targetImage);
  UnloadImage(targetImage);
}

Water::Water() {
  float buttonSize[2] = {95, 95};
  createImage2(buttonSize, waterbuttonTexture, "buttons/waterbutton");
  createImage2(buttonSize, waterbuttonClickedTexture,
               "buttons/waterbuttonclicked");

  waterButtonRect = {750, 16, buttonSize[0], buttonSize[1]};
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
