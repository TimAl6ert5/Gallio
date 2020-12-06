/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef PLAYERS_LIST_TEST_H
#define PLAYERS_LIST_TEST_H

#include "base_test.h"
#include "..\src\players_list.h"
#include "..\src\player.h"

class PlayersListTest : public BaseTest
{
public:
	int Run();

	int TestGetPlayerToLeft();
	int TestGetPlayerToRight();
	int TestCountPlayersWithChips();
	int TestGetPlayerWithChips();
	int TestPlayerListSerialize();
	int TestPlayerListDeserialize();

};

#endif // PLAYERS_LIST_TEST_H
