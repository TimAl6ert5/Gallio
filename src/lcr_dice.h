/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef LCR_DICE_H_
#define LCR_DICE_H_

#define MAX_DICE 3

#include <algorithm>
#include "dice.h"

enum class DiceValue {
	L, // Dice roll 1
	R, // Dice roll 2
	C, // Dice roll 3
	Star // ... 4,5,6
};

class LcrDice {
 public:
	LcrDice();

	void RollDice(int player_chip_count);
	int CountL() const;
	int CountR() const;
	int CountC() const;
	int CountStar() const;

 private:
	Dice game_dice_[MAX_DICE];
	int allowed_dice_;

};

#endif // LCR_DICE_H_
