#include "ui.h"
#include "class.h"

int main() {
  std::string* userInfo;
  userInfo = gameIntro();
  std::cout << gameTitle;
  std::string userName = userInfo[0];
  std::string userType = userInfo[1];
  Player player(userName, userType);
  Goblin goblin1(1);
  delete[] userInfo;

  itemSelect(player);

  normalBattle(player, goblin1);

  deathScreen();

  finishScreen();
}