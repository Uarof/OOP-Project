#ifndef BOSSGOBLIN_H
#define BOSSGOBLIN_H

#include "character.h"
#include "goblin.h"

class BossGoblin : public Goblin {
 private:
  int debuff_damage;
  int debuff_count;
 public:
  BossGoblin() {
    name = "BFG";
    level = 10;
    healthMax = 100;
    healthCurrent = 10;
    strength = 10;
    mana = 10;
    luck = 10;
    isAlive = true;
    debuff_damage = round(strength / 10);

    debuff_count = 0;
    }
  
  int enemy_attack() {
    int damage = 0;
    int spec_attack_chance = rand() % 100;
    if (spec_attack_chance >= 80) {
      debuff_count++;
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
    damage += debuff_count * debuff_damage;
    return damage;
  }

  void set_debuff_damage(int debuff_damage_in) {
    debuff_damage = debuff_damage_in;
  }
  int get_debuff_damage() {
    return debuff_damage;
  }
  void set_debuff_count(int debuff_count_in) {
    debuff_count = debuff_count_in;
  }
  int get_debuff_count() {
    return debuff_count;
  }
};

#endif