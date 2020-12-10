/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "test_config.h"
#include "player_test.h"
#include "lcr_players_list_test.h"

class TestSuite {
 public:
	int Run();

 private:
	PlayerTest player_test_;
	LcrPlayersListTest players_list_test_;
};

#endif // TEST_SUITE_H
