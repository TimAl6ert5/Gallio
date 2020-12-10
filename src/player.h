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

class Player : public Serializable {
public:
	Player();
	Player(std::string name);

	void SetPlayerName(std::string name);
	std::string GetPlayerName() const;

	void IncrementGamesWon();
	void SetGamesWon(const unsigned int won);
	unsigned int GetGamesWon() const;

	void Serialize(std::string& store_string) const;
	bool Deserialize(std::string& store_string);

	bool operator <(const Player& other) const;
	bool operator ==(const Player& other) const;

private:
	std::string name_;
	unsigned int games_won_;

};

#endif // PLAYER_H_
