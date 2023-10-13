#ifndef POTION_H
#define POTION_H

#include "item.h"

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
    if (reset_type == 1) {
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