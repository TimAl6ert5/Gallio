/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "dice_lcr.h"

DiceLCR::DiceLCR() 
	: allowed_dice_(MAX_DICE)
{}

void DiceLCR::RollDice(int player_chip_count) {
	allowed_dice_ = std::min(player_chip_count, MAX_DICE);
	for (auto& dice: game_dice_) {
		dice.Roll();
	}
}

int DiceLCR::CountL() const {
	int countL = 0;
	for (int i = 0; i < allowed_dice_; i++) {
		if (game_dice_[i].GetValue() == 1) {
			countL++;
		}
	}
	return countL;
}

int DiceLCR::CountR() const {
	int countR = 0;
	for (int i = 0; i < allowed_dice_; i++) {
		if (game_dice_[i].GetValue() == 2) {
			countR++;
		}
	}
	return countR;
}

int DiceLCR::CountC() const {
	int countC = 0;
	for (int i = 0; i < allowed_dice_; i++) {
		if (game_dice_[i].GetValue() == 3) {
			countC++;
		}
	}
	return countC;
}

int DiceLCR::CountStar() const {
	int countS = 0;
	for (int i = 0; i < allowed_dice_; i++) {
		if (game_dice_[i].GetValue() >= 4 && game_dice_[i].GetValue() <= 6) {
			countS++;
		}
	}
	return countS;
}
