
#include <raylib.h>
#include <raymath.h>

#include <iostream>

int main() {
  Color darkBlue = {44, 44, 127, 255};

  std::cout << "hello \n\n";

  InitWindow(600, 600, "Pixel Companion"); // size
  SetTargetFPS(60);                        // fps
  // close icon is pressed or the esc key
  while (WindowShouldClose() == false) {
    BeginDrawing();

    ClearBackground(
        darkBlue); // create a background with a clear darkblue colour

    EndDrawing();
  }

  CloseWindow(); // closes the window

  return 0;
}