#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "character.h"
#include "player.h"
#include "goblin.h"
#include "item.h"
#include "potion.h"


// GLOBAL VARIABLE
// Game title, sourced from patorjk.com
std::string gameTitle =
    " ___________ _____ _____     _____ ___________ _     _____ _   "
    "_     _____ ________  ___\n"
    "|  ___| ___ \\_   _/  __ \\   |  __ \\  _  | ___ \\ |   |_   "
    "_| \\ | |   /  ___|_   _|  \\/  |\n"
    "| |__ | |_/ / | | | /  \\/   | |  \\/ | | | |_/ / |     | | |  "
    "\\| |   \\ `--.  | | | .  . |\n"
    "|  __||  __/  | | | |       | | __| | | | ___ \\ |     | | | . "
    "` |    `--. \\ | | | |\\/| |\n"
    "| |___| |    _| |_| \\__/\\   | | \\ \\ \\_/ / |_/ / |_____| "
    "|_| |\\  |   /\\__/ /_| |_| |  | |\n"
    "\\____/\\_|    \\___/ \\____/    "
    "\\____/\\___/\\____/\\_____/\\___/\\_| \\_/   \\____/ "
    "\\___/\\_|  |_/\n";

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

void itemSelect(Player player) {
  // imports players name and game session from player vaiable
  std::string gameSession = player.getGameSession();
  std::string userName = player.getName();

  // clear terminal
  system("clear");

  // print game title
  std::cout << gameTitle;
  std::cout << "\n";

  // game session is printed in the centre
  printCentred(gameSession);

  // "Battle" is printed in the centre
  printCentred("- Item Select -");
  std::cout << "\n";

  // user is prompted to select an item
  std::cout
      << "\nA travelling merchant offers you his wears, what will you take?\n";

  // item options are printed
  std::cout << "\nITEMS:\n";
  std::cout << "1. Health Potion\n";
  std::cout << "2. Power Up\n";
  std::cout << "3. Mannar Up\n\n";

  // accepts input and tests if input is valid or not
  // if the input is invalid, the user will be prompted again.
  // if valid, the item selection is acknowlegded
  bool correctInput = false;
  int selectedItem = 0;
  while (correctInput == false) {
    std::cin >> selectedItem;
    switch (selectedItem) {
      case 1:
        std::cout << "\n" << userName << " took the Health Potion and fled\n";
        correctInput = true;
        break;
      case 2:
        std::cout << "\n" << userName << " took the Power Up and fled\n";
        correctInput = true;
        break;
      case 3:
        std::cout << "\n" << userName << " took the Mannar Up and fled\n";
        correctInput = true;
        break;

      default:
        std::cout << "\n"
                  << "Invalid item, please try again\n";
        break;
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

void normalBattle(Player player, Goblin goblin) {
  // imports players name and game session from player vaiable
  std::string gameSession = player.getGameSession();
  std::string userName = player.getName();

  // imports goblin info
  std::string enemyName = goblin.getName();

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
  std::cout << userName << ": ########\t\t\t\t\t";
  std::cout << enemyName << " the Goblin: ########\n";

  // Prints possible options
  std::cout << "\nMOVES:\n";
  std::cout << "1. Heavy Melee - Requires cool down\n";
  std::cout << "2. Cast Spell\n";
  std::cout << "3. Light Melee\n";
  std::cout << "4. Block\n";
  std::cout << "5. Use Item\n";
  std::cout << "\nWhat will you do?\n";

  // accepts input and tests if input is valid or not
  // if the input is invalid, the user will be prompted again.
  bool correctInput = false;
  int moveInput = 0;
  while (correctInput == false) {
    std::cin >> moveInput;
    switch (moveInput) {
      case 1:
        std::cout << "\n" << userName << " used Heavy Melee!\n";
        std::cout << userName << " feels week and needs to rest\n";
        correctInput = true;
        break;
      case 2:
        std::cout << "\n" << userName << " cast a spell!\n";
        correctInput = true;
        break;
      case 3:
        std::cout << "\n" << userName << " used light Melee!\n";
        correctInput = true;
        break;

      case 4:
        std::cout << "\n" << userName << " blocked their opponent!\n";
        correctInput = true;
        break;

      case 5:
        std::cout << "\n" << userName << " reaches into their pouch...\n";
        correctInput = true;
        break;

      default:
        std::cout << "Invalid move, please try again\n";
        break;
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

std::string* gameIntro() {
  // clear terminal
  system("clear");
  // prompts to user to play fullscreen
  printCentred("Please play Fullscreen");
  printCentred("For the best experience and text compatibility");

  // user is prompted to press enter to continue
  std::cout << "\n";
  printCentred("-Press Enter to Continue-");

  // if enter is pressed, then the game starts
  while (std::cin.get() != '\n') {
    continue;
  }

  // clear terminal
  system("clear");
  // print game title
  std::cout << gameTitle;
  std::cout << "\n";

  // user is prompted to press enter to continue
  printCentred("-Press Enter To Start A New Game-");

  // prologue stores the entire backstory behind epic goblin sim
  std::string prologue =
      "In the rugged heartland of the realm, where emerald forests embraced "
      "jagged peaks, and rivers whispered secrets to ancient stones, there lay "
      "a treacherous cave known only as the Goblin's Den. This cavern, hidden "
      "beneath the gnarled roots of a colossal oak, had long been a source of "
      "dread for the nearby villagers.\n"
      "Among the brave few who dared to tread into the murky depths was a lone "
      "traveler, a wanderer of untamed lands, nameless and faceless to the "
      "villagers who shared tales of this ominous place. Clad in a travelers "
      "cloak, bearing scars of past encounters, and armed with a blade that "
      "gleamed with unspoken resolve, this solitary figure stood at the caves "
      "entrance.\n"
      "The air was thick with the acrid scent of damp earth and the lingering "
      "malevolence of countless goblin clans that had made the cave their "
      "home. Their nefarious deeds were whispered through the forest, their "
      "yellow eyes glowing like coals in the night, their sinister laughter "
      "echoing through the woods.\n"
      "With each step into the abyss, the traveler left behind the comforting "
      "embrace of sunlight, stepping into a world where shadows ruled. The "
      "caves mouth swallowed the traveler, enveloping them in the oppressive "
      "blackness, where stalactites hung like jagged teeth and the cold, "
      "dripping silence was punctuated only by the faintest rustle of unseen "
      "movement.\n"
      "The traveler descended deeper, driven by a relentless curiosity, a "
      "yearning to confront the source of darkness, and to unearth the secrets "
      "hidden within the goblin-infested cave. It was a journey of peril and "
      "discovery, where every step taken could lead to salvation or doom.\n"
      "As the travelers torch flickered in the oppressive darkness, the "
      "goblins, hidden in the labyrinthine passages ahead, prepared for the "
      "intruders arrival. They knew not the name nor the purpose of this brave "
      "soul who dared invade their domain, but they were certain of one thing "
      "-- this traveler would not emerge from the Goblins Den unchanged.\n"
      "In the heart of the cave, where the boundaries between fear and courage "
      "blurred, the destiny of the traveler and the secrets of the Goblins Den "
      "would intertwine. For within this subterranean realm, where treacherous "
      "paths awaited and goblin mischief thrived, a story of bravery and "
      "survival would unfold, and the travelers true name would be forged in "
      "the fires of the Goblins Den.\n";

  // if enter is pressed, then
  if (std::cin.get() == '\n') {
    // terminal is cleared
    system("clear");
    // the game title is printed
    std::cout << gameTitle;

    // "Prologue" is printed centred
    std::cout << "\n";
    printCentred("-Prologue-");
    std::cout << "\n";

    // As the prologue is printed, exceededLength will be set to true
    // if more than 76 characters have been printed in a line
    bool exceededLength = false;
    // j is a counter for the number of characters printed in a line
    int j = 0;
    // delay sets the time in ms for the print delay
    int delay = 0;

    // for i (character number in prologue) is less than the total number
    // of characeters in prologue
    for (int i = 0; i < prologue.length(); i++) {
      // if the number of characters printed in a line is divisable by 76
      if (((j % 76 == 0) && j != 0) || (exceededLength == true)) {
        // set exceededLength to true
        exceededLength = true;
      }
      // if exceededLength is true and the current character is a space
      if ((exceededLength == true) && (prologue[i] == ' ')) {
        // go to a new line
        std::cout << "\n";
        // increase total character counter
        i++;
        // set the number of character in the line to 0
        j = 0;
        // set exceededLength to false
        exceededLength = false;
      }

      // if the last character was a new line character, then a new line
      // has been entered, the amount of characters printed on the line
      // is now 0
      if (prologue[i - 1] == '\n') {
        j = 0;
      }

      // The program will be stopped for the time set by delay in ms
      std::this_thread::sleep_for(std::chrono::milliseconds(delay));

      // the current character is printed
      std::cout << prologue[i] << std::flush;
      j++;
    }
  }

  // print "-Press Enter to Continue-", in the centre
  std::cout << "\n";
  printCentred("-Press Enter to Continue-");

  // if enter is pressed
  if (std::cin.get() == '\n') {
    // clear terminal
    system("clear");
  }

  // print the game title
  std::cout << gameTitle;

  // print "-Select a Character-" in the centre
  std::cout << "\n";
  printCentred("-Select a Character-");
  std::cout << "\n";

  // print the character types on the first line
  std::cout << "WARRIOR";
  std::cout << "\t\t\tWIZARD";
  std::cout << "\t\t\tROUGE";
  std::cout << "\t\t\tPALADIN\n";

  // print the character type health stats on the second line
  std::cout << "Health: #####";
  std::cout << "\t\tHealth: #####";
  std::cout << "\t\tHealth: ###";
  std::cout << "\t\tHealth: ####\n";

  // print the character type strength stats on the third line
  std::cout << "Strength: #####";
  std::cout << "\t\tStrength: ##";
  std::cout << "\t\tStrength: #######";
  std::cout << "\tStrength: ####\n";

  // print the character type mannar stats on the fourth line
  std::cout << "Mannar: #";
  std::cout << "\t\tMannar: ######";
  std::cout << "\t\tMannar: #";
  std::cout << "\t\tMannar: ####\n";

  // print the character luck stats on the fith line
  std::cout << "Luck: #######";
  std::cout << "\t\tLuck: #####";
  std::cout << "\t\tLuck: ####";
  std::cout << "\t\tLuck: ####\n\n";

  // characterType stores the users chosen type
  std::string characterType = "defaultType";

  // if a correct input is given for characterType,
  // then correctInput is set to true, otherwise it's false
  bool correctInput = false;

  // while correctInput is false
  while (correctInput == false) {
    // prompt the user for what type they would like
    std::cout << "Who will you choose?: \n";
    std::cin >> characterType;

    // make characterType uppercase for compatibility.
    // MAY NEED TO BE CHANGED FOR ORIGINALITY
    std::transform(characterType.begin(), characterType.end(),
                   characterType.begin(), ::toupper);

    // characterType is compared to each valid option
    // if characterType is valid, then its set to an offical value
    // and correctInput is set to true, ending the while loop
    if (characterType == "WARRIOR") {
      characterType = "Warrior";
      correctInput = true;
    } else if (characterType == "WIZARD") {
      characterType = "Wizard";
      correctInput = true;
    } else if (characterType == "ROUGE") {
      characterType = "Rouge";
      correctInput = true;
    } else if (characterType == "PALADIN") {
      characterType = "Paladin";
      correctInput = true;
    } else {
      // if it is not valid,
      // the user will be prompted to try again
      std::cout << "Incorrect answer, please try again\n";
      // correctInput is left as false
      correctInput = false;
      // and the while loop will continue
    }
  }

  // the user will keep being prompted for a name until a valid name is
  // entered
  correctInput = false;
  std::string characterName = "DefaultName";
  while (correctInput == false) {
    // the user is prompted for a user name
    std::cout << "\nWhat name will you take?: \n";

    // the inputs of cleared, for compatibility
    // std::cin.ignore();
    std::cin.clear();
    std::fflush(stdin);

    // reads in entire line
    std::getline(std::cin, characterName);

    // if the entered name is less than one character in length it is
    // invalid, otherwise it is valid
    if (characterName.length() > 1) {
      correctInput = true;
      break;
    } else {
      correctInput = false;
      std::cout << "Please enter a valid name\n";
    }
  }

  // make characterName uppercase for aesthetics.
  // MAY NEED TO BE CHANGED FOR ORIGINALITY
  std::transform(characterName.begin(), characterName.end(),
                 characterName.begin(), ::toupper);

  // prompt user with their chosen name and type and display an into message.
  std::cout << "\nThe " << characterType << "; " << characterName
            << ", enters the maze,\n"
               "VENTURE FORTH BRAVE SOUL!!!\n\n";

  // the inputs of cleared, for compatibility
  std::cin.clear();
  std::fflush(stdin);

  // user is prompted to press enter to continue
  printCentred("-Press Enter to Continue-");

  // if the user presses enter
  if (std::cin.get() == '\n') {
    // then terminal is cleared
    system("clear");
  }

  // dynamic memory is allocated for the users name and type
  std::string* introReturn = new std::string[2];
  introReturn[0] = characterName;
  introReturn[1] = characterType;
  // which is returned to the main program.
  return introReturn;
}