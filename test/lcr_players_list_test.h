/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef LCR_PLAYERS_LIST_TEST_H_
#define LCR_PLAYERS_LIST_TEST_H_

#include "base_test.h"
#include "..\src\lcr_players_list.h"
#include "..\src\player.h"

class LcrPlayersListTest : public BaseTest {
public:
	int Run();

private:
	int TestGetPlayerToLeft();
	int TestGetPlayerToRight();
	int TestCountPlayersWithChips();
	int TestGetPlayerWithChips();

};

#endif // LCR_PLAYERS_LIST_TEST_H_
