#include "DogX.hpp"
#include <raylib.h>

DogX::DogX() {
  // Initial position
  position = {250, 480};

  // Load all the images for left and right movements, as well as standing still
  for (int i = 0; i < 4; i++) {
    Image catImage = LoadImage(TextFormat("resources/cat/1%d.png", i + 1));
    ImageResize(&catImage, 85, 95);
    standTextures[i] = LoadTextureFromImage(catImage);
    UnloadImage(catImage); // Unload image after converting to texture
  }

  for (int i = 0; i < 6; i++) {
    Image catImage = LoadImage(TextFormat("resources/cat/2%d.png", i + 1));
    ImageResize(&catImage, 85, 95);
    runRightTextures[i] = LoadTextureFromImage(catImage);
    UnloadImage(catImage); // Unload image after converting to texture
  }
  for (int i = 0; i < 6; i++) {
    Image catImage = LoadImage(TextFormat("resources/cat/3%d.png", i + 1));
    ImageResize(&catImage, 85, 95);
    runLeftTextures[i] = LoadTextureFromImage(catImage);
    UnloadImage(catImage); // Unload image after converting to texture
  }

  // Initialise variables for the cat

  isRunning = false; // Indicates whether the cat is running
  movingRight = true;
  targetPosition = position;
  currentFrame = 0;   // Index of the current frame
  frameSpeed = 0.1f;  // Speed at which frames change (seconds per frame)
  frameTime = 0.0f;   // Time accumulator
  moveSpeed = 100.0f; // Speed at which the cat moves (pixels per second)
}

void DogX::Draw() {
  float deltaTime = GetFrameTime();
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
      position.x += moveSpeed * deltaTime;
      if (position.x >= targetPosition.x) {
        position.x = targetPosition.x;
        isRunning = false; // Stop running when the target is reached
      }
    } else {
      position.x -= moveSpeed * deltaTime;
      if (position.x <= targetPosition.x) {
        position.x = targetPosition.x;
        isRunning = false; // Stop running when the target is reached
      }
    }
  }
  // Draw the appropriate texture based on the cat's state and direction
  if (isRunning) {
    if (movingRight) {
      DrawTexture(runRightTextures[currentFrame], (int)position.x,
                  (int)position.y, WHITE);
    } else {
      DrawTexture(runLeftTextures[currentFrame], (int)position.x,
                  (int)position.y, WHITE);
    }
  } else {
    DrawTexture(standTextures[currentFrame], (int)position.x, (int)position.y,
                WHITE);
  }
}

void DogX::Update() {

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    targetPosition = GetMousePosition();
    // Determine direction based on mouse position
    if (targetPosition.x > position.x) {
      movingRight = true;
    } else if (targetPosition.x < position.x) {
      movingRight = false;
    }
    isRunning = true; // Start running when the mouse is pressed
  }
}

DogX::~DogX() {
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
}