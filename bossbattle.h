// this file contains the battle UI and functionality the the special encounter for the boss case.


#ifndef BOSSBATTLE_H
#define BOSSBATTLE_H

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "bossGoblin.h"
#include "character.h"
#include "gameTitle.h"
#include "generation.h"
#include "goblin.h"
#include "item.h"
#include "player.h"
#include "potion.h"
#include "printCentred.h"

void BossBattle(Player* player, BossGoblin* goblin) {
  // accepts input and tests if input is valid or not
  // if the input is invalid, the user will be prompted again.
  bool correctInput = false;
  int moveInput = 0;
  bool blocked = false;
  bool usedHeavy = false;
  int damage = 0;

  bool battleRunning = true;
  while (battleRunning == true) {
    // imports players name and game session from player vaiable
    std::string gameSession = player->getGameSession();
    std::string userName = player->getName();

    // imports goblin info
    std::string enemyName = goblin->getName();

    correctInput = false;
    while (correctInput == false) {
      // clear terminal
      system("clear");

      // print game title
      std::cout << gameTitle;
      std::cout << "\n";

      // game session is printed in the centre
      printCentred(gameSession);

      printCentred("< THIS IS THE BFG, THE BOSS OF THE GOBLINS >");

      // "Battle" is printed in the centre
      printCentred("- Boss Battle -");
      std::cout << "\n";

      // Prints health bars
      std::cout << userName << ": ";
      player->displayHealth();
      std::cout << std::endl;
      std::cout << enemyName << ": ";
      goblin->displayHealth();
      std::cout << std::endl;

      // Prints possible options
      std::cout << "\nMOVES:\n";
      std::cout << "1. Heavy Melee - Requires cool down\n";
      std::cout << "2. Cast Spell\n";
      std::cout << "3. Light Melee\n";
      std::cout << "4. Block\n";
      std::cout << "5. Use Item\n";
      std::cout << "\nWhat will you do? enter number: \n";
      // user attack
      if (usedHeavy == true) {
        std::cout << "You need to rest\n";
        usedHeavy = false;
      } else {
        int moveInput = 0;
          int pathChoice = 0;
          std::string choiceIn;
          int result = 0;
          while (result == 0) {
            std::cin >> choiceIn;
            result = choiceUpToSix(choiceIn, 5);
            if (choiceUpToSix(choiceIn, 5) == 0) {
              std::cout << "invalid input" << std::endl;
              result = 0;
            }
          moveInput = (choiceUpToSix(choiceIn, 5));
          }
      }
    switch (moveInput) {
      case 1:
        std::cout << "\n" << userName << " used Heavy Melee!\n";
        std::cout << userName << " feels week and needs to rest\n";
        player->playerAttack(goblin, player->getStrength());
        usedHeavy = true;
        correctInput = true;
        goblin->setDebuffDamage(0);
        break;
      case 2:
        std::cout << "\n" << userName << " cast a spell!\n";
        player->playerAttack(goblin, player->getMana());
        correctInput = true;
        break;
      case 3:
        std::cout << "\n" << userName << " used light Melee!\n";
        player->playerAttack(goblin, player->getStrength() / 2);
        correctInput = true;
        break;

      case 4:
        std::cout << "\n" << userName << " blocked their opponent!\n";
        correctInput = true;
        blocked = true;
        break;

        // case 5:
        //   std::cout << "\n" << userName << " reaches into their
        //   pouch...\n"; correctInput = true; break;

      default:
        std::cout << "Invalid move, please try again\n";
        break;
    }
    if (goblin->getIsAlive() == false) {
      battleRunning = false;
    }
    if (player->getIsAlive() == false) {
      battleRunning = false;
    }
  }

  // goblin attack
  if (goblin->getIsAlive() == true) {
    if (blocked == true) {
      std::cout << "The goblin was blocked!! \n";
    } else {
      damage = goblin->enemyAttack();
      player->playerTakeDamage(damage);
    }
  }
  if (goblin->getIsAlive() == false) {
    battleRunning = false;
  }
  if (player->getIsAlive() == false) {
    battleRunning = false;
  }
}
// user is prompted to press enter to continue
std::cout << "\n";
std::cout << "- Press Enter to Continue -\n";

// the inputs of cleared, for compatibility
std::cin.clear();
std::fflush(stdin);

// if enter is pressed, then
if (std::cin.get() == '\n') {
  // terminal is cleared
  system("clear");
}
}


#endif