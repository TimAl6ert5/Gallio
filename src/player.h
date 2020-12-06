/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <sstream>
#include <vector>
#include "serializable.h"

using namespace std;

class Player : public Serializable {
public:
	Player();
	Player(string name);

	void SetPlayerName(string name);
	string GetPlayerName() const;
	void SetPlayerChipCount(const int chips);
	int GetPlayerChipCount() const;

	void AddOneChip();
	void RemoveOneChip();

	void IncrementGamesWon();
	void SetGamesWon(const int won);
	unsigned int GetGamesWon() const;

	void Serialize(std::string& store_string) const;
	bool Deserialize(std::string& store_string);

private:
	string name_;
	int chip_count_;
	unsigned int games_won_;

};

#endif // PLAYER_H_
