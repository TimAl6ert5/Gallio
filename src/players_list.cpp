/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#include "players_list.h"

PlayersList::PlayersList() 
	: players({})
{}

PlayersList::~PlayersList() {}

void PlayersList::addPlayer(Player player) {
	players.push_back(player);
}

Player& PlayersList::getCurrentPlayer() {
	return players.at(currentPlayerIndex);
}

void PlayersList::nextPlayer() {
	currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

unsigned int PlayersList::getNumberOfPlayers() const {
	return players.size();
}

Player& PlayersList::getPlayerToRight() {
	if (currentPlayerIndex == 0) {
		return players[players.size() - 1];
	}
	else {
		return players[currentPlayerIndex - 1];
	}
}

Player& PlayersList::getPlayerToLeft() {
	if (currentPlayerIndex == (players.size() - 1)) {
		return players[0];
	}
	else {
		return players[currentPlayerIndex + 1];
	}
}

unsigned int PlayersList::CountPlayersWithChips() const {
	int count = 0;
	for (auto& player : players) {
		if (player.getPlayerChipCount() > 0) {
			count++;
		}
	}
	return count;
}

Player& PlayersList::getPlayerWithChips() {
	for (auto& player : players) {
		if (player.getPlayerChipCount() > 0) {
			return player;
		}
	}
	throw -1;
}
