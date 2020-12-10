/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <set>
#include "player.h"

class Game {
 public:
	virtual std::string GetGameTitle() = 0;
	virtual std::string GetGameRules() = 0;
	virtual Player& PlayGame(std::set<Player> &players) = 0;
};

#endif // GAME_H_
