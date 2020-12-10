/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "lcr_game_ui.h"

#define dice_val(d) ( d == 1 ? 'L' : ( d == 2 ? 'R' : ( d == 3 ? 'C' : '*' ) ) ) 

#define plural_chip(c) ( c == 1 ? "chip" : "chips" )

void LcrGameUi::ShowGameStart(LcrPlayersList& playersList) {
	int nmbrPlayers = playersList.GetNumberOfPlayers();

	std::cout << std::endl << "Starting LCR game with " << nmbrPlayers << " players." << std::endl;
	std::cout << "Each player has 3 chips.  The game is set.  Ready? Go!" << std::endl;
}

void LcrGameUi::ShowGameRound(int turn, int round) {
	std::cout << std::endl << "Turn " << turn << ", round " << round << ": ";
}

void LcrGameUi::ShowCurrentPlayerTurn(LcrPlayer& currentPlayer, int countL, int countR, int countC, int countS) {
	int showChipCount = std::min(currentPlayer.GetPlayerChipCount(), 3);

	std::cout << "Player " << currentPlayer.GetPlayerName() << " has " << currentPlayer.GetPlayerChipCount()
		<< " " << plural_chip(currentPlayer.GetPlayerChipCount()) << "." << std::endl;

	std::cout << "Player " << currentPlayer.GetPlayerName() << " rolls ";
	
	if (countL > 0) {
		std::cout << countL << "L ";
	}
	if (countR > 0) {
		std::cout << countR << "R ";
	}
	if (countC > 0) {
		std::cout << countC << "C ";
	}
	if (countS > 0) {
		std::cout << countS << "* ";
	}
	std::cout << std::endl;
}

void LcrGameUi::ShowCurrentPlayerTurn(LcrPlayer& currentPlayer) {
	std::cout << "Player " << currentPlayer.GetPlayerName() 
		<< " has no chips and does not get a turn this round." << std::endl;
}

void LcrGameUi::ShowChipPass(LcrPlayer& from, LcrPlayer& to, bool left, int chip_count) {
	// show action
	std::cout << "Player " << from.GetPlayerName() << " passes " << chip_count << " " << plural_chip(chip_count) << " "
		<< (left ? "left" : "right") << " to player " << to.GetPlayerName() << ".";
	// show result
	std::cout << " Player " << from.GetPlayerName() << " now has " << from.GetPlayerChipCount() << " and "
		<< "player " << to.GetPlayerName() << " now has " << to.GetPlayerChipCount() << "." << std::endl;
}

void LcrGameUi::ShowChipCenter(LcrPlayer& currentPlayer, int center_chip_count, int chip_count) {
	std::cout << "Player " << currentPlayer.GetPlayerName() << " moves " << chip_count
		<< " " << plural_chip(chip_count) << " to the center. " << currentPlayer.GetPlayerName() 
		<< " now has " << currentPlayer.GetPlayerChipCount()
		<< " " << plural_chip(currentPlayer.GetPlayerChipCount()) << " and there " 
		<< (center_chip_count > 1 ? "are" : "is") << " "
		<< center_chip_count << " " << plural_chip(center_chip_count) << " out of play." << std::endl;
}

void LcrGameUi::ShowWinner(LcrPlayer& winningPlayer, int turns) {
	std::cout << "Player " << winningPlayer.GetPlayerName() << " win the game in "
		<< turns << " rounds with " << winningPlayer.GetPlayerChipCount() 
		<< " chips left.\nCongratulations!" << std::endl;
}
