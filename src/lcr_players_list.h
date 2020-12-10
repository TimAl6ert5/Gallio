/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef LCR_PLAYERS_LIST_H_
#define LCR_PLAYERS_LIST_H_

#include <vector>
#include <string>
#include "lcr_player.h"

using PlayersVector = std::vector<LcrPlayer>;

/*
* All players in the LCR game.
* 
* Assumes players are in a circle taking one turn at a time in sequence.
*/
class LcrPlayersList {
 public:
	LcrPlayersList();

	void AddPlayer(LcrPlayer player);
	LcrPlayer& GetCurrentPlayer();

	void NextPlayer();
	unsigned int GetNumberOfPlayers() const;

	LcrPlayer& GetPlayerToLeft();
	LcrPlayer& GetPlayerToRight();

	unsigned int CountPlayersWithChips() const;
	LcrPlayer& GetPlayerWithChips();

 private:
	PlayersVector players_;
	unsigned int current_player_index_ = 0;

};

#endif // LCR_PLAYERS_LIST_H_
