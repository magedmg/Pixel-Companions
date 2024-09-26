#include <raylib.h>
#include <raymath.h>

#include "Cat.cpp"
#include "Cat.hpp"
#include "Coin.cpp"
#include "Coin.hpp"
#include "DogX.cpp"
#include "DogX.hpp"
#include "Food.cpp"
#include "Food.hpp"
#include "Game.cpp"
#include "Game.hpp"
#include "Petting.cpp"
#include "Petting.hpp"
#include "Poop.cpp"
#include "Poop.hpp"
#include "Water.cpp"
#include "Water.hpp"
#include "greyCat.cpp"
#include "greyCat.hpp"
#include "healthBar.cpp"
#include "healthBar.hpp"
#include "pBlock.cpp"
#include "pBlock.hpp"
#include "pRow.cpp"
#include "pRow.hpp"

using namespace std;

int main() {

  int windowWidth = 1000;
  int windowHeight = 700;

  // Game window
  InitWindow(windowWidth, windowHeight, "Pixel Companions");

  Game game;

  SetConfigFlags(FLAG_VSYNC_HINT); // Vsync
  SetTargetFPS(60);                // Sets fps cap to 60

  while (!WindowShouldClose()) {
    BeginDrawing();

    // Clears the game of any remaining artifacts of the previous frame
    ClearBackground(RAYWHITE);

    // Updates each frame
    game.updateAll();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}