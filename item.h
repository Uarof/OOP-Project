#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
 protected:
  std::string name;

 public:
  item() {name = "[Empty Slot]";}
  item(std::string name_in) {name = name_in;}
  void set_name(std::string name_in) {name = name_in;}
  std::string get_name() {return name;}
};

#endif