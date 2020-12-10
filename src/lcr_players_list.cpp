/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "lcr_players_list.h"

LcrPlayersList::LcrPlayersList() 
	: players_({})
{}

void LcrPlayersList::AddPlayer(LcrPlayer player) {
	players_.push_back(player);
}

LcrPlayer& LcrPlayersList::GetCurrentPlayer() {
	return players_.at(current_player_index_);
}

void LcrPlayersList::NextPlayer() {
	current_player_index_ = (current_player_index_ + 1) % players_.size();
}

unsigned int LcrPlayersList::GetNumberOfPlayers() const {
	return players_.size();
}

LcrPlayer& LcrPlayersList::GetPlayerToRight() {
	if (current_player_index_ == 0) {
		return players_[players_.size() - 1];
	}
	else {
		return players_[current_player_index_ - 1];
	}
}

LcrPlayer& LcrPlayersList::GetPlayerToLeft() {
	if (current_player_index_ == (players_.size() - 1)) {
		return players_[0];
	}
	else {
		return players_[current_player_index_ + 1];
	}
}

unsigned int LcrPlayersList::CountPlayersWithChips() const {
	int count = 0;
	for (auto& player : players_) {
		if (player.GetPlayerChipCount() > 0) {
			count++;
		}
	}
	return count;
}

LcrPlayer& LcrPlayersList::GetPlayerWithChips() {
	for (auto& player : players_) {
		if (player.GetPlayerChipCount() > 0) {
			return player;
		}
	}
	throw -1;
}
