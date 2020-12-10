/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "player_test.h"

int PlayerTest::Run() {
	int test_result = TEST_PASS;

	test_result += TestPlayerSerialize();
	test_result += TestPlayerDeserialize();

	return test_result;
}

int PlayerTest::TestPlayerSerialize() {
	int test_result = TEST_PASS;

	Player p1("John Doe");
	p1.SetGamesWon(42);

	std::string expected = "John Doe\t42";
	std::string actual;
	p1.Serialize(actual);

	if (!IsEquals("TestPlayerSerialize", expected, actual)) {
		test_result = TEST_FAIL;
	}
	
	return test_result;
}

int PlayerTest::TestPlayerDeserialize() {
	int test_result = TEST_PASS;

	std::string serialized_player = "John Doe\t42";
	Player p1("");

	p1.Deserialize(serialized_player);

	if (!IsEquals("TestPlayerDeserialize", "John Doe", p1.GetPlayerName())) {
		test_result = TEST_FAIL;
	}

	if (!IsEquals("TestPlayerDeserialize", 42, p1.GetGamesWon())) {
		test_result = TEST_FAIL;
	}

	return test_result;
}
