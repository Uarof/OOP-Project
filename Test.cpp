#include "files.h"

class Test {
 private:
  void testCharacter() {
    std::cout << "this is the test for the character class" << std::endl;
    
    void testLevelCharacter() {
      Character character();
      if (character.getLevel() != 0) {
        std::cout << "test 1 failed" << std::endl;
      }
    }

    void testHealthMaxCharacter() {
      Character character();
      if (character.getHealth() != 0) {
        std::cout << "test 2 failed" << std::endl;
      }
    }

    void testHealthCurrentCharacter() {
      Character character();
      if (character.getHealthCurrent() != 0) {
        std::cout << "test 3 failed" << std::endl;
      }
    }

    void testStrengthCharacter() {
      Character character();
      if (character.getStrength() != 0) {
        std::cout << "test 4 failed" << std::endl;
      }
    }

    void testManaCharacter() {
      Character character();
      if (character.getMana() != 0) {
        std::cout << "test 5 failed" << std::endl;
      }
    }

    void testLuckCharacter() {
      Character character();
      if (character.getLuck() != 0.0) {
        std::cout << "test 6 failed" << std::endl;
      }
    }

    void testIsAliveCharacter() {
      Character character();
      if (character.getIsAlive() != true) {
        std::cout << "test 7 failed" << std::endl;
      }
    }

    // void testTakeDamage() {
    //   Character character();
    //   if (character.take_damage(5) != character.getHealthCurrent) {
    //     std::cout << "test 7 failed" << std::endl;
    //   }
    // }
  }

  void testPlayer() {
    std::cout << "this is the test for the Player class" << std::endl;
    void testLevelWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getLevel() != 1) {
        std::cout << "test 1 failed" << std::endl;
      }
    }

    void testHealthMaxWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getHealth() != 8) {
        std::cout << "test 2 failed" << std::endl;
      }
    }

    void testHealthCurrentWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getHealthCurrent() != 8) {
        std::cout << "test 3 failed" << std::endl;
      }
    }

    void testStrengthWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getStrength() != 8) {
        std::cout << "test 4 failed" << std::endl;
      }
    }

    void testManaWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getMana() != 1) {
        std::cout << "test 5 failed" << std::endl;
      }
    }

    void testLuckWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getLuck() != 0.5) {
        std::cout << "test 6 failed" << std::endl;
      }
    }

    void testIsAliveWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getIsAlive() != true) {
        std::cout << "test 7 failed" << std::endl;
      }
    }

    void testNameWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getName() != fred) {
        std::cout << "test 8 failed" << std::endl;
      }
    }
    
    void testGetTypeWarrior() {
      Player Warrior(fred, Warrior);
      if (character.getType() != Warrior) {
        std::cout << "test 9 failed" << std::endl;
      }
    }        
  }

  void testGoblin() {
    std::cout << "this is the test for the Goblin class" << std::endl;
    
    void testLevelGoblin() {
      Goblin Goblin(5);
      if (Goblin.getLevel() != 5) {
        std::cout << "test 1 failed" << std::endl;
      }
    }

    void testHealthMaxGoblin() {
      Goblin Goblin(5);
      if (Goblin.getHealth() != (2*5+1)) {
        std::cout << "test 2 failed" << std::endl;
      }
    }

    void testHealthCurrentGoblin() {
      Goblin Goblin(5);
      if (Goblin.getHealthCurrent() != (2*5+1)) {
        std::cout << "test 3 failed" << std::endl;
      }
    }

    void testStrengthGoblin() {
      Goblin Goblin(5);
      if (Goblin.getStrength() != (2*5+1)) {
        std::cout << "test 4 failed" << std::endl;
      }
    }

    void testManaGoblin() {
      Goblin Goblin(5);
      if (Goblin.getMana() != (2*5+1)) {
        std::cout << "test 5 failed" << std::endl;
      }
    }

    void testLuckGoblin() {
      Goblin Goblin(5);
      if (Goblin.getLuck() != (2*5+1)) {
        std::cout << "test 6 failed" << std::endl;
      }
    }

    void testIsAliveGoblin() {
      Goblin Goblin(5);
      if (Goblin.getIsAlive() != true) {
        std::cout << "test 7 failed" << std::endl;
      }
    }
  }

  void testBossGoblin() {
    std::cout << "this is the test for the BossGoblin class" << std::endl;
    
    void testLevelBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getLevel() != 10) {
        std::cout << "test 1 failed" << std::endl;
      }
    }

    void testHealthMaxBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getHealth() != 100) {
        std::cout << "test 2 failed" << std::endl;
      }
    }

    void testHealthCurrentBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getHealthCurrent() != (100)) {
        std::cout << "test 3 failed" << std::endl;
      }
    }

    void testStrengthBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getStrength() != (10)) {
        std::cout << "test 4 failed" << std::endl;
      }
    }

    void testManaBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getMana() != (10)) {
        std::cout << "test 5 failed" << std::endl;
      }
    }

    void testLuckBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.get_debuff_damage() != (10)) {
        std::cout << "test 6 failed" << std::endl;
      }
    }

    void testLuckBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getLuck() != round(BossGoblin.getStrength() / 10)) {
        std::cout << "test 7 failed" << std::endl;
      }
    }

    void testIsAliveBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getIsAlive() != true) {
        std::cout << "test 8 failed" << std::endl;
      }
    }

    void testIsAliveBossGoblin() {
      BossGoblin BossGoblin();
      if (BossGoblin.getname() != "BFG") {
        std::cout << "test 9 failed" << std::endl;
      }
    }
  }

  void TestPotions() {
    std::cout << "this is the test for the Goblin class" << std::endl;
    
    void testPotionResettype() {
      potion potion(0, 2, 5);
      if (potion.get_reset_type() != 0) {
        std::cout << "test 1 failed" << std::endl;
      }
    }
    void testPotionAttribute() {
      potion potion(0, 2, 5);
      if (potion.get_reset_type() != 2) {
        std::cout << "test 2 failed" << std::endl;
      }
    }
    void testPotionAttribute() {
      potion potion(0, 2, 5);
      if (potion.get_increase() != 5) {
        std::cout << "test 2 failed" << std::endl;
      }
    }          
  } 

 public:
  void runtests() { 
    testCharacter();
    testPlayer();
    testGoblin();
    testBossGoblin();
    TestPotions();
  }
};
