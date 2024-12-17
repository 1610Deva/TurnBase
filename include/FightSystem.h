#ifndef FIGHTSYSTEM_H
#define FIGHTSYSTEM_H

#include "Struct.h"

void attack(Character& attacker, Character& defender);

void criticalHit(Character& attacker, Character& defender);

void attackforcrit(Character& attacker, Character& defender);

void critChance(Character& attacker, Character& defender);

void heal(Character& player);

void manaRegen(Character& player);

void Fireball(Character& player, Character& opponent);

void WaterCanon(Character& player, Character& opponent);

void WorldCuttingSlash(Character& player, Character& opponent);

void playerTurn(Character& player, Character& opponent);

void opponentTurn(Character& player, Character& opponent);

#endif
