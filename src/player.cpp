/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "player.h"

#define SERIALIZE_DELIMITER '\t'

Player::Player()
	: name_("Unknown"), chip_count_(3), games_won_(0)
{}

Player::Player(string name)
	: name_(name), chip_count_(3), games_won_(0)
{}

void Player::SetPlayerName(string new_name) {
	name_.assign(new_name);
}

string Player::GetPlayerName() const {
	return name_;
}

void Player::SetPlayerChipCount(const int chips) {
	chip_count_ = chips;
}

int Player::GetPlayerChipCount() const {
	return chip_count_;
}

void Player::AddOneChip() {
	chip_count_++;
}

void Player::RemoveOneChip() {
	if (chip_count_ > 0) {
		chip_count_--;
	}
}

void Player::IncrementGamesWon() {
	games_won_++;
}

void Player::SetGamesWon(const int won) {
	games_won_ = won;
}

unsigned int Player::GetGamesWon() const {
	return games_won_;
}

void Player::Serialize(std::string& store_string) const {
	stringstream ss;
	ss << name_ << SERIALIZE_DELIMITER << games_won_ << SERIALIZE_DELIMITER << chip_count_;
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

bool Player::Deserialize(std::string& store_string) {
	std::vector<string> parts = splitTabDelimited(store_string);

	if (parts.size() != 3) {
		return false;
	}

	name_ = parts[0];
	try {
		games_won_ = atoi(parts[1].c_str());
		chip_count_ = atoi(parts[2].c_str());
		return true;
	}
	catch (...) {
		return false;
	}
}
