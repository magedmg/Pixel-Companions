

#include "Game.hpp"

#include <ostream>
#include <raylib.h>

#include <iostream>
#include <string>

Game::Game() {
  // Load and resize background image
  bgImage = LoadImage("../resources/bg.png");
  ImageResize(&bgImage, windowWidth, windowHeight);
  bgImageTexture = LoadTextureFromImage(bgImage);

  // Load health bar image and resize it
  healthBarImage = LoadImage("../resources/health bar.png");
  ImageResize(&healthBarImage, 300, 40);
  healthBarTexture = LoadTextureFromImage(healthBarImage);

  // Load fish hunger image and resize it
  hungerImage = LoadImage("../resources/food/fish.png");
  ImageResize(&hungerImage, 30, 30);
  hungerTexture = LoadTextureFromImage(hungerImage);

  // Load water image and resize it
  waterImage = LoadImage("../resources/water.png");
  ImageResize(&waterImage, 30, 30);
  waterTexture = LoadTextureFromImage(waterImage);

  // Load heart happiness image and resize it
  happinessImage = LoadImage("../resources/happiness.png");
  ImageResize(&happinessImage, 30, 30);
  happinessTexture = LoadTextureFromImage(happinessImage);

  // Coin in the menu
  coinBarImage = LoadImage("../resources/Coins/c1.png");
  ImageResize(&coinBarImage, 35, 40);
  coinBarTexture = LoadTextureFromImage(coinBarImage);

  // death background image
  deathbgImage = LoadImage("../resources/deathbg.png");
  ImageResize(&deathbgImage, 600, 350);
  deathbgTexture = LoadTextureFromImage(deathbgImage);

  startButton = LoadImage("../resources/startButton.png");
  ImageResize(&startButton, 300, 200);
  startTexture = LoadTextureFromImage(startButton);

  UIpets = LoadImage("../resources/breedchoosing.png");
  ImageResize(&UIpets, windowWidth, windowHeight);
  UIpetsTexture = LoadTextureFromImage(UIpets);

  // Instructions
  instructions = LoadImage("../resources/instruction.png");
  ImageResize(&instructions, windowWidth, windowHeight);
  instructionsTexture = LoadTextureFromImage(instructions);

  instructionsButton = LoadImage("../resources/instructions-button.png");
  ImageResize(&instructionsButton, 200, 150);
  instructionsButtonTexture = LoadTextureFromImage(instructionsButton);
  UIstate = 0;
  instructionsRect = {
      static_cast<float>(windowWidth / 3 - instructionsButton.width / 2), 560,
      200, 150};

  // Declare the rectangles for the pets on the screen
  petRects[0] = {static_cast<float>((875 / 4) - 65), 300, 140, 200};
  petRects[1] = {static_cast<float>((875 / 4) * 2 - 35), 300, 170, 200};
  petRects[2] = {static_cast<float>((875 / 4) * 3 + 20), 300, 170, 200};

  DrawRectangle(875 / 4 - 65, 300, 140, 200, RED);
  DrawRectangle((875 / 4) * 2 - 35, 300, 170, 200, RED);
  DrawRectangle((875 / 4) * 3 + 20, 300, 170, 200, RED);

  petOptions[0] = ("shibaInu");
  petOptions[1] = ("pinkCat");
  petOptions[2] = ("greyCat");

  boxLocation = -200;

  gameState = 0;
  playingState = 0;
}

void Game::updateAll() {
  // updates game whether it is in starting UI or in an active game
  switch (gameState) {
  case 0:
    startUI();
    UITimer = GetTime();
    break;

  case 1:
    activeGame();
  }
}

void Game::startUI() {
  // can be either a selection screen or instructions screen
  switch (UIstate) {
  case 0:
    pickPet();
    break;
  case 1:
    instructionsUI();
    break;
  }
}

void Game::instructionsUI() {
  // displays instructions
  DrawTextureV(instructionsTexture, {0, 0}, WHITE);
  DrawText("Pixel Companion", 300, 20, 50, WHITE);

  // If the user hits the exit button go back the UI menu
  Rectangle exitButton{100, 100, 115, 80};
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    Rectangle mouseRect{GetMousePosition().x, GetMousePosition().y, 1, 1};
    if (CheckCollisionRecs(mouseRect, exitButton)) {
      UIstate = 0;
    }
  }
}

