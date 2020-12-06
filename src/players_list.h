/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef PLAYER_LIST_H_
#define PLAYER_LIST_H_

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
class PlayersList : public Serializable {
public:
	PlayersList();

	void AddPlayer(Player player);
	Player& GetCurrentPlayer();

	void NextPlayer();
	unsigned int GetNumberOfPlayers() const;

	Player& GetPlayerToLeft();
	Player& GetPlayerToRight();

	unsigned int CountPlayersWithChips() const;
	Player& GetPlayerWithChips();

	void Serialize(std::string& store_string) const;
	bool Deserialize(std::string& store_string);

private:
	PlayersVector players_;
	unsigned int current_player_index_ = 0;

};

#endif // PLAYER_LIST_H_
