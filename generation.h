//this file contains the 'map' generation functions and a choiceUpToSix function that stops wrong inputs
#include <iostream>
#ifndef GENERATION_H
#define GENERATION_H

void displayMap(int path1, int path2, int path3) {  // takes 3 inputs and displays 3 path choices
  std::cout << path1 << "    " << path2 << "    " << path3 << std::endl;
  std::cout << " \\   |   /" << std::endl;
  std::cout << "  \\  |  /" << std::endl;
  std::cout << "   \\ | /" << std::endl;
  std::cout << "   player" << std::endl;  // UI to display 3 seperate paths
}

void displayMap(int path1, int path2) {  // takes 2 inputs and displays 2 path choices
  std::cout << path1 << "        " << path2 << std::endl;
  std::cout << " \\      /" << std::endl;
  std::cout << "  \\    /" << std::endl;
  std::cout << "   \\  /" << std::endl;
  std::cout << "   player" << std::endl;  // UI to display 3 seperate paths
}

void pathNumberToString(int path) {  // this is the key translating an int into the path type
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
  }  // switch statement produces the UI do determine
}

int choiceUpToSix(std::string choiceIn, int amountOfChoices) { //input a string and convert to a char based on how many choices you need 
  int output = 0;                                              //useful so the program dosent break when char is inputed when the program expects a int
  char charChoice;               // define char variable
  charChoice = choiceIn.at(0);  // takes first char of the string and runs
  switch (charChoice) {
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

int createAndReturnPaths() { //creates and displays a map then returns the path that the play wants to go down for the encounter function
  srand(time(0));
  int path1 = std::rand() % 4;
  int path2 = std::rand() % 4;
  int path3 = std::rand() % 4;

  if (path1 >= 2 ) {    //check if more then 2 if it is it sets the path to 2 which is an item encounter
    path1 = 2;
  }
  if (path2 >= 2) {
    path2 = 2;
  }
  if (path3 >= 2) {
    path3 = 2;
  }

  if (path1 == 2 && path2 == 2 && path3 == 2) {     //if all the paths are enemy encouters then it makes path 1 a no encounter
    path1 = 0;
  }

  int twoOrThreePaths = std::rand() % 2;
  int encounterValue = 0;

  if (twoOrThreePaths == 0) {
    displayMap(path1, path2, path3);  // displays the map and takes the
    std::cout << "Path 1 is ";
    pathNumberToString(path1);
    std::cout << "Path 2 is ";
    pathNumberToString(path2);
    std::cout << "Path 3 is ";
    pathNumberToString(path3);

    for (int i = 0; i < 1; i++) {
      std::cout << "\nWhat path would you like to choose?" << std::endl;
      int pathChoice = 0;
      std::string choiceIn;
      std::cin >> choiceIn;
      if (choiceUpToSix(choiceIn, 3) == 0) {
        std::cout << "invalid input" << std::endl;
        i--;
      } else {
        pathChoice = choiceUpToSix(choiceIn, 3);
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
            return encounterValue;
        }
      }
    }
  } else {
    displayMap(path1, path2);  // displays the map and takes the
    std::cout << "Path 1 is ";
    pathNumberToString(path1);
    std::cout << "Path 2 is ";
    pathNumberToString(path2);

    for (int i = 0; i < 1; i++) {
      std::cout << "\nWhat path would you like to choose?" << std::endl;
      int pathChoice = 0;
      std::string choiceIn;
      std::cin >> choiceIn;
      if (choiceUpToSix(choiceIn, 2) == 0) {
        std::cout << "invalid input" << std::endl;
        i--;
      } else {
        pathChoice = choiceUpToSix(choiceIn, 2);
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
            return encounterValue;
        }
      }
    }
  }
  return encounterValue;
}

#endif