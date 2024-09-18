#include "Game.hpp"
#include "DogX.hpp"
#include "raylib.h"

Game::Game() {
  // Load and resize background image
  bgImage = LoadImage("resources/bg.png");
  ImageResize(&bgImage, windowWidth, windowHeight);
  bgImageTexture = LoadTextureFromImage(bgImage);
}

void Game::updateAll() {
  DrawTextureV(bgImageTexture, {0, 0}, WHITE);
  dog.Draw();
  dog.Update();
}