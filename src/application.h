/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "game_lcr.h"
#include "players_list.h"
#include "console_ui.h"

using namespace std;


class Application
{
public:
	Application();
	~Application();

	int run();

private:
	ConsoleUI console_ui;
	GameLCR gameLCR;
	PlayersList playersList;

	void showWelcome();
	void showRules();
	bool getPlayerFromUser();
	void showResults(const Player winner);
	void savePlayersList() const;

	static const string kSavePlayersFilename;
};

#endif // _APPLICATION_H
