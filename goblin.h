//goblin class is the 2nd level inheritance of the Character inheritance tree 
//gobiln takes in a level and scales it's stats based on the stage
#ifndef GOBLIN_H
#define GOBLIN_H

#include "character.h"
#include <cmath>

class Goblin : public Character {
 protected:
  std::string name;
  int index;

 public:
  void setName(std::string nameIn) { name = nameIn; }
  std::string getName() { return name; }
  Goblin() {}

  Goblin(int levelIn) {
    std::string nameOptions[50] = {   
        "John",        "Mary",      "James",    "Sarah",    "Michael",
        "Jennifer",    "David",     "Lisa",     "Robert",   "Emily",
        "William",     "Jessica",   "Richard",  "Michelle", "Thomas",
        "Amanda",      "Daniel",    "Nicole",   "Matthew",  "Laura",
        "Christopher", "Stephanie", "Joseph",   "Heather",  "Charles",
        "Melissa",     "Steven",    "Kimberly", "Brian",    "Elizabeth",
        "Kevin",       "Rebecca",   "Mark",     "Sarah",    "Jason",
        "Christina",   "Scott",     "Amy",      "Daniel",   "Susan",
        "Patrick",     "Karen",     "Timothy",  "Patricia", "Andrew",
        "Angela",      "Jonathan",  "Rachel",   "Eric",     "Michelle"};
  
    index = (rand()) % 49;
    name = nameOptions[index]; // pick a random number 0-49 and picks name from the nameOptions corresponding to that number
    level = levelIn;
    healthMax = 2 * level + 1;      
    healthCurrent = 2 * level + 1;
    strength = 2 * level + 1;
    mana = 2 * level + 1;
    luck = 2 * level + 1;     //goblin stats scale based off stage level and constant
    isAlive = true;
  }
  virtual int enemyAttack() {
    int damage = strength;
    int lb = round(strength * 0.5);
    int ub = round(strength * 1.5);
    damage = rand() % (ub - lb + 1) + lb;
    double hit = (rand() % 100) / 100;    //enemy attack function which determines damage based of a range
    if (hit >= luck) {
      damage = 0;
      return damage;
    }
    return damage;
  }
};

#endif