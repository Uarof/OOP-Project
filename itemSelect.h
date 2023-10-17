#ifndef ITEMSELECT_H
#define ITEMSELECT_H

#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <thread>

#include "bossGoblin.h"
#include "character.h"
#include "gameTitle.h"
#include "generation.h"
#include "goblin.h"
#include "item.h"
#include "player.h"
#include "potion.h"
#include "printCentred.h"

void itemSelect(Player* player) {
  // imports players name and game session from player vaiable
  std::string gameSession = player->getGameSession();
  std::string userName = player->getName();

  // clear terminal
  system("clear");

  // print game title
  std::cout << gameTitle;
  std::cout << "\n";

  // game session is printed in the centre
  printCentred(gameSession);

  // "Battle" is printed in the centre
  printCentred("- Item Select -");
  std::cout << "\n";

  // user is prompted to select an item
  std::cout
      << "\nA travelling merchant offers you his wears, what will you take?\n";

  // generating 3 random items with health restore bias
  int lb = ceil(0.25 * player->getLevel());
  int ub = ceil(0.5 * player->getLevel());
  int increase = rand() % (ub - lb + 1) + lb;

  int type1 = rand() % 3;
  int type2 = round((rand() % 30) / 10);
  int type3 = round((rand() % 300) / 100);

  potion p1(1, type1, increase);  // the fixed health pot
  potion p2(1, type2, increase);
  potion p3(1, type3, increase);

  int healthPotRatio = 3;
  int isHealthPot = rand() % healthPotRatio;  // 1/(healthPotRatio + 1) chance
                                              // of no health restore potion
  if (healthPotRatio - 1 > isHealthPot) {
    p1.setResetType(0);
    p1.setName("Health Restore Potion");
    p1.setAttribute(0);
  }

  // item options are printed
  std::cout << "\nITEMS:\n";
  std::cout << "1. " << p1.getName() << "\n";
  std::cout << "2. " << p2.getName() << "\n";
  std::cout << "3. " << p3.getName() << "\n\n";

  // accepts input and tests if input is valid or not
  // if the input is invalid, the user will be prompted again.
  // if valid, the item selection is acknowlegded
  bool correctInput = false;
  int selectedItem = 0;
  std::string choiceIn;
  int result = 0;
  while (result == 0) {
    std::cin >> choiceIn;
    result = choiceUpToSix(choiceIn, 3);
    if (choiceUpToSix(choiceIn, 3) == 0) {
      std::cout << "invalid input" << std::endl;
      result = 0;
    }
    selectedItem = (choiceUpToSix(choiceIn, 5));
  }

  switch (selectedItem) {
    case 1:
      std::cout << "\n"
                << userName << " took the " << p1.getName() << " and fled\n";
      player->addItem(p1);
      break;
    case 2:
      std::cout << "\n"
                << userName << " took the " << p2.getName() << " and fled\n";
      player->addItem(p2);
      break;
    case 3:
      std::cout << "\n"
                << userName << " took the " << p3.getName() << " and fled\n";
      player->addItem(p3);
      break;

    default:
      std::cout << "\n"
                << "Invalid item, please try again\n";
      break;
  }

  // user is prompted to press enter to continue
  std::cout << "\n";
  std::cout << "- Press Enter to Continue -\n";

  // the inputs of cleared, for compatibility
  std::cin.clear();
  std::fflush(stdin);

  // if enter is pressed, then
  if (std::cin.get() == '\n') {
    // terminal is cleared
    system("clear");
  }
}

#endif