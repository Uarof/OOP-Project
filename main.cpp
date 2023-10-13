#include <iostream>

#include "character.h"
#include "generation.h"
#include "goblin.h"
#include "item.h"
#include "player.h"
#include "potion.h"
#include "ui.h"

int main() {
  // userInfo will store the pointer returned by gameIntro,
  // containing the users name and type
  std::string* userInfo;

  // gameIntro executes the game intro sequence,
  // includes finidng user name and type which are returned
  // in an array.
  userInfo = gameIntro();
  std::cout << gameTitle;
  std::string userName = userInfo[0];
  std::string userType = userInfo[1];
  Player player(userName, userType);
  Goblin* goblin;
  delete[] userInfo;

  bool gameDone = false;
  bool died = false;
  bool finished = false;

  // then terminal is cleared
  system("clear");
  
  std::cout << gameTitle;
  int difficulty = chooseDifficulty();

  int maxLevel = difficulty * 5;
  int currentLevel = 0;
  Generation stage[(maxLevel)];  // creates either

  // user is prompted to press enter to continue
  printCentred("-Press Enter to Continue-");

  // the inputs of cleared, for compatibility
  std::cin.clear();
  std::fflush(stdin);

  // if the user presses enter
  if (std::cin.get() == '\n') {
    // then terminal is cleared
    system("clear");
  }

  // main game while loop
  while (gameDone == false) {
    // then terminal is cleared
    system("clear");

    int encouter = mapDisplayReturnEncouterTypeValue(currentLevel);
    path_number_to_string(encouter);

    if (currentLevel > maxLevel || player.getIsAlive() == false) {
      gameDone = true;
    }
    if (gameDone && player.getIsAlive() == true) {
      finished = true;
    }
    if (gameDone && player.getIsAlive() == false) {
      died = true;
    }
    currentLevel++;
  }

  if (died == true) {
    deathScreen();
  }

  if (finished == true) {
    finishScreen();
  }
}
