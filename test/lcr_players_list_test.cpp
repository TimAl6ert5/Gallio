/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "lcr_players_list_test.h"

int LcrPlayersListTest::Run() {
	int test_result = 0;

	test_result += TestGetPlayerToLeft();
	test_result += TestGetPlayerToRight();
	test_result += TestCountPlayersWithChips();
	test_result += TestGetPlayerWithChips();

	return test_result;
}

int LcrPlayersListTest::TestGetPlayerToLeft() {
	Player p1("A"), p2("B"), p3("C");
	LcrPlayersList player_list;

	player_list.AddPlayer(LcrPlayer(p1));
	player_list.AddPlayer(LcrPlayer(p2));
	player_list.AddPlayer(LcrPlayer(p3));

	LcrPlayer current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p1.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	LcrPlayer left_player = player_list.GetPlayerToLeft();
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

int LcrPlayersListTest::TestGetPlayerToRight() {
	Player p1("A"), p2("B"), p3("C");
	LcrPlayersList player_list;

	player_list.AddPlayer(p1);
	player_list.AddPlayer(p2);
	player_list.AddPlayer(p3);

	LcrPlayer current_player = player_list.GetCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p1.GetPlayerName(), current_player.GetPlayerName())) {
		return 1;
	}

	LcrPlayer right_player = player_list.GetPlayerToRight();
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

int LcrPlayersListTest::TestCountPlayersWithChips() {
	Player a = Player("A");
	Player b = Player("B");
	LcrPlayer p1 = LcrPlayer(a), p2 = LcrPlayer(b);
	LcrPlayersList player_list;

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

	p2.SetPlayerChipCount(3);
	player_list.AddPlayer(p2);
	if (!IsEquals("TestCountPlayersWithChips >>> two with", 2, player_list.CountPlayersWithChips())) {
		return 1;
	}

	return 0;
}

int LcrPlayersListTest::TestGetPlayerWithChips() {
	Player a = Player("A");
	Player b = Player("B");
	Player c = Player("C");
	LcrPlayer p1 = LcrPlayer(a), p2 = LcrPlayer(b), p3 = LcrPlayer(c);
	LcrPlayersList player_list;

	p1.SetPlayerChipCount(0);
	p2.SetPlayerChipCount(2);
	p3.SetPlayerChipCount(0);

	player_list.AddPlayer(p1);
	player_list.AddPlayer(p2);
	player_list.AddPlayer(p3);

	if (!IsEquals("TestGetPlayerWithChips", p2.GetPlayerName(), player_list.GetPlayerWithChips().GetPlayerName())) {
		return -1;
	}

	return 0;
}
