#ifndef BATTLE_H
#define BATTLE_H

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
#include "inventoryselect.h"

void Battle(Player* player, Goblin* goblin) {
  // records wheter a valid input has been given
  bool correctInput = false;
  // store chosen move
  int moveInput = 0;
  // records whether the user chose to block
  bool blocked = false;
  // records whether the user chose to use a heavy
  bool usedHeavy = false;
  // damage stores the amount of damage the goblin will take
  int damage = 0;
  // battle_running will break th while loop if an end of battle condition is
  // met
  bool battle_running = true;

  // while battle_running is true
  while (battle_running == true) {
    // imports players name and game session from player vaiable
    std::string gameSession = player->getGameSession();
    std::string userName = player->getName();

    // imports goblin info
    std::string enemyName = goblin->getName();

    // resets correct input back to false
    correctInput = false;

    // while correct input is false
    while (correctInput == false) {
      // clear terminal
      system("clear");

      // print game title
      std::cout << gameTitle;
      std::cout << "\n";

      // game session is printed in the centre
      printCentred(gameSession);

      // "Battle" is printed in the centre
      printCentred("- Battle -");
      std::cout << "\n";

      // Prints health bars
      std::cout << userName << ":";
      player->display_Health();
      std::cout << std::endl;
      std::cout << enemyName << " the Goblin:";
      goblin->display_Health();
      std::cout << std::endl;

      // Prints possible options
      std::cout << "\nMOVES:\n";
      std::cout << "1. Heavy Melee - Requires cool down\n";
      std::cout << "2. Cast Spell\n";
      std::cout << "3. Light Melee\n";
      std::cout << "4. Block\n";
      std::cout << "5. Use Item\n";
      std::cout << "\nWhat will you do?\n";

      // USER ATTACK
      // if the player used a heavy attack last time
      if (usedHeavy == true) {
        // then they need to rest and the turn is skipped
        std::cout << "You need to rest\n";
        usedHeavy = false;
        // if else
      } else {
        // retrieves the move the user wants to use
        std::cin >> moveInput;
        // if moveInput is...
        switch (moveInput) {
          // 1, then it's a Heavy Melee
          case 1:
            std::cout << "\n" << userName << " used Heavy Melee!\n";
            std::cout << userName << " feels week and needs to rest\n";
            // damage dealt is equal to their strength
            player->playerattack(goblin, player->getStrength());
            usedHeavy = true;
            correctInput = true;
            break;
          // 2, then it's cast a spell
          case 2:
            std::cout << "\n" << userName << " cast a spell!\n";
            // damage dealt is equal to their mana
            player->playerattack(goblin, player->getMana());
            correctInput = true;
            break;
          // 3, then it's a light Melee
          case 3:
            std::cout << "\n" << userName << " used light Melee!\n";
            // damaged dealt is half the players strength
            player->playerattack(goblin, player->getStrength() / 2);
            correctInput = true;
            break;
            // 4, then it's a block
          case 4:

            std::cout << "\n" << userName << " blocked their opponent!\n";
            correctInput = true;
            blocked = true;
            break;

          case 5:
            std::cout << "\n" << userName << " reaches into their pouch...\n ";
            correctInput = true;
            printInventory(player);
            break;

          default:
            std::cout << "Invalid move, please try again\n";
            break;
        }
        if (goblin->getIsAlive() == false) {
          battle_running = false;
        }
        if (player->getIsAlive() == false) {
          battle_running = false;
        }
      }

      // goblin attack
      if (goblin->getIsAlive() == true) {
        if (blocked == true) {
          std::cout << "The goblin was blocked!! \n";
        } else {
          damage = goblin->enemy_attack();
          player->playerTakeDamage(damage);
        }
      }
      if (goblin->getIsAlive() == false) {
        battle_running = false;
      }
      if (player->getIsAlive() == false) {
        battle_running = false;
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
}

#endif