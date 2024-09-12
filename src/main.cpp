
#include <raylib.h>
#include <raymath.h>

#include <iostream>

int main() {
  Color darkBlue = {44, 44, 127, 255};

  Color white = {255, 255, 255, 0};

  Color transparent = {255, 255, 255, 0};

  InitWindow(600, 600, "Pixel Companion"); // size

  Image image =
      LoadImage("resources/backgroundimage.png"); // Loaded in CPU memory (RAM)
  Texture2D texture = LoadTextureFromImage(
      image); // Image converted to texture, GPU memory (VRAM)

  Image image1 = LoadImage("resources/dog.png"); // Loaded in CPU memory (RAM)
  Texture2D texture1 = LoadTextureFromImage(
      image1); // Image converted to texture, GPU memory (VRAM)

  SetTargetFPS(60); // fps
  // close icon is pressed or the esc key
  while (WindowShouldClose() == false) {
    ClearBackground(
        RAYWHITE); // create a background with a clear darkblue colour
    BeginDrawing();

    DrawTexture(
        texture, 0, 0,
        WHITE); // make sure to leave tint on white. does not work with blank
    DrawTexture(texture1, 0, 0, WHITE);
    EndDrawing();
  }

  UnloadTexture(texture); // Texture unloadin
  CloseWindow();          // closes the window

  return 0;
}