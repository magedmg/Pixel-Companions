#include "Game.hpp"
#include "DogX.hpp"
#include "Poop.hpp"
#include "raylib.h"

Game::Game() {
  // Load and resize background image
  bgImage = LoadImage("resources/bg.png");
  ImageResize(&bgImage, windowWidth, windowHeight);
  bgImageTexture = LoadTextureFromImage(bgImage);
}

void Game::updateAll() {
  flag = 0;
  DrawTextureV(bgImageTexture, {0, 0}, WHITE);
  dog.Draw();

  dog.Poo1();

  for (int i = 0; i < dog.currentPooCount; i++) {
    dog.poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < dog.currentPooCount; i++) {
      if (CheckCollisionRecs(dog.poos[i]->getRect(), collisionRect)) {
        dog.poos[i]->deactivate();
        flag = 1;
      }
    }
  }
  if (flag == 0) {
    dog.Update();
  }
}