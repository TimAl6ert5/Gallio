/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef _PLAYER_LIST_H
#define _PLAYER_LIST_H

#include <vector>
#include <string>
#include "player.h"
#include "serializable.h"

using namespace std;

using PlayersVector = vector<Player>;

/*
* A list of players in a game.
* 
* Assumes players are in a circle taking one turn at a time in sequence.
*/
class PlayersList : public Serializable
{
public:
	PlayersList();
	~PlayersList();

	void addPlayer(Player player);
	Player& getCurrentPlayer();

	void nextPlayer();
	unsigned int getNumberOfPlayers() const;

	Player& getPlayerToLeft();
	Player& getPlayerToRight();

	unsigned int CountPlayersWithChips() const;
	Player& getPlayerWithChips();

	void serialize(std::string& store_string) const;
	bool deserialize(std::string& store_string);

private:

	PlayersVector players;
	unsigned int currentPlayerIndex = 0;

};

#endif // _PLAYER_LIST_H
