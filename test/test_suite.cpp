/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "test_suite.h"

int TestSuite::Run() {
	int test_result = TEST_PASS;

#ifdef RUN_PLAYER_TEST
	test_result += player_test_.Run();
#endif

#ifdef RUN_PLAYER_LIST_TEST
	test_result += players_list_test_.Run();
#endif

	return test_result;
}
