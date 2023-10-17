//This file contains a switch statement which based on a player input (carries in from main) executes an encouter 
#ifndef EXECUTEENCOUNTER_H
#define EXECUTEENCOUNTER_H

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
#include "battle.h"
#include "bossbattle.h"
#include "itemSelect.h"

void executeEncounter(Player* player, int chosenEncounter, int level) {
 
  switch (chosenEncounter) {
    case (0): {
      // no encounter
      // return;
      break;
    }
    case (1): {
      // an item select encounter
      itemSelect(player);
      break;
    }
    case (2): {
      // an enemy encounter
      Goblin* goblin = new Goblin(level);
      Battle(player, goblin);
      break;
    }
    case (3): {
      // a boss encounter
      BossGoblin* boss = new BossGoblin();
      BossBattle(player, boss);
      break;
    }
    default: {
      // no path
      break;
    }
  }
}

#endif