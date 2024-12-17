#include <iostream>

#include "Base.cpp"
#include "Struct.h"

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
  } else if (randomenemy >= 46 && randomenemy <= 50) {
    opponent.name = "Kraken";
    opponent.health = 500;
    opponent.fullhealth = 500;
    opponent.mana = 300;
    opponent.maxmana = 300;
    opponent.attack = 50;
    opponent.defense = 10;
  } else if (randomenemy >= 51 && randomenemy <= 60) {
    opponent.name = "Riot";
    opponent.health = 300;
    opponent.fullhealth = 300;
    opponent.mana = 100;
    opponent.maxmana = 100;
    opponent.attack = 40;
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
  cout << "5. Dimas | Futsal Player TIC \n";
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
  } else if (choice == 5) {
    player.name = "Dimas";
    player.health = 180;
    player.fullhealth = 180;
    player.attack = 40;
    player.defense = 5;
    player.mana = 100;
    player.maxmana = 100;
  } else {
    cout << "Invalid choice. Please choose a class.\n";
    return ChoseClass(player);
  }

  clearScreen();
}
