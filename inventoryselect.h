#ifndef INVENTORYSELECT_H
#define INVENTORYSELECT_H

#include <chrono>
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

void printInventory(Player* player) {
  std::string selectedItem = 0;
  int result = 0;
  potion* inven = player->get_inventory();
  std::cout << "\n< INVENTORY >\n";
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << ": " << inven[i];
    std::cout << std::endl;
  }
  std::cout << "Please select an Item";
  std::cin >> selectedItem;
  while (result == 0) {
    result = choiceUpToSix(selectedItem, 5);
  }
  potion itemChoice = inven[result];
  if (itemChoice.get_reset_type() == true)

}

#endif