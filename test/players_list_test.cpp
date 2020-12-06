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

	p1.setPlayerName("A");
	p2.setPlayerName("B");
	p3.setPlayerName("C");

	player_list.addPlayer(p1);
	player_list.addPlayer(p2);
	player_list.addPlayer(p3);

	current_player = player_list.getCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p1.getPlayerName(), current_player.getPlayerName())) {
		return 1;
	}

	left_player = player_list.getPlayerToLeft();
	if (!IsEquals("TestGetPlayerToLeft >>> check player to left", p2.getPlayerName(), left_player.getPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToLeft >>> next player");
	player_list.nextPlayer();

	current_player = player_list.getCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p2.getPlayerName(), current_player.getPlayerName())) {
		return 1;
	}

	left_player = player_list.getPlayerToLeft();
	if (!IsEquals("TestGetPlayerToLeft >>> check player to left", p3.getPlayerName(), left_player.getPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToLeft >>> next player");
	player_list.nextPlayer();

	current_player = player_list.getCurrentPlayer();
	if (!IsEquals("TestGetPlayerToLeft >>> check default current player", p3.getPlayerName(), current_player.getPlayerName())) {
		return 1;
	}

	left_player = player_list.getPlayerToLeft();
	if (!IsEquals("TestGetPlayerToLeft >>> check player to left", p1.getPlayerName(), left_player.getPlayerName())) {
		return 1;
	}


	return 0;
}

int PlayersListTest::TestGetPlayerToRight() {
	Player p1, p2, p3, current_player, right_player;
	PlayersList player_list;

	p1.setPlayerName("A");
	p2.setPlayerName("B");
	p3.setPlayerName("C");

	player_list.addPlayer(p1);
	player_list.addPlayer(p2);
	player_list.addPlayer(p3);

	current_player = player_list.getCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p1.getPlayerName(), current_player.getPlayerName())) {
		return 1;
	}

	right_player = player_list.getPlayerToRight();
	if (!IsEquals("TestGetPlayerToRight >>> check player to right", p3.getPlayerName(), right_player.getPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToRight >>> next player");
	player_list.nextPlayer();

	current_player = player_list.getCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p2.getPlayerName(), current_player.getPlayerName())) {
		return 1;
	}

	right_player = player_list.getPlayerToRight();
	if (!IsEquals("TestGetPlayerToRight >>> check player to right", p1.getPlayerName(), right_player.getPlayerName())) {
		return 1;
	}

	LogInfo("TestGetPlayerToRight >>> next player");
	player_list.nextPlayer();

	current_player = player_list.getCurrentPlayer();
	if (!IsEquals("TestGetPlayerToRight >>> check default current player", p3.getPlayerName(), current_player.getPlayerName())) {
		return 1;
	}

	right_player = player_list.getPlayerToRight();
	if (!IsEquals("TestGetPlayerToRight >>> check player to right", p2.getPlayerName(), right_player.getPlayerName())) {
		return 1;
	}

	player_list.nextPlayer();

	return 0;
}

int PlayersListTest::TestCountPlayersWithChips() {
	Player p1, p2;
	PlayersList player_list;

	if (!IsEquals("TestCountPlayersWithChips >>> empty list", 0, player_list.CountPlayersWithChips())) {
		return 1;
	}

	p1.setPlayerChipCount(1);
	player_list.addPlayer(p1);
	if (!IsEquals("TestCountPlayersWithChips >>> one with", 1, player_list.CountPlayersWithChips())) {
		return 1;
	}

	p2.setPlayerChipCount(0);
	player_list.addPlayer(p2);
	if (!IsEquals("TestCountPlayersWithChips >>> one without", 1, player_list.CountPlayersWithChips())) {
		return 1;
	}

	return 0;
}

int PlayersListTest::TestGetPlayerWithChips() {
	Player p1, p2, p3;
	PlayersList player_list;

	p1.setPlayerName("A");
	p1.setPlayerChipCount(0);
	p2.setPlayerName("B");
	p2.setPlayerChipCount(2);
	p3.setPlayerName("C");
	p3.setPlayerChipCount(0);

	player_list.addPlayer(p1);
	player_list.addPlayer(p2);
	player_list.addPlayer(p3);

	if (!IsEquals("", p2.getPlayerName(), player_list.getPlayerWithChips().getPlayerName())) {
		return -1;
	}

	return 0;
}

int PlayersListTest::TestPlayerListSerialize() {
	PlayersList player_list;

	Player p1("John Doe");
	p1.setGamesWon(42);
	p1.setPlayerChipCount(13);

	Player p2("Jane Doe");
	p2.setGamesWon(24);
	p2.setPlayerChipCount(31);

	player_list.addPlayer(p1);
	player_list.addPlayer(p2);

	string expected = "John Doe\t42\t13\nJane Doe\t24\t31\n";
	string actual;
	player_list.serialize(actual);

	if (!IsEquals("TestPlayerSerialize", expected, actual)) {
		return 1;
	}

	return 0;
}

int PlayersListTest::TestPlayerListDeserialize() {
	PlayersList player_list;

	string players_source = "John Doe\t42\t13\nJane Doe\t24\t31\n";

	player_list.deserialize(players_source);

	if (!IsEquals("TestPlayerListDeserialize", 2, player_list.getNumberOfPlayers())) {
		return 1;
	}

	Player p1 = player_list.getCurrentPlayer();

	if (!IsEquals("TestPlayerListDeserialize", "John Doe", p1.getPlayerName())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 42, p1.getGamesWon())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 13, p1.getPlayerChipCount())) {
		return 1;
	}

	player_list.nextPlayer();

	Player p2 = player_list.getCurrentPlayer();

	if (!IsEquals("TestPlayerListDeserialize", "Jane Doe", p2.getPlayerName())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 24, p2.getGamesWon())) {
		return 1;
	}
	if (!IsEquals("TestPlayerListDeserialize", 31, p2.getPlayerChipCount())) {
		return 1;
	}

	return 0;
}
