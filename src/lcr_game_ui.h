/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef LCR_GAME_UI_H_
#define LCR_GAME_UI_H_

#include <iostream>
#include "lcr_player.h"
#include "lcr_players_list.h"
#include "dice.h"

class LcrGameUi {
 public:
	void ShowGameStart(LcrPlayersList& playersList);
	void ShowGameRound(int turn, int round);
	void ShowCurrentPlayerTurn(LcrPlayer& currentPlayer, int countL, int countR, int countC, int countS);
	void ShowCurrentPlayerTurn(LcrPlayer& currentPlayer);
	void ShowChipPass(LcrPlayer& from, LcrPlayer& to, bool left, int chip_count);
	void ShowChipCenter(LcrPlayer& currentPlayer, int center_chip_count, int chip_count);
	void ShowWinner(LcrPlayer& winningPlayer, int turns);

};

#endif // LCR_GAME_UI_H_
