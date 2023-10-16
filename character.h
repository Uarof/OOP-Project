#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <cmath>

class Character {
 protected:
  int level;
  int healthMax;
  int healthCurrent;
  int strength;
  int mana;
  double luck;
  bool isAlive;

 public:
  Character() {
    level = 0;
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
  void setLuck(double luckIn) { luck = luckIn; }
  double getLuck() { return luck; }
  bool getIsAlive() { return isAlive; }
  void setIsAlive(bool isAliveIn) { isAlive = isAliveIn; }

  void take_damage(int damage) {
    healthCurrent -= damage;
  }
  
  void display_Health() {
    for (int i = 0; i < this->healthCurrent; i++) {
      std::cout << "#";
    }
  }
};

#endif