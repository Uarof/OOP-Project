//inventory UI and functionality
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

void printInventory(Player* player) { //prints the in UI
  std::string selectedItem;
  int result = 0;
  item* inven = player->getInventory();
  std::cout << "\n< INVENTORY >\n";
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << ": " << (inven[i].getName());
    std::cout << std::endl;
  }
  
  item itemChoice = inven[result];
  while (result == 0) {
    std::cout << "Please select an Item (num): ";
    std::cin >> selectedItem;
    result = choiceUpToSix(selectedItem, 5);
    if (inven[result - 1].getName() == "[Empty Slot]") {
      result = 0;
      std::cout << "Invalid input\n";
    }
  }
  result -= 1;
  itemChoice = inven[result];
  
  if (itemChoice.getResetType() == false && itemChoice.getAttribute() == 0) { //selcet and consume a potion 
    player->setHealthCurrent(player->getHealth()); //reset the current health to max health (full heal)
  } else {
    int Att = itemChoice.getAttribute(); //finds attribute and assigns a incrase tipe based on the attribute
    switch(Att) {
      case 0:
        std::cout << player->getHealth();
        player->setHealth(itemChoice.getIncrease() + player->getHealth());
        player->setHealthCurrent(player->getHealth());
        std::cout << player->getHealth();
        player->removeItem(result);
        break;
      case 1:
        player->setStrength(itemChoice.getIncrease() + player->getStrength());
        player->removeItem(result);
        break;
      case 2:
        player->setMana(itemChoice.getIncrease() + player->getMana());
        player->removeItem(result);
        break;
      case 3:
        player->setLuck(itemChoice.getIncrease() + player->getLuck());
        player->removeItem(result);
        break;
    }
  }
}

#endif