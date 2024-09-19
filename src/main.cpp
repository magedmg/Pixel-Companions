#include <raylib.h>
#include <raymath.h>

#include <iostream>
using namespace std;

void createAnimation(int, int[2], Texture2D*, const char*);
void createImage(int[2], Texture2D&, const char*);

int main() {
  // DECLARE WINDOW SIZE
  int windowSize[2] = {1000, 700};
  InitWindow(windowSize[0], windowSize[1], "Pixel Companions");
  SetTargetFPS(60);

  // IMPORT ELEMENTS (BG & SPRITES)
  int catSize[2] = {85, 95};
  int fishSize[2] = {55, 65};
  int buttonSize[2] = {95, 95};

  Texture2D bgTexture;
  createImage(windowSize, bgTexture, "bg");

  Texture2D fishTexture;
  createImage(fishSize, fishTexture, "food/fish");

  Texture2D foodbuttonTexture;
  createImage(buttonSize, foodbuttonTexture, "buttons/foodbutton");
	Texture2D foodbuttonClickedTexture;
	createImage(buttonSize, foodbuttonClickedTexture, "buttons/foodbuttonclicked");

  Texture2D waterbuttonTexture;
  createImage(buttonSize, waterbuttonTexture, "buttons/waterbutton");
	Texture2D waterbuttonClickedTexture;
	createImage(buttonSize, waterbuttonClickedTexture, "buttons/waterbuttonclicked");

  Texture2D standTextures[4];
  createAnimation(4, catSize, standTextures, "cat/1");

  Texture2D runRightTextures[6];
  createAnimation(6, catSize, runRightTextures, "cat/2");

  Texture2D runLeftTextures[6];
  createAnimation(6, catSize, runLeftTextures, "cat/3");

  // DEFINE VARIABLES TO USE IN LOOP
  Vector2 catPosition = {250, 480};
  Vector2 targetPosition = catPosition;
  int curFrame = 0;
  float frameSpeed = 0.1f;
  float frameTime = 0.0f;
  float moveSpeed = 100.0f;
  bool isRunning = false;
  bool movingRight = true;

  Vector2 foodPosition = {0, -100};
  bool foodFalling = false;
  float foodSpeed = 200.0f;
  Rectangle foodButtonRect = {870, 16, (float)buttonSize[0],
                              (float)buttonSize[1]};
	bool isfoodbuttonPressed = false;

  Rectangle waterButtonRect = {750, 16, (float)buttonSize[0],
                              (float)buttonSize[1]};
	bool iswaterbuttonPressed = false;

  // GAME LOOP
  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    // 1. Event Handling & Updating Positions
    // FEEDING PART
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && foodFalling == false) {
      Vector2 mousePosition = GetMousePosition();

      if (CheckCollisionPointRec(mousePosition, foodButtonRect)) {
        isfoodbuttonPressed = true;

        // random place for food falling
        foodPosition.x = catPosition.x + (float)GetRandomValue(-300, 300);
        while (foodPosition.x < 0 || foodPosition.x > 950) {
          foodPosition.x = catPosition.x + (float)GetRandomValue(-300, 300);
        }
        foodPosition.y = 0;
        foodFalling = true;

        targetPosition.x = foodPosition.x;
        if (targetPosition.x > catPosition.x) {
					movingRight = true;
				} else {
					movingRight = false;
				}
        isRunning = true;
        curFrame = 0;
      }
    } else {
      isfoodbuttonPressed = false;
    }

    // GIVING WATER PART
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && foodFalling == false) {
      Vector2 mousePosition = GetMousePosition();

      if(CheckCollisionPointRec(mousePosition, waterButtonRect)) {
        iswaterbuttonPressed = true;
      }
    } else {
      iswaterbuttonPressed = false;
    }

    // FOOD FALLING PART
		if (foodFalling) {
      foodPosition.y += foodSpeed * deltaTime;
      if (foodPosition.y >= 480) {
        foodFalling = false;
      }
    }

    frameTime += deltaTime;
    if (frameTime >= frameSpeed) {
      frameTime = 0.0f;
      if (isRunning) {
        curFrame = (curFrame + 1) % 6;
      } else {
        curFrame = (curFrame + 1) % 4;
      }
    }

    // CAT RUNNING PART
    if (isRunning) {
      if (movingRight) {
        catPosition.x += moveSpeed * deltaTime;
        if (catPosition.x >= targetPosition.x) {
          catPosition.x = targetPosition.x;
          isRunning = false;
					curFrame = 0;
        }
      } else {
        catPosition.x -= moveSpeed * deltaTime;
        if (catPosition.x <= targetPosition.x) {
          catPosition.x = targetPosition.x;
          isRunning = false;
					curFrame = 0;
        }
      }
    }

    // 2. Drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(bgTexture, 0, 0, WHITE);

		if (foodFalling) {
      DrawTexture(fishTexture, (int)foodPosition.x, (int)foodPosition.y, WHITE);
    }

    if (isRunning) {
      if (movingRight) {
        DrawTexture(runRightTextures[curFrame], (int)catPosition.x, (int)catPosition.y, WHITE);
      } else {
        DrawTexture(runLeftTextures[curFrame], (int)catPosition.x, (int)catPosition.y, WHITE);
      }
    } else {
      DrawTexture(standTextures[curFrame], (int)catPosition.x, (int)catPosition.y, WHITE);
    }

    if (isfoodbuttonPressed) {
			DrawTexture(foodbuttonClickedTexture, 870, 16, WHITE);
		} else {
			DrawTexture(foodbuttonTexture, 870, 16, WHITE);
		}

    if (iswaterbuttonPressed) {
			DrawTexture(waterbuttonClickedTexture, 750, 16, WHITE);
		} else {
			DrawTexture(waterbuttonTexture, 750, 16, WHITE);
		}

    EndDrawing();
  }

  // UNLOAD TEXTURES
  UnloadTexture(bgTexture);
  for (int i = 0; i < 4; i++) {
    UnloadTexture(standTextures[i]);
  }
  for (int i = 0; i < 6; i++) {
    UnloadTexture(runRightTextures[i]);
    UnloadTexture(runLeftTextures[i]);
  }
  UnloadTexture(fishTexture);
  UnloadTexture(foodbuttonTexture);
  UnloadTexture(foodbuttonClickedTexture);
  UnloadTexture(waterbuttonTexture);
  UnloadTexture(waterbuttonClickedTexture);

  CloseWindow();
  return 0;
}

void createAnimation(int numLoop, int sizes[2], Texture2D* textures,
                     const char* path) {
  for (int i = 0; i < numLoop; i++) {
    const char* filename = TextFormat("resources/%s%d.png", path, i + 1);
    Image targetImage = LoadImage(filename);
    ImageResize(&targetImage, sizes[0], sizes[1]);
    textures[i] = LoadTextureFromImage(targetImage);
    UnloadImage(targetImage);
  }
}

void createImage(int sizes[2], Texture2D& ImgTexture, const char* path) {
  const char* filename = TextFormat("resources/%s.png", path);
  Image targetImage = LoadImage(filename);
  ImageResize(&targetImage, sizes[0], sizes[1]);
  ImgTexture = LoadTextureFromImage(targetImage);
  UnloadImage(targetImage);
}
