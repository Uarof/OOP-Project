// 2nd lvl inhertance from item class
#ifndef POTION_H
#define POTION_H

#include "item.h"

class potion : public item {
 protected:
  bool resetType; // if its a reset back to max or an increase of total
  int attribute; // attribute that the potion affects
  int increase; // amount of increase
 public:
  potion() {}
  potion(bool rType, int att, int inc) {
   resetType = rType;
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
    if (resetType == 1) {
     name = "Increase Max " + name;
    }
  }
  
  void setResetType(bool rType) {resetType = rType;}
  bool getResetType() {return resetType;}
  void setAttribute(int att) {attribute = att;}
  int getAttribute() {return attribute;}
  void setIncrease(int inc) {increase = inc;}
  int getIncrease() {return increase;}
};

#endif