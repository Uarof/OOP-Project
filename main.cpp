#include "files.h"

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
  Player* player = new Player(userName, userType);
  delete[] userInfo;

  bool gameDone = false;
  bool died = false;
  bool gameWon = false;

  // then terminal is cleared
  system("clear");

  std::cout << gameTitle;
  int difficulty = chooseDifficulty();

  int maxLevel = difficulty * 5;
  int currentLevel = 0;
  // Generation stage[(maxLevel)];  // creates either

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
    std::cout << gameTitle;
    std::cout << "\n";
    printCentred(player->getGameSession());

    if (currentLevel > maxLevel) {
      // BOSS
      system("clear");
      std::cout << gameTitle;
      std::cout << "\n";
      printCentred(player->getGameSession());
      std::cout << "\n";
      printCentred("BOSS\n");
      printCentred("|");
      printCentred("|");
      printCentred("|\n");
      printCentred("player\n");

      printCentred("You have encounterd the boss Goblins");
      printCentred("That's one Big F**cken Goblin!!!\n\n");

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

      executeEncounter(player, 3, currentLevel);
    } else {
      int encouter = createAndReturnPaths();
      executeEncounter(player, encouter, currentLevel);
    }

    if (currentLevel > maxLevel &&
        player->getIsAlive() == true) {  // win condition
      gameWon = true;
      gameDone = true;
    }

    if (player->getIsAlive() == false) {
      died = true;
      gameDone = true;
    }
    currentLevel++;
    player->setStage(currentLevel);
  }

  if (died == true) {
    deathScreen();
  }

  if (gameWon == true) {
    finishScreen();
  }
  delete player;
}
