#ifndef GOBLIN_H
#define GOBLIN_H

#include "character.h"

class Goblin : public Character {
 private:
  std::string name;
  int index;

 public:
  void setName(std::string nameIn) { name = nameIn; }
  std::string getName() { return name; }
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
    srand(time(NULL));
    index = std::rand() % 49;
    name = nameOptions[index];
    level = levelIn;
    healthMax = 2 * level;
    healthCurrent = 2 * level;
    strength = 2 * level;
    mana = 2 * level;
    luck = 2 * level;
    isAlive = true;
  }
};

#endif