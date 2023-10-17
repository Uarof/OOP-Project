//this file contains the chooseDifficulty function which takes a player input to set the length of the dungeon
// 1 or easy makes the length = 5 
// 2 or medium makes the length = 10
// 3 or hard makes the length = 15
#ifndef CHOOSEDIFFICULTY_H
#define CHOOSEDIFFICULTY_H

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
#include "printCentred.h"
#include "gameTitle.h"

int chooseDifficulty() {
  int playerDificultychoice = 0;
  for (int i = 0; i < 1; i++) {
    std::cout << "\nPlease enter dificutly" << std::endl;
    std::cout << "(1) for Easy" << std::endl;
    std::cout << "(2) for Medium" << std::endl;
    std::cout << "(3) for Hard\n" << std::endl;

    std::string choiceIn;
    std::cin >> choiceIn;  // player input as a string

    if (choiceUpToSix(choiceIn, 3) == 0) {
      std::cout << "invalid input" << std::endl;
      i--;
    } else {
      playerDificultychoice = choiceUpToSix(choiceIn, 3);
    }
  }
  return playerDificultychoice;
}

#endif