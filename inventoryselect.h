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
  std::string selectedItem;
  int result = 0;
  potion* inven = player->get_inventory();
  std::cout << "\n< INVENTORY >\n";
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << ": " << (inven[i].get_name());
    std::cout << std::endl;
  }
  
  potion itemChoice = inven[result];
  while (result == 0) {
    std::cout << "Please select an Item (num)";
    std::cin >> selectedItem;
    result = choiceUpToSix(selectedItem, 5);
    if (inven[result - 1].get_name() == "[Empty Slot]") {
      result = 0;
      std::cout << "Invalid input";
    }
  }
  result =- 1;
  
  if (itemChoice.get_reset_type() == true && itemChoice.get_attribute() == 0) {
    player->setHealthCurrent(player->getHealth());
  } else {
    int Att = itemChoice.get_attribute();
    switch(Att) {
      case 0:
        player->setHealth(itemChoice.get_increase());
        player->remove_item(result);
        break;
      case 1:
        player->setStrength(itemChoice.get_increase());
        player->remove_item(result);
        break;
      case 2:
        player->setMana(itemChoice.get_increase());
        player->remove_item(result);
        break;
      case 3:
        player->setLuck(itemChoice.get_increase());
        player->remove_item(result);
        break;
    }
  }
}

#endif