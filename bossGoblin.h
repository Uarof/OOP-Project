#ifndef BOSSGOBLIN_H
#define BOSSGOBLIN_H

#include "character.h"
#include "goblin.h"

class BossGoblin : public Goblin {
 private:
  int debuffDamage;
  int debuffCount;
 public:
  BossGoblin() {
    name = "BFG";
    level = 10;
    healthMax = 100;
    healthCurrent = 100;
    strength = 10;
    mana = 10;
    luck = 10;
    isAlive = true;
    debuffDamage = round(strength / 10);

    debuffCount = 0;
    }
  
  int enemyAttack() {
    int damage = 10;
    int specAttackChance = rand() % 100;
    if (specAttackChance >= 80) {
      debuffCount++;
    } else {
      int damage = strength;
      int lb = round(strength * 0.5);
      int ub = round(strength * 1.5);
      damage = rand() % (ub - lb + 1) + lb;
      double hit = (rand() % 100) / 100;
      // if (hit >= luck) {
      //   damage = 0;
      //   return damage;
      // }
    }
    damage += debuffCount * debuffDamage;
    return damage;
  }

  void setDebuffDamage(int debuffDamageIn) {
    debuffDamage = debuffDamageIn;
  }
  int getDebuffDamage() {
    return debuffDamage;
  }
  void setDebuffCount(int debuffCountIn) {
    debuffCount = debuffCountIn;
  }
  int getDebuffCount() {
    return debuffCount;
  }
};

#endif