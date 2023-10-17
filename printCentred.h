//function to print any text centered in the terminal
#ifndef PRINTCENTRED_H
#define PRINTCENTRED_H

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "bossGoblin.h"
#include "character.h"
#include "generation.h"
#include "goblin.h"
#include "item.h"
#include "player.h"
#include "potion.h"

void printCentred(std::string str) {
  // printCentred prints a given string in the middle of a set character width,
  // in this case a width of 90 characters
  int width = 90;
  // the function will find the length of the string and find the difference
  // between it and the set width
  // It will then divide this value by 2, giving an even space on each side
  int padding = (width - str.length()) / 2;
  // this many spaces are then printed.
  for (int i = 0; i < padding; i++) {
    std::cout << " ";
  }
  // followed by the desired string and a new line.
  std::cout << str;
  std::cout << "\n";
}

#endif