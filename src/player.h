/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

using namespace std;

class Player
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

private:
	string name;
	int chipCount;

};

#endif // _PLAYER_H
