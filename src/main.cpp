#include <raylib.h>
#include <raymath.h>

#include "companion/Cat.hpp"

#include "companion/GreyCat.hpp"

#include "companion/Pet.hpp"

#include "companion/PinkCat.hpp"

#include "companion/ShibaInu.hpp"
#include "game/Game.hpp"

#include "game/Highscore.hpp"

#include "health/HealthBar.hpp"

#include "health/pBlock.hpp"

#include "health/pRow.hpp"

#include "pet-essentials/Coin.hpp"

#include "pet-essentials/Food.hpp"

#include "pet-essentials/Petting.hpp"

#include "pet-essentials/Poop.hpp"

#include "pet-essentials/Water.hpp"

#include "companion/Dog.hpp"

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