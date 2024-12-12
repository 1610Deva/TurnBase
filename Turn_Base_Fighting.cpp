#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct Character {
  string nickname;
  string name;
  int health;
  int fullhealth;
  int attack;
  int defense;
  int mana;
  int maxmana;
};

void displayStats(const Character& player, const Character& opponent) {
  cout << "\n-- " << player.nickname << " (" << player.name << ") Stats --\n";
  cout << "Health: " << player.health << "\n";
  cout << "Mana: " << player.mana << "\n\n";
  cout << "-- " << opponent.name << " Stats --\n";
  cout << "Health: " << opponent.health << "\n";
  cout << "Mana: " << opponent.mana << "\n";
  cout << "-------------------\n";
}

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void displayMessageLog() {
  cout << "Press Enter to continue...\n";
  cin.ignore();
  cin.get();
  clearScreen();
}

int randomInRange(int min, int max) { return min + rand() % (max - min + 1); }

void attack(Character& attacker, Character& defender) {
  int damage = max(0, attacker.attack - defender.defense);
  defender.health -= damage;
  cout << attacker.name << " attacks for " << damage << " damage!\n";
}

void criticalHit(Character& attacker, Character& defender) {
  int damage = max(0, attacker.attack - defender.defense) * 2;
  defender.health -= damage;
  cout << attacker.name << " lands a critical hit for " << damage
       << " damage!\n";
}

void attackforcrit(Character& attacker, Character& defender) {
  int damage = max(0, attacker.attack - defender.defense);
  defender.health -= damage;
  attacker.mana -= 7;
  cout << attacker.name << " attacks for " << damage << " damage!\n";
}

void critChance(Character& attacker, Character& defender) {
  int chance = randomInRange(0, 100);

  if (chance < 10) {
    criticalHit(attacker, defender);
  } else {
    attackforcrit(attacker, defender);
  }
}

void Heal(Character& player) {
  int heal;

  if (player.name == "Heiter") {
    heal = randomInRange(40, 60);
    if (player.mana >= 10) {
      if (player.health == player.fullhealth) {
        cout << "You are already at full health. You lose your turn.\n";
        return;
      } else if (player.health + heal > player.fullhealth) {
        int heal = player.fullhealth - player.health;
        player.health += heal;
        player.mana -= 10;
        cout << "You heal for " << heal << " health points!\n";
        return;
      }
    } else {
      cout << "Not enough mana to heal. You lose your turn.\n";
    }
  }

  heal = randomInRange(10, 30);
  if (player.mana >= 10) {
    if (player.health == player.fullhealth) {
      cout << "You are already at full health. You lose your turn.\n";
      return;
    } else if (player.health + heal > player.fullhealth) {
      int heal = player.fullhealth - player.health;
      player.health += heal;
      player.mana -= 10;
      cout << "You heal for " << heal << " health points!\n";
      return;
    }
  } else {
    cout << "Not enough mana to heal. You lose your turn.\n";
  }
}

void manaRegen(Character& player) {
  if (player.mana < player.maxmana) {
    player.mana += 1;
  }
}

void Fireball(Character& player, Character& opponent) {
  if (player.mana >= 60) {
    int damage = max(0, player.attack - opponent.defense) * 2;
    opponent.health -= damage;
    player.mana -= 60;
    cout << "You cast Fireball for " << damage << " damage!\n";
  } else {
    cout << "Not enough mana to cast Fireball. You lose your turn.\n";
  }
}

