/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef _GAME_LCR_H
#define _GAME_LCR_H

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "dice_lcr.h"
#include "players_list.h"
#include "game_lcr_ui.h"

using namespace std;

class GameLCR
{
public:
	GameLCR();
	~GameLCR();

	string getTitle() const;
	string getRules();
	Player& PlayGame(PlayersList& playersList);

	static const int minPlayers = 3; // must have 3, no upper bound

private:
	static const string title;
	string rules;
	DiceLCR game_dice;
	int centerChips, turns;
	GameLcrUi game_ui;

	void TakeTurn(PlayersList& playersList);

};

#endif // _GAME_LCR_H
