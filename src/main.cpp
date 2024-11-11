#include <raylib.h>
#include <raymath.h>

#include "companion/Cat.hpp"
#include "companion/Cat.cpp"

#include "companion/GreyCat.hpp"
#include "companion/GreyCat.cpp"

#include "companion/Pet.hpp"
#include "companion/Pet.cpp"

#include "companion/PinkCat.hpp"
#include "companion/PinkCat.cpp"

#include "companion/ShibaInu.hpp"
#include "companion/ShibaInu.cpp"
#include "game/Game.hpp"
#include "game/Game.cpp"

#include "health/HealthBar.hpp"
#include "health/HealthBar.cpp"

#include "health/pBlock.hpp"
#include "health/pBlock.cpp"

#include "health/pRow.hpp"
#include "health/pRow.cpp"


#include "pet-essentials/Coin.hpp"
#include "pet-essentials/Coin.cpp"

#include "pet-essentials/Food.hpp"
#include "pet-essentials/Food.cpp"

#include "pet-essentials/Petting.hpp"
#include "pet-essentials/Petting.cpp"

#include "pet-essentials/Poop.hpp"
#include "pet-essentials/Poop.cpp"

#include "pet-essentials/Water.hpp"
#include "pet-essentials/Water.cpp"

#include "companion/Dog.hpp"
#include "companion/Dog.cpp"

int main() {
  //SetTraceLogLevel(
      //LOG_WARNING); // doesnt print out anything except errors in terminal

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