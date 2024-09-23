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
  float emptyWaterBowlSize[2] = {90,70};
  float fullWaterBowlSize[2] = {110,90};
  createImage2(buttonSize, waterbuttonTexture, "buttons/waterbutton");
  createImage2(buttonSize, waterbuttonClickedTexture,
               "buttons/waterbuttonclicked");
  createImage2(emptyWaterBowlSize, emptyWaterBowlTexture, "water/emptyWater");
  createImage2(fullWaterBowlSize, fullWaterBowlTexture, "water/fullWater");

  waterButtonRect = {750, 16, buttonSize[0], buttonSize[1]};
  waterBowlRect = {700, 470, fullWaterBowlSize[0], fullWaterBowlSize[1]};

  iswaterbuttonPressed = false;
  isBowlFull = false;
}

Water::~Water() { unloadTextures(); }

void Water::update() {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePosition = GetMousePosition();

    if (CheckCollisionPointRec(mousePosition, waterButtonRect)) {
        if (*currCoins >= 1) {
          iswaterbuttonPressed = true;
          isBowlFull = true;
          *currCoins -= 1;
        }
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

  if (isBowlFull) {
    DrawTexture(fullWaterBowlTexture, 700, 470, WHITE);
  }
  else {
    DrawTexture(emptyWaterBowlTexture, 710, 480, WHITE);
  }
}

void Water::unloadTextures() {
  UnloadTexture(waterbuttonTexture);
  UnloadTexture(waterbuttonClickedTexture);
}

void Water::drink() {
  isBowlFull = false;
}
void Water::getCoins(int *currentCoins) {
  this->currCoins = currentCoins;
}

Rectangle Water::getRect() {
  return waterBowlRect;
  }
  
