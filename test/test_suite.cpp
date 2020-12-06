/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "test_suite.h"

int TestSuite::Run() {
	int test_result = 0;

	test_result += player_test.Run();
	test_result += players_list_test.Run();

	return test_result;
}
