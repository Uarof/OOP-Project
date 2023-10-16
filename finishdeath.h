#ifndef FINISHDEATH_H
#define FINISHDEATH_H


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


void deathScreen() {
  // clears terminal
  system("clear");

  // ASCII art for "DEATH"
  std::cout << "______ _____  ___ _____ _   _\n";
  std::cout << "|  _  \\  ___|/ _ \\_   _| | | |\n";
  std::cout << "| | | | |__ / /_\\ \\| | | |_| |\n";
  std::cout << "| | | |  __||  _  || | |  _  |\n";
  std::cout << "| |/ /| |___| | | || | | | | |\n";
  std::cout << "|___/ \\____/\\_| |_/\\_/ \\_| |_/\n";

  // the user is reminded of their failure
  std::cout << "\n";
  std::cout << "The maze has taken you,\n";
  std::cout << "the Goblins laugh in your demise!\n";

  // the user is prompted to press enter to continue
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

void finishScreen() {
  // clears terminal
  system("clear");

  // ACSCII art for "FINISH"
  std::cout << "______ _____ _   _ _____ _____ _   _\n";
  std::cout << "|  ___|_   _| \\ | |_   _/  ___| | | |\n";
  std::cout << "| |_    | | |  \\| | | | \\ `--.| |_| |\n";
  std::cout << "|  _|   | | | . ` | | |  `--. \\  _  |\n";
  std::cout << "| |    _| |_| |\\  |_| |_/\\__/ / | | |\n";
  std::cout << "\\_|    \\___/\\_| \\_/\\___/\\____/\\_| |_/\n";

  // The user is reminded of their success
  std::cout << "\n";
  std::cout << "You have successfully made it through the cave,\n";
  std::cout << "The goblins weep in your victory!\n";

  // Game Credits
  std::cout << "\n";
  std::cout << "Thank you for playing!\n";
  std::cout << "\n";
  std::cout << "This game was made buy:\n";
  std::cout << "* Ayden Julien\n";
  std::cout << "* Ethan Carling\n";
  std::cout << "* Trey Smith\n";

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