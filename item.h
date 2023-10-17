#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
 protected:
  std::string name;

 public:
  item() {name = "[Empty Slot]";}
  item(std::string nameIn) {name = nameIn;}
  void setName(std::string nameIn) {name = nameIn;}
  std::string getName() {return name;}

  void setResetType(bool) {}
  bool getResetType() {return false;}
  void setAttribute(int) {}
  int getAttribute() {return 0;}
  void setIncrease(int) {}
  int getIncrease() {return 0;}
};

#endif