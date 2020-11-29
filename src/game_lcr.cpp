/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#include "game_lcr.h"

GameLCR::GameLCR()
	: centerChips(0), turns(0)
{}

GameLCR::~GameLCR() {}

string GameLCR::getTitle() const {
	return title;
}

string GameLCR::getRules() {
	if (rules.size() < 1) {
		std::ifstream ifs("rules_lcr.txt");
		rules.assign((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
	}
	return rules;
}

const string GameLCR::title{ "Left-Center-Right (LCR)" };

Player& GameLCR::PlayGame(PlayersList& playersList) {
	game_ui.ShowGameStart(playersList);

	while (playersList.CountPlayersWithChips() > 1) {
		++turns;
		game_ui.ShowGameRound(turns, ((turns - 1) / playersList.getNumberOfPlayers()) + 1);

		TakeTurn(playersList);

		playersList.nextPlayer();
	}

	// Return the last player that still has chips
	return playersList.getPlayerWithChips();
}

void GameLCR::TakeTurn(PlayersList& playersList) {

	Player& currentPlayer = playersList.getCurrentPlayer();
	Player& leftPlayer = playersList.getPlayerToLeft();
	Player& rightPlayer = playersList.getPlayerToRight();
	int currentChipCount = currentPlayer.getPlayerChipCount();

	game_dice.rollDice(currentPlayer.getPlayerChipCount());
	int countL = game_dice.CountL();
	int countR = game_dice.CountR();
	int countC = game_dice.CountC();

	// Check that player can take a turn
	if (currentChipCount > 0) {
		game_ui.ShowCurrentPlayerTurn(currentPlayer, countL, countR, countC, game_dice.CountStar());

		if (countL > 0) {
			for (int i = 0; i < countL; i++) {
				currentPlayer.removeOneChip();
				leftPlayer.addOneChip();
			}
			game_ui.ShowChipPass(currentPlayer, leftPlayer, true, countL);
		}

		if (countR > 0) {
			for (int i = 0; i < countR; i++) {
				currentPlayer.removeOneChip();
				rightPlayer.addOneChip();
			}
			game_ui.ShowChipPass(currentPlayer, rightPlayer, false, countR);
		}

		if (countC > 0) {
			for (int i = 0; i < countC; i++) {
				currentPlayer.removeOneChip();
				centerChips++;
			}
			game_ui.ShowChipCenter(currentPlayer, centerChips, countC);
			// TODO show updated player chip count
		}
	}
	else {
		// Player has no chips and can't take a turn
		game_ui.ShowCurrentPlayerTurn(currentPlayer);
	}
}