void Game::pickPet() {

  DrawTextureV(UIpetsTexture, {0, 0}, WHITE);
  DrawText("Pixel Companion", 300, 20, 50, WHITE);

  DrawTextureV(
      instructionsButtonTexture,
      {static_cast<float>(windowWidth / 3 - instructionsButton.width / 2), 560},
      WHITE);

  // displays current highscores for each pet type
  DrawText(highscore.getShibaScore().c_str(), 180, 500, 40, GRAY);
  DrawText(highscore.getPinkCatScore().c_str(), 470, 500, 40, GRAY);
  DrawText(highscore.getGreyCatScore().c_str(), 750, 500, 40, GRAY);

  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    Rectangle mouseRect{GetMousePosition().x, GetMousePosition().y, 1, 1};
    for (int i = 0; i < 3; i++) {
      if (CheckCollisionRecs(mouseRect, petRects[i])) {
        // if mouse clicks any pet, select that pet
        petBreed = petOptions[i];
        boxLocation = i;
      }
    }
    // Check to see if the game should start
    if (petBreed != "") {
      Rectangle startRect{
          static_cast<float>((windowWidth / 3) * 2 - startButton.width / 2),
          560, 300, 200};
      if (CheckCollisionRecs(startRect, mouseRect)) {
        createPet(petBreed);
        gameState = 1;
      }
    }

    // Check if the player has clicked the instructions button
    if (CheckCollisionRecs(mouseRect, instructionsRect)) {
      UIstate = 1;
      petBreed = "";      // Unselect the pet
      boxLocation = -200; // reset the box location
    }
  }

  DrawRectangle(((865 / 4) * (boxLocation) + 70 * boxLocation + 110), 300, 20,
                20, YELLOW);

  // Draws the button on the screen if a pet has been picked
  if (petBreed != "") {
    DrawTextureV(
        startTexture,
        {static_cast<float>((windowWidth / 3) * 2 - startButton.width / 2),
         530},
        WHITE);
  }
}

// game is either currently being played, or player has died
void Game::activeGame() {
  switch (playingState) {
  case 0:
    playingGame();
    break;

  case 1:
    deathScreen();
    break;
  }
}

// when the game is actually being played
void Game::playingGame() {
  int scoreTimer = GetTime() - UITimer; // current time elapsed in seconds
  DrawTextureV(bgImageTexture, {0, 0}, WHITE);
  DrawText(std::to_string(coinCounter).c_str(), 915, 655, 30, WHITE);
  DrawText(std::to_string(scoreValue + scoreTimer).c_str(), 30, 648, 50, WHITE);

  // display status values
  DrawText(std::to_string(currentPet->currentHunger).c_str(), 370, 20, 30, RED);
  DrawTextureV(hungerTexture, {330, 20}, WHITE);

  DrawText(std::to_string(currentPet->currentThirst).c_str(), 500, 20, 30,
           BLUE);
  DrawTextureV(waterTexture, {460, 20}, WHITE);

  // display current pet level
  DrawText("LVL ", 13, 75, 40, BLACK);
  DrawText(std::to_string(currentPet->level).c_str(), 106, 75, 40, BLACK);

  // only show happiness status if pet is a cat
  if (currentPet->petType == "cat") {
    DrawText(std::to_string(currentPet->currentHappiness).c_str(), 630, 20, 30,
             PINK);
    DrawTextureV(happinessTexture, {590, 20}, WHITE);
  }

  // displays cost for food
  DrawTextureV(coinBarTexture, {885, 130}, WHITE);
  DrawText("2", 930, 135, 35, WHITE);

  // displays cost for water
  DrawTextureV(coinBarTexture, {770, 130}, WHITE);
  DrawText("1", 815, 135, 35, WHITE);

  flag = 0;

  // Water
  water.draw();
  if (petAlive) {
    water.update();
    currentPet->Poo1();
  }

  currentPet->Draw();

  // draw poops
  for (int i = 0; i < currentPet->currentPooCount; i++) {
    currentPet->poos[i]->Draw();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Rectangle mouseRect = {mousePos.x, mousePos.y, 1, 1};

    Rectangle collisionRect = {mousePos.x, mousePos.y, 5, 5};
    for (int i = 0; i < currentPet->currentPooCount; i++) {
      // if poop is clicked, deactivate the poop and award points
      if (CheckCollisionRecs(currentPet->poos[i]->getRect(), collisionRect)) {
        currentPet->poos[i]->deactivate();
        scoreValue += 30;
        flag = 1;
      }
    }

    if (currentPet->petType == "cat") {
      // Checks if the pet has been petted
      if (CheckCollisionRecs(mouseRect, currentPet->getRect())) {
        if (GetTime() - lastTimePetted > 4) {
          pet.Update(currentPet->position);
          lastTimePetted = GetTime(); // reset the last time petted
          if (currentPet->currentHappiness + 25 > 100) {
            // add to happiness status when petted
            currentPet->currentHappiness = 100;
          } else {
            currentPet->currentHappiness += 25;
          }
        }
        flag = 1; // so that the cat doesnt move
      }
    }
    // If the user clicks the food and water buttons dont move the pet
    if (CheckCollisionRecs(mouseRect, food.foodButtonRect) ||
        CheckCollisionRecs(mouseRect, water.waterButtonRect)) {
      flag = 1;
    }
  }

  if (flag == 0) {
    currentPet->Update();
  }

  pet.Draw();

  currentPet->Draw();
  // draw health bar and coins
  DrawTextureV(healthBarTexture, {10, 10}, WHITE);
  DrawTextureV(coinBarTexture,
               {static_cast<float>(windowWidth - coinBarImage.width) - 20,
                static_cast<float>(windowHeight - coinBarImage.height) - 10},
               WHITE);

  if (petAlive) {
    loadCoins(); // spawns coins randomly

    for (auto &coin : coins) {
      coin.Draw();
    }

    checkCollisions(); // check for any collisions ingame
  }

  // Drawing food on the screen and updating it each frame
  food.draw();
  if (petAlive) {
    food.update(currentPet->position, currentPet->targetPosition,
                currentPet->isRunning, currentPet->movingRight);
  }
  // Health
  health.Draw();

  // if status bars are not replenished, deplete them
  currentPet->updateStatus();

  // if any status bar is 0, take damage every second the status bar is 0
  if (currentPet->currentHappiness == 0 || currentPet->currentHunger == 0 ||
      currentPet->currentThirst == 0) {
    if (GetTime() - lastTimeDamaged > 1.5) {
      for (int i = 0; i < 5; i++) {
        health.takeDamage(1);
      }
      lastTimeDamaged = GetTime();
      // when health is 0, trigger pet death, stop everything and save highscore
      // if appropriate
      if (health.getHealth() == 0) {
        if (petAlive == true) {
          petAlive = false;
          currentPet->isRunning = false;
          currentPet->isDead = true;
          water.drink();
          highscore.addHighscore((scoreValue + scoreTimer), petBreed);
          endingTimer = GetTime();
          timeTracker = GetTime();
          endCounter = 3;
          playingState = 1; // send to ending screen
        }
      }
    }
  } else {
    // heal over time if status bars are not 0
    if (GetTime() - lastTimeHealed > 2) {
      for (int i = 0; i < 5; i++) {
        health.healDamage(1);
      }
      lastTimeHealed = GetTime();
    }
  }
}