void playerTurn(Character& player, Character& opponent) {
  int choice;

  if (player.name == "Himmel") {
    cout << player.nickname << " Turn " << "Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal | Mana cost: 10\n";
    cout << "Your Choice: ";
    cin >> choice;
    cout << "\n";

    if (choice == 1) {
      critChance(player, opponent);
    } else if (choice == 2) {
      player.defense += 10;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else {
      cout << "Invalid choice. You lose your turn.\n";
    }
  } else if (player.name == "Frieren") {
    cout << player.nickname << " Turn " << "Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal | Mana cost: 10\n";
    cout << "4. Fireball | Mana cost: 60\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      attack(player, opponent);
    } else if (choice == 2) {
      player.defense += 10;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else if (choice == 4) {
      Fireball(player, opponent);
    } else {
      cout << "Not enough mana to cast Fireball. You lose your turn.\n";
    }
  } else if (player.name == "Eisen") {
    cout << player.nickname << " Turn " << "Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal | Mana cost: 10\n";
    cout << "4. Backstab\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      attack(player, opponent);
    } else if (choice == 2) {
      player.defense += 10;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else if (choice == 4) {
      critChance(player, opponent);
    } else {
      cout << "Invalid choice. You lose your turn.\n";
    }
  } else if (player.name == "Heiter") {
    cout << player.nickname << " Turn " << "Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal | Mana cost: 10\n";
    cout << "4. Fireball | Mana cost: 60\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      attack(player, opponent);
    } else if (choice == 2) {
      player.defense += 10;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else if (choice == 4) {
      Fireball(player, opponent);
    } else {
      cout << "Not enough mana to cast Fireball. You lose your turn.\n";
    }
  } else {
    cout << "Invalid choice. You lose your turn.\n";
  }
}

void opponentTurn(Character& opponent, Character& player) {
  int choice = randomInRange(0, 2);

  if (opponent.name == "Orc" && opponent.health < 30) {
    if (choice == 0) {
      Heal(opponent);
      return;
    } else {
      critChance(opponent, player);
    }
  } else if (opponent.name == "Bhuto" && opponent.health < 20) {
    if (choice == 0) {
      Heal(opponent);
      return;
    } else {
      critChance(opponent, player);
    }
  } else if (opponent.name == "Skeleton" && opponent.health < 40) {
    if (choice == 0) {
      Heal(opponent);
      return;
    } else {
      critChance(opponent, player);
    }
  } else {
    critChance(opponent, player);
  }

  if (opponent.name == "Goblin" && opponent.health < 20) {
    if (choice == 0) {
      Heal(opponent);
      return;
    } else {
      if (choice == 0) {
        critChance(opponent, player);
      } else {
        opponent.defense += 10;
        cout << opponent.name << " raises their defense!\n";
      }
    }
  }
}

void RandomOpponent(Character& opponent) {
  int randomenemy = randomInRange(0, 100);
  if (randomenemy >= 1 && randomenemy <= 10) {
    opponent.name = "Orc";
    opponent.health = 150;
    opponent.fullhealth = 150;
    opponent.mana = 30;
    opponent.maxmana = 30;
    opponent.attack = 15;
    opponent.defense = 5;
  } else if (randomenemy >= 11 && randomenemy <= 20) {
    opponent.name = "Bhuto";
    opponent.health = 130;
    opponent.fullhealth = 130;
    opponent.mana = 20;
    opponent.maxmana = 20;
    opponent.attack = 25;
    opponent.defense = 5;
  } else if (randomenemy >= 21 && randomenemy <= 40) {
    opponent.name = "Skeleton";
    opponent.health = 140;
    opponent.fullhealth = 140;
    opponent.mana = 40;
    opponent.maxmana = 40;
    opponent.attack = 20;
    opponent.defense = 5;
  } else if (randomenemy >= 41 && randomenemy <= 45) {
    opponent.name = "Dragon";
    opponent.health = 500;
    opponent.fullhealth = 500;
    opponent.mana = 100;
    opponent.maxmana = 100;
    opponent.attack = 50;
    opponent.defense = 10;
  } else {
    opponent.name = "Goblin";
    opponent.health = 100;
    opponent.fullhealth = 100;
    opponent.mana = 20;
    opponent.maxmana = 20;
    opponent.attack = 20;
    opponent.defense = 5;
  }
}

void ChoseClass(Character& player) {
  clearScreen();
  int choice;
  cout << "|       | Welcome to the Turn-Based Fighting Game! |       | \n\n";
  cout << player.nickname << " Choose a class:\n\n";
  cout << "1. Himmel | Warrior\n";
  cout << "2. Frieren | Mage\n";
  cout << "3. Eisen | Dwarf\n";
  cout << "4. Heiter | Priest\n";
  cout << "Your Choice: ";
  cin >> choice;
  cout << "\n";

  if (choice == 1) {
    player.name = "Himmel";
    player.health = 100;
    player.fullhealth = 100;
    player.attack = 20;
    player.defense = 5;
    player.mana = 50;
    player.maxmana = 50;
  } else if (choice == 2) {
    player.name = "Frieren";
    player.health = 60;
    player.fullhealth = 60;
    player.attack = 30;
    player.defense = 3;
    player.mana = 100;
    player.maxmana = 100;
  } else if (choice == 3) {
    player.name = "Eisen";
    player.health = 80;
    player.fullhealth = 80;
    player.attack = 25;
    player.defense = 4;
    player.mana = 70;
    player.maxmana = 70;
  } else if (choice == 4) {
    player.name = "Heiter";
    player.health = 90;
    player.fullhealth = 90;
    player.attack = 25;
    player.defense = 5;
    player.mana = 80;
    player.maxmana = 80;
  } else {
    cout << "Invalid choice. Please choose a class.\n";
    return ChoseClass(player);
  }

  clearScreen();
}

void AdventureMode(const string& nickname) {
  clearScreen();
  Character player;
  player.nickname = nickname;
  ChoseClass(player);
  Character opponent;
  cout << "|       | Welcome to the Turn-Based Fighting Game! |       | \n";

  for (int i = 0; i < 5; i++) {
    player.health = player.fullhealth;
    player.mana = player.maxmana;
    player.defense = 5;
    if (i == 4) {
      opponent.name = "The Conqueror";
      opponent.health = 800;
      opponent.fullhealth = 800;
      opponent.mana = 200;
      opponent.maxmana = 200;
      opponent.attack = 50;
      opponent.defense = 10;

      cout << "Seems like you have reached the final boss! \n";
      cout << "suddenly you got a buff from the sky. \n";

      player.health = player.fullhealth + 100;
      player.mana = player.maxmana + 100;
      player.attack = player.attack + 20;
      player.defense = player.defense + 5;

      cout << "You have encountered a " << opponent.name << "!\n";
      cout << "Prepare for battle!\n";
      cout << "Press Enter to continue...\n";
      cin.ignore();
      cin.get();
      clearScreen();

      while (player.health > 0 && opponent.health > 0) {
        displayStats(player, opponent);
        playerTurn(player, opponent);
        if (opponent.health <= 0) {
          cout << endl;
          cout << "   _____        __      _______     \n\n";
          cout << "|          | Victory |           | \n";
          cout << "    Congratulations " << player.nickname
               << " is the winner \n";
          cout << "   _____        __      _______     \n\n";
          break;
        }
        opponentTurn(opponent, player);
        if (player.health <= 0) {
          cout << "You were defeated by the opponent. Game over.\n";
          break;
        }
        player.defense = 5;
        opponent.defense = 5;
        manaRegen(player);
        manaRegen(opponent);

        if (player.health <= 0 && opponent.health <= 0) {
          cout << "Both players were defeated. Game over.\n";
          break;
        }
        displayMessageLog();
      }
    } else {
      RandomOpponent(opponent);
      cout << "You have encountered a " << opponent.name << "!\n";
      cout << "Prepare for battle!\n";
      cout << "Press Enter to continue...\n";
      cin.ignore();
      cin.get();
      clearScreen();

      while (player.health > 0 && opponent.health > 0) {
        displayStats(player, opponent);
        playerTurn(player, opponent);
        if (opponent.health <= 0) {
          cout << endl;
          cout << "   _____        __      _______     \n\n";
          cout << "|          | Victory |           | \n";
          cout << "    Congratulations " << player.nickname
               << " is the winner \n";
          cout << "   _____        __      _______     \n\n";
          break;
        }
        opponentTurn(opponent, player);
        if (player.health <= 0) {
          cout << "You were defeated by the opponent. Game over.\n";
          break;
        }
        player.defense = 5;
        opponent.defense = 5;
        manaRegen(player);
        manaRegen(opponent);

        if (player.health <= 0 && opponent.health <= 0) {
          cout << "Both players were defeated. Game over.\n";
          break;
        }
        displayMessageLog();
      }
    }
  }
}

void SinglePlayer(const string& nickname) {
  clearScreen();
  Character player;
  player.nickname = nickname;
  ChoseClass(player);
  Character opponent;
  RandomOpponent(opponent);
  cout << "|       | Welcome to the Turn-Based Fighting Game! |       | \n";

  while (player.health > 0 && opponent.health > 0) {
    displayStats(player, opponent);
    playerTurn(player, opponent);

    if (opponent.health <= 0) {
      cout << endl;
      cout << "   _____        __      _______     \n\n";
      cout << "|          | Victory |           | \n";
      cout << "   Congratulations " << player.nickname << " is the winner \n";
      cout << "   _____        __      _______     \n\n";

      cout << " press Enter to continue fight ... \n";
      cin.ignore();
      cin.get();
      clearScreen();
      return SinglePlayer(nickname);
      break;
    }

    opponentTurn(opponent, player);

    if (player.health <= 0) {
      cout << "You were defeated by the opponent. Game over.\n";
      break;
    }
    player.defense = 5;
    opponent.defense = 5;
    manaRegen(player);
    manaRegen(opponent);

    if (player.health <= 0 && opponent.health <= 0) {
      cout << "Both players were defeated. Game over.\n";
      break;
    }
    displayMessageLog();
  }
}

void Multiplayer(const string& nickname1, const string& nickname2) {
  Character player1, player2;
  clearScreen();
  player1.nickname = nickname1;
  player2.nickname = nickname2;

  ChoseClass(player1);
  ChoseClass(player2);
  cout << "|       | Welcome to the Turn-Based Fighting Game! |       |\n";

  while (player1.health > 0 && player2.health > 0) {
    displayStats(player1, player2);
    playerTurn(player1, player2);
    if (player2.health <= 0) {
      cout << endl;
      cout << "   _____        __      _______     \n\n";
      cout << "|          | Victory |           | \n";
      cout << "    Congratulations " << player1.nickname << " is the winner \n";
      cout << "   _____        __      _______     \n\n";
      break;
    }
    playerTurn(player2, player1);
    if (player1.health <= 0) {
      cout << endl;
      cout << "   _____        __      _______     \n\n";
      cout << "|          | Victory |           |\\n";
      cout << "    Congratulations " << player2.nickname << " is the winner\n";
      cout << "   _____        __      _______     \n\n";
      break;
    }
    player1.defense = 5;
    player2.defense = 5;
    manaRegen(player1);
    manaRegen(player2);

    if (player1.health <= 0 && player2.health <= 0) {
      cout << "Both players were defeated. Game over.\n";
      break;
    }
    displayMessageLog();
  }
}

void Menu() {
  cout << "|       | Welcome to the Turn-Based Fighting Game! |       | \n";
  cout << "------------------------------------------------------------ \n\n";

  cout << "Chose your game mode:\n";
  cout << "1. Single Player\n";
  cout << "2. Multiplayer\n";
  cout << "3. Adventure Mode\n";
  cout << "4. Exit\n";
  cout << "Enter your choice: ";
  int choice;
  cin >> choice;
  cout << "\n";

  string nickname1, nickname2;

  if (choice == 1) {
    cout << "Enter your nickname: ";
    cin >> nickname1;
    cout << "\n";
    SinglePlayer(nickname1);
  } else if (choice == 2) {
    cout << "Enter Player 1's nickname: ";
    cin >> nickname1;
    cout << "Enter Player 2's nickname: ";
    cin >> nickname2;
    Multiplayer(nickname1, nickname2);
  } else if (choice == 3) {
    cout << "Enter your nickname: ";
    cin >> nickname1;
    cout << "\n";
    AdventureMode(nickname1);
  } else if (choice == 4) {
    cout << "Goodbye!\n";
    exit(0);
  } else {
    cout << "Invalid choice. Please choose a valid option.\n";
    Menu();
  }
}

int main() {
  srand(static_cast<unsigned int>(time(0)));
  clearScreen();
  Menu();
  return 0;
}
