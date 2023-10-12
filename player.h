#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "item.h"

class Player : public Character {
 private:
  std::string name;
  std::string type;
  item inventory[5];

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
      luck = 5;
    } else if (type == "Wizard") {
      healthMax = 8;
      strength = 4;
      mana = 8;
      luck = 5;
    } else if (type == "Rouge") {
      healthMax = 5;
      strength = 10;
      mana = 1;
      luck = 3;
    } else if (type == "Paladin") {
      healthMax = 10;
      strength = 4;
      mana = 6;
      luck = 3;
    }
    healthCurrent = healthMax;

    item blank;
    for (int i = 0; i < 5; i++) {
      inventory[i] = blank;
    }


  }
  item* add_item(item to_add) {
    for (int i = 0; i < 5; i++) {
      if (inventory[i].get_name() == "[Empty Slot]") {
        inventory[i] = to_add;
      }
    }
    return inventory;
  }
  item* remove_item(int position) {
    item blank;
    inventory[position] = blank;
    for (int i = position; i < 4; i++) {
      inventory[i] = inventory[i + 1];
    }
    inventory[4] = blank;
    return inventory;
  }
  int find_item(item to_find) {
    int pos = 6; // 6 is an error code for the fucker ain't here
    for (int i = 0; i < 5; i++) {
      if (inventory[i].get_name() == to_find.get_name()) {
        pos = i;
      }
    }
    return pos;
  }
  std::string getGameSession() {
    std::string gameSession = "- " + name + " the " + type + " -";
    return gameSession;
  }
};

#endif