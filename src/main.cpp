#include <raylib.h>
#include <raymath.h>

#include "companion/Cat.cpp"
#include "companion/Cat.hpp"
#include "companion/Pet.cpp"
#include "companion/Pet.hpp"
#include "companion/greyCat.cpp"
#include "companion/greyCat.hpp"
#include "game/Game.cpp"
#include "game/Game.hpp"
#include "health/healthBar.cpp"
#include "health/healthBar.hpp"
#include "health/pBlock.cpp"
#include "health/pBlock.hpp"
#include "health/pRow.cpp"
#include "health/pRow.hpp"
#include "pet-essentials/Coin.cpp"
#include "pet-essentials/Coin.hpp"
#include "pet-essentials/Food.cpp"
#include "pet-essentials/Food.hpp"
#include "pet-essentials/Petting.cpp"
#include "pet-essentials/Petting.hpp"
#include "pet-essentials/Poop.cpp"
#include "pet-essentials/Poop.hpp"
#include "pet-essentials/Water.cpp"
#include "pet-essentials/Water.hpp"

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