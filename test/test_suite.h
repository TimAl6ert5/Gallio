/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "player_test.h"
#include "players_list_test.h"

class TestSuite
{
public:
	int Run();

private:
	PlayerTest player_test;
	PlayersListTest players_list_test;
};

#endif // TEST_SUITE_H
