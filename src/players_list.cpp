/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "players_list.h"

PlayersList::PlayersList() 
	: players_({})
{}

void PlayersList::AddPlayer(Player player) {
	players_.push_back(player);
}

Player& PlayersList::GetCurrentPlayer() {
	return players_.at(current_player_index_);
}

void PlayersList::NextPlayer() {
	current_player_index_ = (current_player_index_ + 1) % players_.size();
}

unsigned int PlayersList::GetNumberOfPlayers() const {
	return players_.size();
}

Player& PlayersList::GetPlayerToRight() {
	if (current_player_index_ == 0) {
		return players_[players_.size() - 1];
	}
	else {
		return players_[current_player_index_ - 1];
	}
}

Player& PlayersList::GetPlayerToLeft() {
	if (current_player_index_ == (players_.size() - 1)) {
		return players_[0];
	}
	else {
		return players_[current_player_index_ + 1];
	}
}

unsigned int PlayersList::CountPlayersWithChips() const {
	int count = 0;
	for (auto& player : players_) {
		if (player.GetPlayerChipCount() > 0) {
			count++;
		}
	}
	return count;
}

Player& PlayersList::GetPlayerWithChips() {
	for (auto& player : players_) {
		if (player.GetPlayerChipCount() > 0) {
			return player;
		}
	}
	throw -1;
}

void PlayersList::Serialize(std::string& store_string) const {
	string temp;
	for (Player p : players_) {
		p.Serialize(temp);
		temp += "\n";
	}
	store_string += temp;
}

bool PlayersList::Deserialize(std::string& store_string) {
	stringstream ss;
	ss.str(store_string);
	string buffer;

	while (getline(ss, buffer, '\n')) {
		Player player("");
		player.Deserialize(buffer);
		AddPlayer(player);
	}

	return false;
}
