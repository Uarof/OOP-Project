//all class's and their funtions are tested in this file 
//the class called 'Test' contains void functions in protected that test each funtionality of the funtions within it
#include "files.h"

class Test {
 protected:
  void testCharacter() {
    std::cout << "this is the test for the character class" << std::endl;

    Character character;
    if (character.getLevel() != 0) {
      std::cout << "test 1 failed" << std::endl;
    };

    if (character.getHealth() != 0) {
      std::cout << "test 2 failed" << std::endl;
    };

    if (character.getHealthCurrent() != 0) {
      std::cout << "test 3 failed" << std::endl;
    }

    if (character.getStrength() != 0) {
      std::cout << "test 4 failed" << std::endl;
    }

    if (character.getMana() != 0) {
      std::cout << "test 5 failed" << std::endl;
    }

    if (character.getLuck() != 0.0) {
      std::cout << "test 6 failed" << std::endl;
    }

    if (character.getIsAlive() != true) {
      std::cout << "test 7 failed" << std::endl;
    }
  }

  void testPlayer() {
    std::cout << "this is the test for the Player class" << std::endl;

    Player Warrior("fred", "Warrior");
    if (Warrior.getLevel() != 1) {
      std::cout << "test 1 failed" << std::endl;
    }

    if (Warrior.getHealth() != 8) {
      std::cout << "test 2 failed" << std::endl;
    }

    if (Warrior.getHealthCurrent() != 8) {
      std::cout << "test 3 failed" << std::endl;
    }
    if (Warrior.getStrength() != 8) {
      std::cout << "test 4 failed" << std::endl;
    }

    if (Warrior.getMana() != 1) {
      std::cout << "test 5 failed" << std::endl;
    }

    if (Warrior.getLuck() != 0.5) {
      std::cout << "test 6 failed" << std::endl;
    }

    if (Warrior.getIsAlive() != true) {
      std::cout << "test 7 failed" << std::endl;
    }

    if (Warrior.getName() != "fred") {
      std::cout << "test 8 failed" << std::endl;
    }

    if (Warrior.getType() != "Warrior") {
      std::cout << "test 9 failed" << std::endl;
    }
  }

  void testGoblin() {
    std::cout << "this is the test for the Goblin class" << std::endl;
    Goblin Goblin(5);
      if (Goblin.getLevel() != 5) {
        std::cout << "test 1 failed" << std::endl;
      }
      if (Goblin.getHealth() != ((2 * 5 + 1))) {
        std::cout << "test 2 failed" << std::endl;
      }
      if (Goblin.getHealthCurrent() != (2 * 5 + 1)) {
        std::cout << "test 3 failed" << std::endl;
      }
      if (Goblin.getStrength() != (2 * 5 + 1)) {
        std::cout << "test 4 failed" << std::endl;
      }
      if (Goblin.getMana() != (2 * 5 + 1)) {
        std::cout << "test 5 failed" << std::endl;
      }
      if (Goblin.getLuck() != (2 * 5 + 1)) {
        std::cout << "test 6 failed" << std::endl;
      }
      if (Goblin.getIsAlive() != true) {
        std::cout << "test 7 failed" << std::endl;
      }
  }

  void testBossGoblin() {
    std::cout << "this is the test for the BossGoblin class" << std::endl;

          BossGoblin BossGoblin;
      if (BossGoblin.getLevel() != 10) {
        std::cout << "test 1 failed" << std::endl;
      }
      if (BossGoblin.getHealth() != 100) {
        std::cout << "test 2 failed" << std::endl;
      }
      if (BossGoblin.getHealthCurrent() != (100)) {
        std::cout << "test 3 failed" << std::endl;
      }

      if (BossGoblin.getStrength() != (10)) {
        std::cout << "test 4 failed" << std::endl;
      }

      if (BossGoblin.getMana() != (10)) {
        std::cout << "test 5 failed" << std::endl;
      }
            if (BossGoblin.getLuck() != (10)) {
        std::cout << "test 6 failed" << std::endl;
      }
      if (BossGoblin.getDebuffDamage() != round(BossGoblin.getStrength() / 10)) {
        std::cout << "test 7 failed" << std::endl;
      }
      if (BossGoblin.getIsAlive() != true) {
        std::cout << "test 8 failed" << std::endl;
      }
      if (BossGoblin.getName() != "BFG") {
        std::cout << "test 9 failed" << std::endl;
      }
  }

  void TestPotions() {
    std::cout << "this is the test for the Potion class" << std::endl;
      potion potion(0, 2, 5);
      if (potion.getResetType() != 0) {
        std::cout << "test 1 failed" << std::endl;
      }
      if (potion.getAttribute() != 2) {
        std::cout << "test 2 failed" << std::endl;
      }
      if (potion.getIncrease() != 5) {
        std::cout << "test 3 failed" << std::endl;
      }


  }

  void TestItem() {
    std::cout << "this is the test for the Goblin class" << std::endl;
      item item("fred");
      if (item.getName() != "fred") {
        std::cout << "test 1 failed" << std::endl;
      }
    }

 public:
  Test(){};
  void runtests() {
    testCharacter();
    testPlayer();
    testGoblin();
    testBossGoblin();
    TestPotions();
    TestItem();
  }
};

int main() {
  Test test;
  test.runtests();

  std::string blank;
  std::cin >> blank;
}