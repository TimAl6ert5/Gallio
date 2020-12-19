/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef LCR_GAME_H_
#define LCR_GAME_H_

#include <iostream>
#include <fstream>
#include <string>
#include "game.h"
#include "player.h"
#include "lcr_player.h"
#include "lcr_dice.h"
#include "lcr_players_list.h"
#include "lcr_game_ui.h"

class LcrGame : public Game {
 public:
	LcrGame();

	std::string GetGameTitle();
	std::string GetGameRules();
	const Player* PlayGame(std::set<Player>& players);

	static const int kMinPlayers = 3; // must have 3, no upper bound

 private:
	static const std::string title_;
	std::string rules_;
	LcrDice game_dice_;
	int center_chips_, turns_;
	LcrGameUi game_ui_;

	void TakeTurn(LcrPlayersList& playersList);

};

#endif // LCR_GAME_H_
