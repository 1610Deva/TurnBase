#include <iostream>
#include <string>

#include "FightSystem.cpp"
#include "Struct.h"

using namespace std;

void displayStats(const Character& player, const Character& opponent) {
  cout << "\n-- " << player.nickname << " (" << player.name << ") Stats --\n";
  cout << "Health: " << player.health << "\n";
  cout << "Mana: " << player.mana << "\n\n";
  cout << "-- " << opponent.name << " Stats --\n";
  cout << "Health: " << opponent.health << "\n";
  cout << "Mana: " << opponent.mana << "\n";
  cout << "-------------------\n";
}

void displayMessageLog() {
  cout << "Press Enter to continue...\n";
  cin.ignore();
  cin.get();
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
