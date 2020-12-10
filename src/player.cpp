/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "player.h"

#define SERIALIZE_DELIMITER '\t'

Player::Player()
	: name_("Unknown"), games_won_(0)
{}

Player::Player(std::string name)
	: name_(name), games_won_(0)
{}

void Player::SetPlayerName(std::string new_name) {
	name_.assign(new_name);
}

std::string Player::GetPlayerName() const {
	return name_;
}

void Player::IncrementGamesWon() {
	games_won_++;
}

void Player::SetGamesWon(const unsigned int won) {
	games_won_ = won;
}

unsigned int Player::GetGamesWon() const {
	return games_won_;
}

void Player::Serialize(std::string& store_string) const {
	std::stringstream ss;
	ss << name_ << SERIALIZE_DELIMITER << games_won_;
	store_string += ss.str();
}

std::vector<std::string> splitTabDelimited(const std::string& tab_string) {
	std::vector<std::string> parts;
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

bool Player::Deserialize(std::string& store_string) {
	std::vector<std::string> parts = splitTabDelimited(store_string);

	if (parts.size() != 2) {
		return false;
	}

	name_ = parts[0];
	try {
		games_won_ = atoi(parts[1].c_str());
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Player::operator <(const Player& other) const {
	return name_ < other.GetPlayerName();
}

bool Player::operator ==(const Player& other) const {
	return name_ == other.GetPlayerName();
}
