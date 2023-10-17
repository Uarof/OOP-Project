//2nd level inheritance from Character class
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "goblin.h"
#include "item.h"
#include "potion.h"

class Player : public Character {
 private:
  std::string name;
  std::string type;
  item inventory[5];
  int stage;

 public:
  void setStage(int stageIn) { stage = stageIn; }
  int getStage() { return stage; }
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
  item* addItem(item toAdd) {
    for (int i = 0; i < 5; i++) {
      if (inventory[i].getName() == "[Empty Slot]") {
        inventory[i] = toAdd;
        break;
      }
    }
    return inventory;
  }
  item* removeItem(int position) {
    item blank;
    inventory[position] = blank;
    for (int i = position; i < 4; i++) {
      inventory[i] = inventory[i + 1];
    }
    inventory[4] = blank;
    return inventory;
  }
  
  item* getInventory() { return inventory; }
  std::string getGameSession() {
    std::string stageString = std::to_string(stage);
    std::string gameSession =
        "- " + name + " the " + type + ", stage: " + stageString + " -";
    return gameSession;
  }

  void playerAttack(Goblin* goblin, int attackpower) {
    std::cout << goblin->getName() << " the goblin took " << attackpower
              << " damage\n";
    int healthIn = goblin->getHealthCurrent() - attackpower;
    goblin->setHealthCurrent(healthIn);
    if (goblin->getHealthCurrent() <= 0) {
      goblin->setIsAlive(false);
      std::cout << "You defeated " << goblin->getName() << "!\n";
      std::cout << goblin->getName() << " perished!!\n";
      healthMax+=2;
      healthCurrent++;
      strength = strength * 1.5;
      mana = mana * 1.5;
      luck = luck * 1.5;
      level++;
      std::cout << "You leveled up!!! ";
    }
  }

  void playerTakeDamage(int damage) {
    healthCurrent = healthCurrent - damage;
    std::cout << std::endl;
    std::cout << name << " took " << damage << " damage!\n";
    if (healthCurrent <= 0) {
      isAlive = false;
      std::cout << name << " perished!!\n";
    }
  }
};

#endif