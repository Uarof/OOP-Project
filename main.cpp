#include "generation.h"
#include <iostream>

int main() {

    // next 6 line are intro graphics
    std::cout << " ___________ _____ _____   _____ ___________ _     _____ _   _   _____ ________  ____   _ _       ___ _____ ___________" << std::endl; 
    std::cout << "|  ___| ___ \\_   _/  __ \\ |  __ \\  _  | ___ \\ |   |_   _| \\ | | /  ___|_   _|  \\/  | | | | |     / _ \\_   _|  _  | ___ \\" << std::endl;
    std::cout << "| |__ | |_/ / | | | /  \\/ | |  \\/ | | | |_/ / |     | | |  \\| | \\ `--.  | | | .  . | | | | |    / /_\\ \\| | | | | | |_/ /" << std::endl;
    std::cout << "|  __||  __/  | | | |     | | __| | | | ___ \\ |     | | | . ` |  `--. \\ | | | |\\/| | | | | |    |  _  || | | | | |    / " << std::endl;
    std::cout << "| |___| |    _| |_| \\__/\\ | |_\\ \\ \\_/ / |_/ / |_____| |_| |\\  | /\\__/ /_| |_| |  | | |_| | |____| | | || | \\ \\_/ / |\\ \\ " << std::endl;
    std::cout << "\\____/\\_|    \\___/ \\____/  \\____/\\___/\\____/\\_____/\\___/\\_| \\_/ \\____/ \\___/\\_|  |_/\\___/\\_____/\\_| |_/\\_/  \\___/\\_| \\_|" << std::endl;

    // next 15 lines are setting dificulty with a check to make sure you only pick between 1 and 3
    
    int dificulty = 0;                                          //set dificulty to default 0

    for (int i = 0; i < 1; i++) {
        std::cout << "please enter dificutly" << std::endl;
        std::cout << "(1) for Easy"<< std::endl;
        std::cout << "(2) for Medium" << std::endl;
        std::cout << "(3) for Hard" << std::endl;

        std::string choice_in;
        std::cin >> choice_in;                             //player input as a string
        
        if (three_choice(choice_in) == 0) {
            std::cout << "invalid input" << std::endl;
            i--;
        } else {
            dificulty = three_choice(choice_in);
        }

    }

    int maxLevel = dificulty*5;
    int currentLevel = 0;
    Generation stage[(maxLevel)];                        //creates either 
    
    //while(Player::) check if player is alive

    for (int i = 0; i < dificulty*5; i++){                  // this for loop is where the game lives
    
        stage[i] = Generation(i);                           //this is the level changes each time we get to the top of the for loop
        
        srand (time(NULL));
        int TwoOrThreePaths = std::rand() % 2;           
        if (TwoOrThreePaths == 0) {
            stage[i].displaymap(stage[i].get_path1(), stage[i].get_path2(), stage[i].get_path3());  //displays the map and takes the diferent paths for this iteration as imputs
            std::cout << "Path 1 is "; 
            path_number_to_string(stage[i].get_path1());
            std::cout << "Path 2 is ";
            path_number_to_string(stage[i].get_path2());
            std::cout << "Path 3 is ";
            path_number_to_string(stage[i].get_path3());
            std::cout << std::endl;
        } else {
            stage[i].displaymap(stage[i].get_path1(), stage[i].get_path2());  //displays the map and takes the diferent paths for this iteration as imputs
            std::cout << "Path 1 is "; 
            path_number_to_string(stage[i].get_path1());
            std::cout << "Path 2 is ";
            path_number_to_string(stage[i].get_path2());       
        }
        
        for (int i = 0; i < 1; i++) {
            std::cout << "what path would you like to choose?" << std::endl;
            
            std::string choice_in;
            std::cin >> choice_in;                             //player input as a string
        
        // if (three_choice(choice_in) == 0) {
        //     std::cout << "invalid path" << std::endl;
        //     i--;
        // } else {
        //     dificulty = three_choice(choice_in);
        // }

    }
    }

return 0;
}
