#ifndef ITEMSELECT_H
#define ITEMSELECT_H

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <cmath>

#include "bossGoblin.h"
#include "character.h"
#include "generation.h"
#include "goblin.h"
#include "item.h"
#include "player.h"
#include "potion.h"
#include "printCentred.h"
#include "gameTitle.h"

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
  int increase1 = rand() % (ub - lb + 1) + lb;
  int increase2 = rand() % (ub - lb + 1) + lb;
  int increase3 = rand() % (ub - lb + 1) + lb;

  int type1 = rand() % 3;
  int type2 = round((rand() % 30) / 10);
  int type3 = round((rand() % 300) / 100);

  potion p1(1, type1, increase1); // the fixed health pot
  potion p2(1, type2, increase2);
  potion p3(1, type3, increase3);

  int healthPotRatio = 3;
  int isHealthPot = rand() % healthPotRatio; // 1/(healthPotRatio + 1) chance of no health restore potion
  if (isHealthPot > healthPotRatio - 1) {
    p1.set_reset_type(0);
    p1.set_attribute(0);
  }

  // item options are printed
  std::cout << "\nITEMS:\n";
  std::cout << "1. " << p1.get_name() << "\n";
  std::cout << "2. " << p2.get_name() << "\n";
  std::cout << "3. " << p3.get_name() << "\n\n";

  // accepts input and tests if input is valid or not
  // if the input is invalid, the user will be prompted again.
  // if valid, the item selection is acknowlegded
  bool correctInput = false;
  int selectedItem = 0;
  while (correctInput == false) {
    std::cin >> selectedItem;
    switch (selectedItem) {
      case 1:
        std::cout << "\n" << userName << " took the " << p1.get_name() << " and fled\n";
        player->add_item(p1);
        correctInput = true;
        break;
      case 2:
        std::cout << "\n" << userName << " took the " << p2.get_name() << " and fled\n";
        player->add_item(p2);
        correctInput = true;
        break;
      case 3:
        std::cout << "\n" << userName << " took the " << p3.get_name() << " and fled\n";
        player->add_item(p3);
        correctInput = true;
        break;

      default:
        std::cout << "\n"
                  << "Invalid item, please try again\n";
        break;
    }
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