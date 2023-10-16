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
    std::cout << "please enter dificutly" << std::endl;
    std::cout << "(1) for Easy" << std::endl;
    std::cout << "(2) for Medium" << std::endl;
    std::cout << "(3) for Hard" << std::endl;

    std::string choice_in;
    std::cin >> choice_in;  // player input as a string

    if (choiceUpToSix(choice_in, 3) == 0) {
      std::cout << "invalid input" << std::endl;
      i--;
    } else {
      playerDificultychoice = choiceUpToSix(choice_in, 3);
    }
  }
  return playerDificultychoice;
}

#endif