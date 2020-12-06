/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "game_lcr_ui.h"

#define dice_val(d) ( d == 1 ? 'L' : ( d == 2 ? 'R' : ( d == 3 ? 'C' : '*' ) ) ) 

#define plural_chip(c) ( c == 1 ? "chip" : "chips" )

void GameLcrUi::ShowGameStart(PlayersList& playersList) {
	int nmbrPlayers = playersList.GetNumberOfPlayers();

	cout << endl << "Starting LCR game with " << nmbrPlayers << " players." << endl;
	cout << "Each player has 3 chips.  The game is set.  Ready? Go!" << endl;
}

void GameLcrUi::ShowGameRound(int turn, int round) {
	cout << endl << "Turn " << turn << ", round " << round << ": ";
}

void GameLcrUi::ShowCurrentPlayerTurn(Player& currentPlayer, int countL, int countR, int countC, int countS) {
	int showChipCount = min(currentPlayer.GetPlayerChipCount(), 3);

	cout << "Player " << currentPlayer.GetPlayerName() << " has " << currentPlayer.GetPlayerChipCount()
		<< " " << plural_chip(currentPlayer.GetPlayerChipCount()) << "." << endl;

	cout << "Player " << currentPlayer.GetPlayerName() << " rolls ";
	
	if (countL > 0) {
		cout << countL << "L ";
	}
	if (countR > 0) {
		cout << countR << "R ";
	}
	if (countC > 0) {
		cout << countC << "C ";
	}
	if (countS > 0) {
		cout << countS << "* ";
	}
	cout << endl;
}

void GameLcrUi::ShowCurrentPlayerTurn(Player& currentPlayer) {
	cout << "Player " << currentPlayer.GetPlayerName() << " has no chips and does not get a turn this round." << endl;
}

void GameLcrUi::ShowChipPass(Player& from, Player& to, bool left, int chip_count) {
	// show action
	cout << "Player " << from.GetPlayerName() << " passes " << chip_count << " " << plural_chip(chip_count) << " "
		<< (left ? "left" : "right") << " to player " << to.GetPlayerName() << ".";
	// show result
	cout << " Player " << from.GetPlayerName() << " now has " << from.GetPlayerChipCount() << " and "
		<< "player " << to.GetPlayerName() << " now has " << to.GetPlayerChipCount() << "." << endl;
}

void GameLcrUi::ShowChipCenter(Player& currentPlayer, int center_chip_count, int chip_count) {
	cout << "Player " << currentPlayer.GetPlayerName() << " moves " << chip_count
		<< " " << plural_chip(chip_count) << " to the center. " << currentPlayer.GetPlayerName() << " now has " << currentPlayer.GetPlayerChipCount()
		<< " " << plural_chip(currentPlayer.GetPlayerChipCount()) << " and there " << (center_chip_count > 1 ? "are" : "is") << " "
		<< center_chip_count << " " << plural_chip(center_chip_count) << " out of play." << endl;
}
