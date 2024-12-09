#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct Character {
  string name;
  int health;
  int fullhealth;
  int attack;
  int defense;
  int mana;
};

void displayStats(const Character& player, const Character& opponent) {
  cout << "\n-- " << player.name << " Stats --\n";
  cout << "Health: " << player.health << "\n";
  cout << "Mana: " << player.mana << "\n\n";
  cout << "-- " << opponent.name << " Stats --\n";
  cout << "Health: " << opponent.health << "\n";
  cout << "Mana: " << opponent.mana << "\n";
  cout << "-------------------\n";
}

int randomInRange(int min, int max) { return min + rand() % (max - min + 1); }

void criticalHit(Character& attacker, Character& defender) {
  int damage = max(0, attacker.attack - defender.defense) * 2;
  defender.health -= damage;
  cout << attacker.name << " lands a critical hit for " << damage
       << " damage!\n";
}

void attack(Character& attacker, Character& defender) {
  int damage = max(0, attacker.attack - defender.defense);
  defender.health -= damage;
  cout << attacker.name << " attacks for " << damage << " damage!\n";
}

void critChance(Character& attacker, Character& defender) {
  int chance = randomInRange(0, 100);

  if (chance < 10) {
    criticalHit(attacker, defender);
  } else {
    attack(attacker, defender);
  }
}

void Heal(Character& player) {
  int heal;

  if (player.name == "Heiter") {
    heal = randomInRange(20, 40);
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

void Fireball(Character& player, Character& opponent) {
  if (player.mana >= 20) {
    int damage = max(0, player.attack - opponent.defense) * 2;
    opponent.health -= damage;
    player.mana -= 20;
    cout << "You cast Fireball for " << damage << " damage!\n";
  } else {
    cout << "Not enough mana to cast Fireball. You lose your turn.\n";
  }
}

void playerTurn(Character& player, Character& opponent) {
  int choice;

  if (player.name == "Himmel") {
    cout << "Your turn! Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      critChance(player, opponent);
    } else if (choice == 2) {
      player.defense += 5;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else {
      cout << "Invalid choice. You lose your turn.\n";
    }
  } else if (player.name == "Frieren") {
    cout << "Your turn! Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal\n";
    cout << "4. Fireball\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      attack(player, opponent);
    } else if (choice == 2) {
      player.defense += 5;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else if (choice == 4) {
      Fireball(player, opponent);
    } else {
      cout << "Not enough mana to cast Fireball. You lose your turn.\n";
    }
  } else if (player.name == "Eisen") {
    cout << "Your turn! Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal\n";
    cout << "4. Backstab\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      attack(player, opponent);
    } else if (choice == 2) {
      player.defense += 5;
      cout << "You raise your defense!\n";
    } else if (choice == 3) {
      Heal(player);
    } else if (choice == 4) {
      critChance(player, opponent);
    } else {
      cout << "Invalid choice. You lose your turn.\n";
    }
  } else if (player.name == "Heiter") {
    cout << "Your turn! Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal\n";
    cout << "4. Fireball\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      attack(player, opponent);
    } else if (choice == 2) {
      player.defense += 5;
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
        opponent.defense += 5;
        cout << opponent.name << " raises their defense!\n";
      }
    }
  }
}

void RandomOpponent(Character& opponent) {
  int randomenemy = randomInRange(0, 100);
  if (randomenemy > 0 && randomenemy < 10) {
    opponent.name = "Orc";
    opponent.health = 70;
    opponent.fullhealth = 70;
    opponent.mana = 30;
    opponent.attack = 15;
    opponent.defense = 5;
  } else if (randomenemy > 10 && randomenemy < 20) {
    opponent.name = "Bhuto";
    opponent.health = 50;
    opponent.fullhealth = 50;
    opponent.mana = 20;
    opponent.attack = 10;
    opponent.defense = 5;
  } else if (randomenemy > 20 && randomenemy < 40) {
    opponent.name = "Skeleton";
    opponent.health = 80;
    opponent.fullhealth = 80;
    opponent.mana = 40;
    opponent.attack = 20;
    opponent.defense = 5;
  } else {
    opponent.name = "Goblin";
    opponent.health = 50;
    opponent.fullhealth = 50;
    opponent.mana = 20;
    opponent.attack = 10;
    opponent.defense = 5;
  }
}

void ChoseClass(Character& player) {
  int choice;
  cout << "Choose a class:\n";
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
  } else if (choice == 2) {
    player.name = "Frieren";
    player.health = 70;
    player.fullhealth = 70;
    player.attack = 30;
    player.defense = 3;
    player.mana = 100;
  } else if (choice == 3) {
    player.name = "Eisen";
    player.health = 80;
    player.fullhealth = 80;
    player.attack = 25;
    player.defense = 4;
    player.mana = 70;
  } else if (choice == 4) {
    player.name = "Heiter";
    player.health = 90;
    player.fullhealth = 90;
    player.attack = 25;
    player.defense = 5;
    player.mana = 80;
  } else {
    cout << "Invalid choice. Please choose a class.\n";
    return ChoseClass(player);
  }
}

void SinglePlayer() {
  cout << "Single Player Mode\n";
  Character player;
  ChoseClass(player);
  Character opponent;
  RandomOpponent(opponent);
  cout << "Welcome to the Turn-Based Fighting Game!\n";

  while (player.health > 0 && opponent.health > 0) {
    displayStats(player, opponent);

    cout << "Player's turn!\n";

    playerTurn(player, opponent);

    if (opponent.health <= 0) {
      cout << "You defeated the opponent! Congratulations!\n";
      break;
    }

    cout << "\n";
    cout << "Opponent's turn!\n";

    opponentTurn(opponent, player);

    if (player.health <= 0) {
      cout << "You were defeated by the opponent. Game over.\n";
      break;
    }

    player.defense = 5;
    opponent.defense = 5;
    player.mana += 1;
    cout << "\n";
    cout << "-- Next Round --\n";
  }
}

void Multiplayer() {
  cout << "Multiplayer Mode\n";
  Character player1;
  ChoseClass(player1);
  Character player2;
  ChoseClass(player2);
  cout << "Welcome to the Turn-Based Fighting Game!\n";

  while (player1.health > 0 && player2.health > 0) {
    displayStats(player1, player2);

    cout << "Player 1's turn!\n";

    playerTurn(player1, player2);

    if (player2.health <= 0) {
      cout << "Player 1 defeated Player 2! Congratulations!\n";
      break;
    }

    cout << "\n";
    cout << "Player 2's turn!\n";

    playerTurn(player2, player1);

    if (player1.health <= 0) {
      cout << "Player 2 defeated Player 1! Congratulations!\n";
      break;
    }

    player1.defense = 5;
    player2.defense = 5;
    player1.mana += 1;
    player2.mana += 1;
    cout << "\n";
    cout << "-- Next Round --\n";
  }
}

void Menu() {
  cout << "Chose your game mode:\n";
  cout << "1. Single Player\n";
  cout << "2. Multiplayer\n";
  cout << "3. Exit\n";

  cout << "Enter your choice: ";
  int choice;
  cin >> choice;
  cout << "\n";

  switch (choice) {
    case 1:
      SinglePlayer();
      break;
    case 2:
      Multiplayer();
      break;
    case 3:
      cout << "Exit\n";
      break;
    default:
      cout << "Invalid choice. Please choose a game mode.\n";
      return Menu();
  }
}

int main() {
  srand(static_cast<unsigned int>(time(0)));
  Menu();
  return 0;
}
