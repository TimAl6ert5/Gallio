/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef GAME_LCR_H_
#define GAME_LCR_H_

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "dice_lcr.h"
#include "players_list.h"
#include "game_lcr_ui.h"

using namespace std;

class GameLCR {
public:
	GameLCR();

	string GetTitle() const;
	string GetRules();
	Player& PlayGame(PlayersList& playersList);

	static const int kMinPlayers = 3; // must have 3, no upper bound

private:
	static const string title_;
	string rules_;
	DiceLCR game_dice_;
	int center_chips_, turns_;
	GameLcrUi game_ui_;

	void TakeTurn(PlayersList& playersList);

};

#endif // GAME_LCR_H_
