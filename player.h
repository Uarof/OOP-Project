#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "item.h"
#include "potion.h"
#include "goblin.h"

class Player : public Character {
 private:
  std::string name;
  std::string type;
  potion inventory[5];

 public:
  void setName(std::string nameIn) { name = nameIn; }
  std::string getName() { return name; }
  void setType(std::string typeIn) { type = typeIn; }
  std::string getType() { return type; }
  Player(std::string nameIn, std::string typeIn) {
    name = nameIn;
    type = typeIn;
    isAlive = true;
    level = 1;
    if (type == "Warrior") {
      healthMax = 8;
      strength = 8;
      mana = 1;
      luck = 0.5;
    } else if (type == "Wizard") {
      healthMax = 8;
      strength = 4;
      mana = 8;
      luck = 0.5;
    } else if (type == "Rouge") {
      healthMax = 5;
      strength = 10;
      mana = 1;
      luck = 0.3;
    } else if (type == "Paladin") {
      healthMax = 10;
      strength = 4;
      mana = 6;
      luck = 0.3;
    }
    healthCurrent = healthMax;

    potion blank;
    for (int i = 0; i < 5; i++) {
      inventory[i] = blank;
    }
  }
  potion* add_item(potion to_add) {
    for (int i = 0; i < 5; i++) {
      if (inventory[i].get_name() == "[Empty Slot]") {
        inventory[i] = to_add;
        break;
      }
    }
    return inventory;
  }
  potion* remove_item(int position) {
    potion blank;
    inventory[position] = blank;
    for (int i = position; i < 4; i++) {
      inventory[i] = inventory[i + 1];
    }
    inventory[4] = blank;
    return inventory;
  }
  int find_item(potion to_find) {
    int pos = 6;  // 6 is an error code for the fucker ain't here
    for (int i = 0; i < 5; i++) {
      if (inventory[i].get_name() == to_find.get_name()) {
        pos = i;
      }
    }
    return pos;
  }
  potion* get_inventory() {
    return inventory;
  }
  std::string getGameSession() {
    std::string gameSession = "- " + name + " the " + type + " -";
    return gameSession;
  }

  void playerattack(Goblin* goblin, int attackpower) {
    std::cout << goblin->getName() << " the goblin took " << attackpower
              << " damage\n";
    int healthIn = goblin->getHealthCurrent() - attackpower;
    goblin->setHealthCurrent(healthIn);
    if (goblin->getHealthCurrent() <= 0) {
      goblin->setIsAlive(false);
      std::cout << "You defeated " << goblin->getName() << "!\n";
      std::cout << goblin->getName() << " perished!!\n";
      healthMax = healthMax*1.5;
      strength = strength*1.5;
      mana = mana*1.5;
      luck = luck*1.5;
      level++;
      std::cout << "You leveled up!!! ";
    }
  }

  void playerTakeDamage(int damage) {
    healthCurrent = healthCurrent - damage;
    std::cout << name << " took " << damage << "!\n";
    if (healthCurrent <= 0) {
      isAlive = false;
      std::cout << name << " perished!!\n";
    }
  }
};

#endif