/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include <string>
#include "lcr_player.h"

LcrPlayer::LcrPlayer(Player& player)
	: player_(player), chip_count_(3)
{}

Player& LcrPlayer::GetPlayer() {
	return player_;
}

std::string LcrPlayer::GetPlayerName() const {
	return player_.GetPlayerName();
}

void LcrPlayer::SetPlayerChipCount(const int chips) {
	chip_count_ = chips;
}

int LcrPlayer::GetPlayerChipCount() const {
	return chip_count_;
}

void LcrPlayer::AddOneChip() {
	chip_count_++;
}

void LcrPlayer::RemoveOneChip() {
	if (chip_count_ > 0) {
		chip_count_--;
	}
}
