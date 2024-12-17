#include <iostream>

#include "Character.cpp"

void attack(Character& attacker, Character& defender) {
  int miss = randomInRange(0, 100);

  if (miss < 10) {
    cout << attacker.name << " missed the attack!\n";
    return;
  }

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
  int miss = randomInRange(0, 100);

  if (miss < 10) {
    cout << attacker.name << " missed the attack!\n";
    return;
  }

  if (chance < 10) {
    criticalHit(attacker, defender);
    return;
  } else {
    attackforcrit(attacker, defender);
    return;
  }
}

void Heal(Character& player) {
  int heal;

  if (player.name == "Heiter") {
    heal = randomInRange(40, 60);
    if (player.mana >= 10) {
      if (player.health == player.fullhealth) {
        cout << player.name
             << " are already at full health. You lose your turn.\n";
        return;
      } else if (player.health + heal > player.fullhealth) {
        int heal = player.fullhealth - player.health;
        player.health += heal;
        player.mana -= 10;
        cout << player.name << " heal for " << heal << " health points!\n";
        return;
      }
    } else {
      cout << "Not enough mana to heal. You lose your turn.\n";
      return;
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
      cout << player.name << " heal for " << heal << " health points!\n";
      return;
    }
  } else {
    cout << "Not enough mana to heal. You lose your turn.\n";
    return;
  }
}

void manaRegen(Character& player) {
  if (player.mana < player.maxmana) {
    player.mana += 2;
  }
}

void Fireball(Character& player, Character& opponent) {
  int miss = randomInRange(0, 100);

  if (miss < 10) {
    cout << player.name << " missed the attack!\n";
    return;
  }

  if (player.mana >= 60) {
    int damage = max(0, player.attack - opponent.defense) * 2;
    opponent.health -= damage;
    player.mana -= 60;
    cout << player.name << " cast Fireball for " << damage << " damage!\n";
    return;
  } else {
    cout << "Not enough mana to cast Fireball. You lose your turn.\n";
    return;
  }
}

void WaterCanon(Character& player, Character& opponent) {
  int miss = randomInRange(0, 100);

  if (miss < 10) {
    cout << player.name << " missed the attack!\n";
    return;
  }

  if (player.mana >= 60) {
    int damage = max(0, player.attack - opponent.defense) * 2;
    opponent.health -= damage;
    player.mana -= 60;
    cout << player.name << " cast Water Canon for " << damage << " damage!\n";
    return;
  } else {
    cout << "Not enough mana to cast Water Canon. You lose your turn.\n";
    return;
  }
}

void WorldCuttingSlash(Character& player, Character& opponent) {
  int miss = randomInRange(0, 100);

  if (miss < 10) {
    cout << player.name << " missed the attack!\n";
    return;
  }

  if (player.mana >= 60) {
    int damage = max(0, player.attack - opponent.defense) * 2;
    opponent.health -= damage;
    player.mana -= 60;
    cout << player.name << " cast World Cutting Slash for " << damage
         << " damage!\n";
  } else {
    cout
        << "Not enough mana to cast World Cutting Slash. You lose your turn.\n";
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
  } else if (player.name == "Dimas") {
    cout << player.nickname << " Turn " << "Choose an action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. Heal | Mana cost: 10\n";
    cout << "4. Fireball | Mana cost: 60\n";
    cout << "5. Futsal Kick | Mana cost: 20\n";
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
    } else if (choice == 5) {
      if (player.mana >= 20) {
        int damage = max(0, player.attack - opponent.defense) * 3;
        opponent.health -= damage;
        player.mana -= 20;
        cout << "You cast Futsal Kick for " << damage << " damage!\n";
      } else {
        cout << "Not enough mana to cast Futsal Kick. You lose your turn.\n";
      }
    } else {
      cout << "Invalid choice. You lose your turn.\n";
    }
  } else {
    cout << "Invalid choice. You lose your turn.\n";
  }
}

void opponentTurn(Character& opponent, Character& player) {
  int choice = randomInRange(0, 2);
  int skillchoice = randomInRange(0, 2);

  if (opponent.name == "Orc" && opponent.health < 30) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else if (choice == 1) {
      critChance(opponent, player);
      return;
    } else {
      attack(opponent, player);
      return;
    }
  } else if (opponent.name == "Orc") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      Heal(opponent);
      return;
    }
  }

  if (opponent.name == "Bhuto" && opponent.health < 20) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else if (choice == 1) {
      critChance(opponent, player);
      return;
    } else {
      attack(opponent, player);
      return;
    }
  } else if (opponent.name == "Bhuto") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      Heal(opponent);
      return;
    }
  }

  if (opponent.name == "Skeleton" && opponent.health < 40) {
    if (choice == 0) {
      Heal(opponent);
      return;
    } else if (choice == 1) {
      critChance(opponent, player);
      return;
    } else {
      attack(opponent, player);
      return;
    }
  } else if (opponent.name == "Skeleton") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      Heal(opponent);
      return;
    }
  }

  if (opponent.name == "Goblin" && opponent.health < 30) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else {
      critChance(opponent, player);
      return;
    }
  } else if (opponent.name == "Goblin") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      Heal(opponent);
      return;
    }
  }

  if (opponent.name == "Fire Dragon" && opponent.health < 100) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else {
      if (skillchoice == 0) {
        critChance(opponent, player);
        return;
      } else if (skillchoice == 1) {
        attack(opponent, player);
        return;
      } else {
        Fireball(opponent, player);
        return;
      }
    }
  } else if (opponent.name == "Fire Dragon") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      Fireball(opponent, player);
      return;
    }
  }

  if (opponent.name == "Kraken" && opponent.health < 100) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else {
      if (skillchoice == 0) {
        critChance(opponent, player);
        return;
      } else if (skillchoice == 1) {
        attack(opponent, player);
        return;
      } else {
        WaterCanon(opponent, player);
        return;
      }
    }
  } else if (opponent.name == "Kraken") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      WaterCanon(opponent, player);
      return;
    }
  }

  if (opponent.name == "The Conqueror" && opponent.health < 200) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else {
      if (skillchoice == 0) {
        critChance(opponent, player);
        return;
      } else if (skillchoice == 1) {
        attack(opponent, player);
        return;
      } else {
        WorldCuttingSlash(opponent, player);
        return;
      }
    }
  } else if (opponent.name == "The Conqueror") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      WorldCuttingSlash(opponent, player);
      return;
    }
  }

  if (opponent.name == "Riot" && opponent.health < 100) {
    if (choice < 2) {
      Heal(opponent);
      return;
    } else {
      if (skillchoice == 0) {
        critChance(opponent, player);
        return;
      } else if (skillchoice == 1) {
        attack(opponent, player);
        return;
      } else {
        WorldCuttingSlash(opponent, player);
        return;
      }
    }
  } else if (opponent.name == "Riot") {
    if (choice == 0) {
      critChance(opponent, player);
      return;
    } else if (choice == 1) {
      attack(opponent, player);
      return;
    } else {
      WorldCuttingSlash(opponent, player);
    }
  }
}
