/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "players_list_test.h"

class TestSuite
{
public:
	int Run();

private:
	PlayersListTest players_list_test;
};

#endif // TEST_SUITE_H
