/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "players_list_test.h"

int PlayersListTest::Run() {
	int test_result = 0;

	test_result += TestGetPlayerToLeft();
	test_result += TestGetPlayerToRight();
	test_result += TestCountPlayersWithChips();
	test_result += TestGetPlayerWithChips();
	test_result += TestPlayerListSerialize();
	test_result += TestPlayerListDeserialize();

	return test_result;
}

int PlayersListTest::TestGetPlayerToLeft() {
	Player p1, p2, p3, current_player, left_player;
	PlayersList player_list;

	p1.SetPlayerName("A");
	p2.SetPlayerName("B");
	p3.SetPlayerName("C");

	player_list.AddPlayer(p1);
	player_list.AddPlayer(p2);
	player_list.AddPlayer(p3);

	current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p1.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	left_player = player_list.GetPlayerToLeft();
	if (!IsEquals("TestGetPlayerToLeft >>> check player to left", p2.GetPlayerName(), left_player.GetPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToLeft >>> next player");
	player_list.NextPlayer();

	current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p2.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	left_player = player_list.GetPlayerToLeft();
	if (!IsEquals("TestGetPlayerToLeft >>> check player to left", p3.GetPlayerName(), left_player.GetPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToLeft >>> next player");
	player_list.NextPlayer();

	current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p3.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	left_player = player_list.GetPlayerToLeft();
	if (!IsEquals("TestGetPlayerToLeft >>> check player to left", p1.GetPlayerName(), left_player.GetPlayerName())) {
		return 1;
	}


	return 0;
}

int PlayersListTest::TestGetPlayerToRight() {
	Player p1, p2, p3, current_player, right_player;
	PlayersList player_list;

	p1.SetPlayerName("A");
	p2.SetPlayerName("B");
	p3.SetPlayerName("C");

	player_list.AddPlayer(p1);
	player_list.AddPlayer(p2);
	player_list.AddPlayer(p3);

	current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p1.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	right_player = player_list.GetPlayerToRight();
	if (!IsEquals("TestGetPlayerToRight >>> check player to right", p3.GetPlayerName(), right_player.GetPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToRight >>> next player");
	player_list.NextPlayer();

	current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p2.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	right_player = player_list.GetPlayerToRight();
	if (!IsEquals("TestGetPlayerToRight >>> check player to right", p1.GetPlayerName(), right_player.GetPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToRight >>> next player");
	player_list.NextPlayer();

	current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p3.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	right_player = player_list.GetPlayerToRight();
	if (!IsEquals("TestGetPlayerToRight >>> check player to right", p2.GetPlayerName(), right_player.GetPlayerName())) {
		return 1;
	}

	player_list.NextPlayer();

	return 0;
}

int PlayersListTest::TestCountPlayersWithChips() {
	Player p1, p2;
	PlayersList player_list;

	if (!IsEquals("TestCountPlayersWithChips >>> empty list", 0, player_list.CountPlayersWithChips())) {
		return 1;
	}

	p1.SetPlayerChipCount(1);
	player_list.AddPlayer(p1);
	if (!IsEquals("TestCountPlayersWithChips >>> one with", 1, player_list.CountPlayersWithChips())) {
		return 1;
	}

	p2.SetPlayerChipCount(0);
	player_list.AddPlayer(p2);
	if (!IsEquals("TestCountPlayersWithChips >>> one without", 1, player_list.CountPlayersWithChips())) {
		return 1;
	}

	return 0;
}

int PlayersListTest::TestGetPlayerWithChips() {
	Player p1, p2, p3;
	PlayersList player_list;

	p1.SetPlayerName("A");
	p1.SetPlayerChipCount(0);
	p2.SetPlayerName("B");
	p2.SetPlayerChipCount(2);
	p3.SetPlayerName("C");
	p3.SetPlayerChipCount(0);

	player_list.AddPlayer(p1);
	player_list.AddPlayer(p2);
	player_list.AddPlayer(p3);

	if (!IsEquals("", p2.GetPlayerName(), player_list.GetPlayerWithChips().GetPlayerName())) {
		return -1;
	}

	return 0;
}

int PlayersListTest::TestPlayerListSerialize() {
	PlayersList player_list;

	Player p1("John Doe");
	p1.SetGamesWon(42);
	p1.SetPlayerChipCount(13);

	Player p2("Jane Doe");
	p2.SetGamesWon(24);
	p2.SetPlayerChipCount(31);

	player_list.AddPlayer(p1);
	player_list.AddPlayer(p2);

	string expected = "John Doe\t42\t13\nJane Doe\t24\t31\n";
	string actual;
	player_list.Serialize(actual);

	if (!IsEquals("TestPlayerSerialize", expected, actual)) {
		return 1;
	}

	return 0;
}

int PlayersListTest::TestPlayerListDeserialize() {
	PlayersList player_list;

	string players_source = "John Doe\t42\t13\nJane Doe\t24\t31\n";

	player_list.Deserialize(players_source);

	if (!IsEquals("TestPlayerListDeserialize", 2, player_list.GetNumberOfPlayers())) {
		return 1;
	}

	Player p1 = player_list.GetCurrentPlayer();

	if (!IsEquals("TestPlayerListDeserialize", "John Doe", p1.GetPlayerName())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 42, p1.GetGamesWon())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 13, p1.GetPlayerChipCount())) {
		return 1;
	}

	player_list.NextPlayer();

	Player p2 = player_list.GetCurrentPlayer();

	if (!IsEquals("TestPlayerListDeserialize", "Jane Doe", p2.GetPlayerName())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 24, p2.GetGamesWon())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 31, p2.GetPlayerChipCount())) {
		return 1;
	}

	return 0;
}
