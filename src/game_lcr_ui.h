/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#ifndef GAME_LCR_UI_H
#define GAME_LCR_UI_H

#include <algorithm>
#include <iostream>
#include "players_list.h"
#include "dice.h"

class GameLcrUi
{
public:
	void ShowGameStart(PlayersList& playersList);
	void ShowGameRound(int turn, int round);
	void ShowCurrentPlayerTurn(Player& currentPlayer, int countL, int countR, int countC, int countS);
	void ShowCurrentPlayerTurn(Player& currentPlayer);
	void ShowChipPass(Player& from, Player& to, bool left, int chip_count);
	void ShowChipCenter(Player& currentPlayer, int center_chip_count, int chip_count);
};

#endif // GAME_LCR_UI_H
