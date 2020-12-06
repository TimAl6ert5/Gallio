/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "player.h"

#define SERIALIZE_DELIMITER '\t'

Player::Player()
	: name("Unknown"), chipCount(3), games_won(0)
{}

Player::Player(string name)
	: name(name), chipCount(3), games_won(0)
{}

Player::~Player() {}

void Player::setPlayerName(string new_name) {
	name.assign(new_name);
}

string Player::getPlayerName() const {
	return name;
}

void Player::setPlayerChipCount(const int chips) {
	chipCount = chips;
}

int Player::getPlayerChipCount() const {
	return chipCount;
}

void Player::addOneChip() {
	chipCount++;
}

void Player::removeOneChip() {
	if (chipCount > 0) {
		chipCount--;
	}
}

void Player::incrementGamesWon() {
	games_won++;
}

void Player::setGamesWon(const int won) {
	games_won = won;
}

unsigned int Player::getGamesWon() const {
	return games_won;
}

void Player::serialize(std::string& store_string) const {
	stringstream ss;
	ss << name << SERIALIZE_DELIMITER << games_won << SERIALIZE_DELIMITER << chipCount;
	store_string += ss.str();
}

std::vector<string> splitTabDelimited(const std::string& tab_string) {
	std::vector<string> parts;
	std::size_t left_index = 0, right_index;
	std::string s_buf;

	right_index = tab_string.find(SERIALIZE_DELIMITER);
	while (right_index != std::string::npos) {
		s_buf = tab_string.substr(left_index, right_index);
		parts.push_back(s_buf);
		left_index = right_index + 1;
		right_index = tab_string.find(SERIALIZE_DELIMITER, left_index);
	}
	parts.push_back(tab_string.substr(left_index, tab_string.length()));

	return parts;
}

bool Player::deserialize(std::string& store_string) {
	std::vector<string> parts = splitTabDelimited(store_string);

	if (parts.size() != 3) {
		return false;
	}

	name = parts[0];
	try {
		games_won = atoi(parts[1].c_str());
		chipCount = atoi(parts[2].c_str());
		return true;
	}
	catch (...) {
		return false;
	}
}
