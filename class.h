#ifndef CLASS_H
#define CLASS_H
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

class Player : public Character {
 private:
  std::string name;
  std::string type;
  item* inventory[5];

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
  }
  std::string getGameSession() {
    std::string gameSession = "- " + name + " the " + type + " -";
    return gameSession;
  }
};

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

class item {
 protected:
  std::string name;

 public:
  item() {name = " ";}
  item(std::string name_in) {name = name_in;}
  void set_name(std::string name_in) {name = name_in;}
  std::string get_name() {return name;}
};

class potion : public item {
 protected:
  bool reset_type; // if its a reset back to max or an increase of total
  int attribute; // attribute that the potion affects
  int increase; // amount of increase
 public:
  potion() {}
  potion(bool r_type, int att, int inc) {
   reset_type = r_type;
   attribute = att;
   increase = inc;
   switch(attribute) {
    case 0:
     name = "Health Potion";
    break;
    case 1:
     name = "Strength Potion";
    break;
    case 2:
     name = "Mana Potion";
    break;
    case 3:
     name = "Luck Potion";
    break;
    default:
     name = "Invalid Potion";
    }
    if (reset_type = 1) {
     name = "Increase Max " + name;
    }
  }
  
  void set_reset_type(bool r_type) {reset_type = r_type;}
  bool get_reset_type() {return reset_type;}
  void set_attribute(int att) {attribute = att;}
  int get_attribute() {return attribute;}
  void set_increase(int inc) {increase = inc;}
  int get_increase() {return increase;}
};

#endif