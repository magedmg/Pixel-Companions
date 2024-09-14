#include <raylib.h>
#include <raymath.h>

#include <iostream>
using namespace std;

int main() {

  int windowWidth = 1000;
  int windowHeight = 700;

  InitWindow(windowWidth, windowHeight, "Pixel Companions");

  // Load and resize background image
  Image bgImage = LoadImage("resources/bg.png");
  ImageResize(&bgImage, windowWidth, windowHeight);
  Texture2D bgTexture = LoadTextureFromImage(bgImage);
  UnloadImage(bgImage); // Unload image after converting to texture

  // Load and resize standing cat images
  Texture2D standTextures[4];
  for (int i = 0; i < 4; i++) {
    const char *filename = TextFormat("resources/cat/1%d.png", i + 1);

    Image catImage = LoadImage(filename);
    ImageResize(&catImage, 85, 95);
    standTextures[i] = LoadTextureFromImage(catImage);
    UnloadImage(catImage); // Unload image after converting to texture
  }

  // Load and resize running cat images (right direction)
  Texture2D runRightTextures[6];
  for (int i = 0; i < 6; i++) {
    const char *filename = TextFormat("resources/cat/2%d.png", i + 1);

    Image catImage = LoadImage(filename);
    ImageResize(&catImage, 85, 95);
    runRightTextures[i] = LoadTextureFromImage(catImage);
    UnloadImage(catImage); // Unload image after converting to texture
  }

  // Load and resize running cat images (left direction)
  Texture2D runLeftTextures[6];
  for (int i = 0; i < 6; i++) {
    const char *filename = TextFormat("resources/cat/3%d.png", i + 1);

    Image catImage = LoadImage(filename);
    ImageResize(&catImage, 85, 95);
    runLeftTextures[i] = LoadTextureFromImage(catImage);
    UnloadImage(catImage); // Unload image after converting to texture
  }

  SetTargetFPS(60);

  Vector2 catPosition = {250, 480};
  Vector2 targetPosition = catPosition;
  int currentFrame = 0;     // Index of the current frame
  float frameSpeed = 0.1f;  // Speed at which frames change (seconds per frame)
  float frameTime = 0.0f;   // Time accumulator
  float moveSpeed = 100.0f; // Speed at which the cat moves (pixels per second)
  bool isRunning = false;   // Indicates whether the cat is running
  bool movingRight = true;  // Direction of movement (right by default)

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    // Check for mouse click and update target position
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      targetPosition = GetMousePosition();
      // Determine direction based on mouse position
      if (targetPosition.x > catPosition.x) {
        movingRight = true;
      } else if (targetPosition.x < catPosition.x) {
        movingRight = false;
      }
      isRunning = true; // Start running when the mouse is pressed
    }

    // Update frame time and change frame if needed
    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0f; // Reset frame time
      if (isRunning) {
        currentFrame = (currentFrame + 1) % 6; // Cycle through run frames
      } else {
        currentFrame = (currentFrame + 1) % 4; // Cycle through stand frames
      }
    }
    // Move the cat left or right towards the target position if running
    if (isRunning) {
      if (movingRight) {
        catPosition.x += moveSpeed * deltaTime;
        if (catPosition.x >= targetPosition.x) {
          catPosition.x = targetPosition.x;
          isRunning = false; // Stop running when the target is reached
        }
      } else {
        catPosition.x -= moveSpeed * deltaTime;
        if (catPosition.x <= targetPosition.x) {
          catPosition.x = targetPosition.x;
          isRunning = false; // Stop running when the target is reached
        }
      }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(bgTexture, 0, 0, WHITE);

    // Draw the appropriate texture based on the cat's state and direction
    if (isRunning) {
      if (movingRight) {
        DrawTexture(runRightTextures[currentFrame], (int)catPosition.x,
                    (int)catPosition.y, WHITE);
      } else {
        DrawTexture(runLeftTextures[currentFrame], (int)catPosition.x,
                    (int)catPosition.y, WHITE);
      }
    } else {
      DrawTexture(standTextures[currentFrame], (int)catPosition.x,
                  (int)catPosition.y, WHITE);
    }

    EndDrawing();
  }

  // Unload textures and close window
  UnloadTexture(bgTexture);
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
  CloseWindow();

  return 0;
}