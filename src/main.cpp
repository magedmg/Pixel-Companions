#include <ostream>
#include <raylib.h>
#include <raymath.h>

#include <iostream>

int main() {
  Color darkBlue = {44, 44, 127, 255};
  Color white = {255, 255, 255, 0};
  Color transparent = {255, 255, 255, 0};

  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  InitWindow(screenWidth, screenHeight, "Pixel Companions");
  ToggleFullscreen();

  Image bg_img =
      LoadImage("resources/rename.png"); // Loaded in CPU memory (RAM)

  ImageResize(&bg_img, 1440, 900);
  Texture2D bg_texture = LoadTextureFromImage(
      bg_img); // Image converted to texture, GPU memory (VRAM)

  Image corgi_img =
      LoadImage("resources/Corgi.png"); // Loaded in CPU memory (RAM)
  ImageResize(&corgi_img, 110, 120);
  Texture2D corgi_texture = LoadTextureFromImage(
      corgi_img); // Image converted to texture, GPU memory (VRAM)

  SetTargetFPS(60); // fps
  // close icon is pressed or the esc key
  while (!WindowShouldClose()) {
    ClearBackground(BLANK); // create a background with a clear darkblue colour
    BeginDrawing();

    DrawTexture(
        bg_texture, 0, 0,
        WHITE); // make sure to leave tint on white. does not work with blank
    DrawTexture(corgi_texture, 250, 400, WHITE);
    EndDrawing();
  }

  UnloadTexture(bg_texture); // Texture unloadin
  CloseWindow();             // closes the window

  return 0;
}