
#include <raylib.h>
#include <raymath.h>

#include <iostream>

int main() {
  Color darkBlue = {44, 44, 127, 255};

  Color white = {255, 255, 255, 0};

  Color transparent = {255, 255, 255, 0};

  InitWindow(600, 600, "Pixel Companion"); // size

  Image bg_img = LoadImage("resources/backgroundimage.png"); // Loaded in CPU memory (RAM)
  Texture2D bg_texture = LoadTextureFromImage(
      bg_img); // Image converted to texture, GPU memory (VRAM)

// Apple image for hunger bar
  Image hunger_img = LoadImage("resources/apple.png"); // Loaded in CPU memory (RAM)
  ImageResize(&hunger_img, 50, 50);
  Texture2D hunger_texture = LoadTextureFromImage(
      hunger_img); // Image converted to texture, GPU memory (VRAM)

// Water image for thirst bar
  Image thirst_img = LoadImage("resources/water.png"); // Loaded in CPU memory (RAM)
  ImageResize(&thirst_img, 50, 50);
  Texture2D thirst_texture = LoadTextureFromImage(
      thirst_img); // Image converted to texture, GPU memory (VRAM)

// Heart image for happiness bar
  Image happiness_img = LoadImage("resources/heart.png"); // Loaded in CPU memory (RAM)
  ImageResize(&happiness_img, 50, 50);
  Texture2D happiness_texture = LoadTextureFromImage(
      happiness_img); // Image converted to texture, GPU memory (VRAM)

// Coin image for coin counter
  Image coin_img = LoadImage("resources/coin.png"); // Loaded in CPU memory (RAM)
  ImageResize(&coin_img, 50, 50);
  Texture2D coin_texture = LoadTextureFromImage(
      coin_img); // Image converted to texture, GPU memory (VRAM)


// Pet image
  Image corgi_img = LoadImage("resources/Corgi.png"); // Loaded in CPU memory (RAM)
  ImageResize(&corgi_img, 110, 120);
  Texture2D corgi_texture = LoadTextureFromImage(
      corgi_img); // Image converted to texture, GPU memory (VRAM)

  SetTargetFPS(60); // fps
  // close icon is pressed or the esc key
  while (WindowShouldClose() == false) {
    ClearBackground(
        RAYWHITE); // create a background with a clear darkblue colour
    BeginDrawing();

    DrawTexture(
        bg_texture, 0, 0,
        WHITE); // make sure to leave tint on white. does not work with blank
    DrawTexture(corgi_texture, 250, 400, WHITE);
    DrawTexture(hunger_texture, 20, 20, WHITE);
    DrawTexture(thirst_texture, 20, 80, WHITE);
    DrawTexture(happiness_texture, 20, 140, WHITE);
    DrawTexture(coin_texture, 20, 250, WHITE);
    EndDrawing();
  }

  UnloadTexture(bg_texture); // Texture unloadin
  CloseWindow();          // closes the window

  return 0;
}