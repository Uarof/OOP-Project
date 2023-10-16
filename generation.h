#include <iostream>
#ifndef GENERATION_H
#define GENERATION_H

void displaymap(int path1, int path2, int path3) {  // takes 3 inputs and displays 3 path choices                      
  std::cout << path1 << "    " << path2 << "    " << path3 << std::endl;
  std::cout << " \\   |   /" << std::endl;
  std::cout << "  \\  |  /" << std::endl;
  std::cout << "   \\ | /" << std::endl;
  std::cout << "   player" << std::endl;            // UI to display 3 seperate paths
}

void displaymap(int path1, int path2) {             // takes 2 inputs and displays 2 path choices
  std::cout << path1 << "        " << path2 << std::endl;
  std::cout << " \\      /" << std::endl;
  std::cout << "  \\    /" << std::endl;
  std::cout << "   \\  /" << std::endl;
  std::cout << "   player" << std::endl;            // UI to display 3 seperate paths
}

void path_number_to_string(int path) {// this is the key translating an int into the path type
  switch (path) {
    case (0):
      std::cout << "no encounter" << std::endl;
      break;
    case (1):
      std::cout << "an item encounter" << std::endl;
      break;
    case (2):
      std::cout << "an enemy encounter" << std::endl;
      break;
    case (3):
      std::cout << "a boss encounter" << std::endl;
      break;
    default:
      std::cout << "no path" << std::endl;
      break;
  }                                               //switch statement produces the UI do determine 
}

int choiceUpToSix(std::string choice_in, int amountOfChoices) {
  int output = 0;
  char char_choice;                       // define char variable
  char_choice = choice_in.at(0);  // takes first char of the string and runs
  switch (char_choice) {
    case ('1'):
      output = 1;
      break;
    case ('2'):
      output = 2;
      break;
    case ('3'):
      output = 3;
      break;
    case ('4'):
      output = 4;
      break;
    case ('5'):
      output = 5;
      break;
    case ('6'):
      output = 6;
      break;
    default:
      output = 0;
      break;
  }
  if (output > amountOfChoices) {
    output = 0;
  }
  return output;
}

int createAndReturnPaths() {
  srand(time(0));
  int path1 = std::rand() % 3;
  int path2 = std::rand() % 3;
  int path3 = std::rand() % 3;

  int TwoOrThreePaths = std::rand() % 2;
  int encounterValue = 0;

  if (TwoOrThreePaths == 0) {
    displaymap(path1, path2, path3);  // displays the map and takes the
    std::cout << "Path 1 is ";
    path_number_to_string(path1);
    std::cout << "Path 2 is ";
    path_number_to_string(path2);
    std::cout << "Path 3 is ";
    path_number_to_string(path3);
    std::cout << std::endl;

    for (int i = 0; i < 1; i++) {
      std::cout << "what path would you like to choose?" << std::endl;
      int pathChoice = 0;
      std::string choice_in;
      std::cin >> choice_in;
      if (choiceUpToSix(choice_in, 3) == 0) {
        std::cout << "invalid input" << std::endl;
        i--;
      } else {
        pathChoice = choiceUpToSix(choice_in, 3);
      }
      switch (pathChoice) {
        case 1:
          encounterValue = path1;
          break;
        case 2:
          encounterValue = path2;
          break;
        case 3:
          encounterValue = path3;
          break;
        default:
          encounterValue = path1;
          break;
      }
      return encounterValue;
    }
  } else {
    displaymap(path1, path2);  // displays the map and takes the
    std::cout << "Path 1 is ";
    path_number_to_string(path1);
    std::cout << "Path 2 is ";
    path_number_to_string(path2);

    for (int i = 0; i < 1; i++) {
      std::cout << "what path would you like to choose?" << std::endl;
      int pathChoice = 0;
      std::string choice_in;
      std::cin >> choice_in;
      if (choiceUpToSix(choice_in, 2) == 0) {
        std::cout << "invalid input" << std::endl;
        i--;
      } else {
        pathChoice = choiceUpToSix(choice_in, 2);
      }
      switch (pathChoice) {
        case 1:
          encounterValue = path1;
          break;
        case 2:
          encounterValue = path2;
          break;
        default:
          encounterValue = path1;
          break;
      }
      return encounterValue;
    }
  }
  return encounterValue;
}

#endif