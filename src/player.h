/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <sstream>
#include <vector>
#include "serializable.h"

using namespace std;

class Player : public Serializable
{
public:
	Player();
	Player(string name);
	~Player();

	void setPlayerName(string name);
	string getPlayerName() const;
	void setPlayerChipCount(const int chips);
	int getPlayerChipCount() const;

	void addOneChip();
	void removeOneChip();

	void incrementGamesWon();
	void setGamesWon(const int won);
	unsigned int getGamesWon() const;

	void serialize(std::string& store_string) const;
	bool deserialize(std::string& store_string);

private:
	string name;
	int chipCount;
	unsigned int games_won;

};

#endif // _PLAYER_H
