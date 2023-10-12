#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

class Character {
 protected:
  int level;
  int healthMax;
  int healthCurrent;
  int strength;
  int mana;
  int luck;
  bool isAlive;

 public:
  Character() {
    level = 1;
    healthMax = 0;
    healthCurrent = healthMax;
    strength = 0;
    mana = 0;
    luck = 0;
    isAlive = true;
  }
  void setLevel(int levelIn) { level = levelIn; }
  int getLevel() { return level; }
  void setHealth(int healthIn) { healthMax = healthIn; }
  int getHealth() { return healthMax; }
  void setHealthCurrent(int healthCurrentIn) {
    healthCurrent = healthCurrentIn;
  }
  int getHealthCurrent() { return healthCurrent; }
  void setStrength(int strengthIn) { strength = strengthIn; }
  int getStrength() { return strength; }
  void setMana(int manaIn) { mana = manaIn; }
  int getMana() { return mana; }
  void setLuck(int luckIn) { luck = luckIn; }
  int getLuck() { return luck; }
  bool getIsAlive() { return isAlive; }
  void setIsAlive(bool isAliveIn) { isAlive = isAliveIn; }

  void display_Health() {
    int length = this->getHealthCurrent();
    char hashArray[length];
    for (int tempLength = 0; tempLength < length; tempLength++) {
      hashArray[tempLength] = '#';
    }
    for (int tempLength = 0; tempLength < length; tempLength++) {
      std::cout << hashArray[tempLength];
    }
  }
};

#endif