void Game::loadCoins() {
  if (GetTime() - lastCoinTime >= randomCoinInterval) {
    lastCoinTime = GetTime(); // Reset the last time a coin was spawned
    randomCoinInterval =
        GetRandomValue(5, 10); // Get a new interval for the next coin to spawn
    float randomSpawn = GetRandomValue(
        20, 980); // set to float so that it can be passed in the pushback

    coins.push_back(Coin({randomSpawn, 525}));
  }
}

void Game::checkCollisions() {
  for (auto &coin : coins) { // if pet touches with coin, consume coin
    if (CheckCollisionRecs(coin.getRect(), currentPet->getRect())) {
      if (coin.collision == false) {
        coinCounter += 1;
        scoreValue += 20;
      }
      coin.collision = true;
      coin.collisionTime = GetTime();
    }
  }

  // if pet rectangle collides with water bowl rectangle, empty the water bowl
  if (CheckCollisionRecs(water.getRect(), currentPet->getRect())) {
    water.drink();
    currentPet->lastDrankTime = GetTime();
    if (currentPet->currentThirst + 25 > 100) {
      currentPet->currentThirst = 100;
    } else {
      currentPet->currentThirst += 25;
    }
  }

  // if pet rectangle collides with fish rectangle, consume fish
  if (CheckCollisionRecs(food.getRect(), currentPet->getRect())) {
    food.eat();
    currentPet->lastFedTime = GetTime();
    if (currentPet->currentHunger + 50 > 100) {
      currentPet->currentHunger = 100;
    } else {
      currentPet->currentHunger += 50;
    }
  }
}

void Game::createPet(std::string petBreed) {

  //  creates pet breed
  if (petBreed == "pinkCat") {
    currentPet = new PinkCat();
  } else if (petBreed == "greyCat") {
    currentPet = new GreyCat();
  } else if (petBreed == "shibaInu") {
    currentPet = new ShibaInu();
  }
  Reset();
}

void Game::Reset() {
  // Clear the coins on screen
  auto it = coins.begin();
  while (it != coins.end()) {

    it = coins.erase(it);
  }

  // Reset the health
  health.healDamage(97);

  randomCoinInterval = GetRandomValue(5, 10);
  lastCoinTime = GetTime();
  lastTimeDamaged = GetTime();
  lastTimeHealed = GetTime();
  lastTimePetted = GetTime();

  coinCounter = 0;
  scoreValue = 0;

  food.getCoins(&coinCounter);
  water.getCoins(&coinCounter);

  levelText = "LVL ";

  petAlive = true;

  Food food;
  Water water;
  HealthBar health;

  gameState = 0;
}

void Game::deathScreen() {
  DrawTextureV(bgImageTexture, {0, 0}, WHITE);

  // display current pet level
  DrawText("LVL ", 13, 75, 40, BLACK);
  DrawText(std::to_string(currentPet->level).c_str(), 106, 75, 40, BLACK);

  currentPet->Draw(); // draw dead pet

  // keeps track of seconds remaining until deathscreen closes
  if (GetTime() - timeTracker >= 1) {
    endCounter--;
    timeTracker = GetTime();
  }

  DrawTextureV(deathbgTexture, {200, 60}, WHITE);
  DrawText("You died!", 350, 170, 70, WHITE);
  DrawText("Returning in", 320, 240, 50, GRAY);
  DrawText(std::to_string(endCounter).c_str(), 650, 240, 50, GRAY);

  // if 3 seconds have passed, switch back to starting screen
  if (GetTime() - endingTimer >= 5) {
    playingState = 0;
    gameState = 0;
    delete currentPet;
  }
}
