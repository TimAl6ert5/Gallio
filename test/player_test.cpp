/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "player_test.h"

int PlayerTest::Run() {
	int result = 0;

	result += TestPlayerSerialize();
	result += TestPlayerDeserialize();

	return result;
}

int PlayerTest::TestPlayerSerialize() {
	Player p1("John Doe");
	p1.SetGamesWon(42);
	p1.SetPlayerChipCount(5);

	string expected = "John Doe\t42\t5";
	string actual;
	p1.Serialize(actual);

	if (!IsEquals("TestPlayerSerialize", expected, actual)) {
		return 1;
	}
	return 0;
}

int PlayerTest::TestPlayerDeserialize() {
	string serialized_player = "John Doe\t42\t5";
	Player p1("");

	p1.Deserialize(serialized_player);

	if (!IsEquals("TestPlayerDeserialize", "John Doe", p1.GetPlayerName())) {
		return 1;
	}

	if (!IsEquals("TestPlayerDeserialize", 42, p1.GetGamesWon())) {
		return 1;
	}

	if (!IsEquals("TestPlayerDeserialize", 5, p1.GetPlayerChipCount())) {
		return 1;
	}

	return 0;
}
