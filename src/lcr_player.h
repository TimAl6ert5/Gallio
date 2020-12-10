/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef LCR_PLAYER_H_
#define LCR_PLAYER_H_

#include "player.h"

class LcrPlayer {
 public:
	LcrPlayer(Player& player);

	Player& GetPlayer();
	std::string GetPlayerName() const;

	void SetPlayerChipCount(const int chips);
	int GetPlayerChipCount() const;

	void AddOneChip();
	void RemoveOneChip();

 private:
	Player player_;
	int chip_count_;

};

#endif // LCR_PLAYER_H_
