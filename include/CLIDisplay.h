#ifndef CLIDISPLAY_H
#define CLIDISPLAY_H

#include "Struct.h"

void displayStats(const Character& player, const Character& opponent);

void displayMessageLog();

void AdventureMode(const string& nickname);

void SinglePlayer(const string& nickname);

void Multiplayer(const string& nickname1, const string& nickname2);

void Menu();
#endif
