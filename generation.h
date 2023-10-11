#include <iostream>
#ifndef GENERATION_H
#define GENERATION_H

class Generation {
private:
    int path1 = 0; 
    int path2 = 0; 
    int path3 = 0;         //setting all paths to default 0

public:
    Generation(int lvl);
    Generation() {};
    
    void displaymap(int path1, int path2, int path3);
    void displaymap(int path1, int path2);
    void bossCase(int path1);

    int get_path1();
    int get_path2();
    int get_path3();
};


Generation::Generation(int lvl) {
    srand (time(NULL));                                 //initlise the random seed

    this->path1 = std::rand() % 5;                       
    this->path2 = std::rand() % 5;
    this->path3 = std::rand() % 5;                       //defines the ints path1, path2, path3 and random ints between 0 and 4

    // Generation::displaymap(path1, path2, path3); 
    
    std::cout << "this is lvl " << lvl << std::endl;
}

void Generation::displaymap(int path1, int path2, int path3) {
    std::cout << path1 << "    " << path2 << "    " << path3 << std::endl;
    std::cout << " \\   |   /" << std::endl;
    std::cout << "  \\  |  /" << std::endl;
    std::cout << "   \\ | /" << std::endl;
    std::cout << "   player" << std::endl;
}

void Generation::displaymap(int path1, int path2) {
    std::cout << path1 << "        " << path2 << std::endl;
    std::cout << " \\      /" << std::endl;
    std::cout << "  \\    /" << std::endl;
    std::cout << "   \\  /" << std::endl;
    std::cout << "   player" << std::endl;
}

void Generation::bossCase(int path1) {}


int Generation::get_path1() {
    return this->path1;
}

int Generation::get_path2() {
    return this->path2;
}

int Generation::get_path3() {
        return path3;
}


void path_number_to_string(int path) {            
        // std::cout << path << std::endl;
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
            std::cout << "a miniboss encounter" << std::endl;
            break;
        case (4):
            std::cout << "a boss encounter" << std::endl;
            break;  
        default:
        std::cout << "no path" << std::endl;
            break;
        }
    }

    int three_choice(std::string choice_in) {
        int output = 0;
        char char_choice;                                      //define char variable
        std::string string_choice = choice_in;                             //define string variable
        char_choice = string_choice.at(0);                  //takes first char of the string and runs it through the switch statment 
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
        default:
            output = 0;
            break;
        }
    return output;
    }

#endif

