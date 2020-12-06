/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "game_lcr.h"

GameLCR::GameLCR()
	: center_chips_(0), turns_(0)
{}

string GameLCR::GetTitle() const {
	return title_;
}

string GameLCR::GetRules() {
	if (rules_.size() < 1) {
		std::ifstream ifs("rules_lcr.txt");
		rules_.assign((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
	}
	return rules_;
}

const string GameLCR::title_{ "Left-Center-Right (LCR)" };

Player& GameLCR::PlayGame(PlayersList& playersList) {
	game_ui_.ShowGameStart(playersList);

	while (playersList.CountPlayersWithChips() > 1) {
		++turns_;
		game_ui_.ShowGameRound(turns_, ((turns_ - 1) / playersList.GetNumberOfPlayers()) + 1);

		TakeTurn(playersList);

		playersList.NextPlayer();
	}

	// Return the last player that still has chips
	return playersList.GetPlayerWithChips();
}

void GameLCR::TakeTurn(PlayersList& playersList) {

	Player& currentPlayer = playersList.GetCurrentPlayer();
	Player& leftPlayer = playersList.GetPlayerToLeft();
	Player& rightPlayer = playersList.GetPlayerToRight();
	int currentChipCount = currentPlayer.GetPlayerChipCount();

	game_dice_.RollDice(currentPlayer.GetPlayerChipCount());
	int countL = game_dice_.CountL();
	int countR = game_dice_.CountR();
	int countC = game_dice_.CountC();

	// Check that player can take a turn
	if (currentChipCount > 0) {
		game_ui_.ShowCurrentPlayerTurn(currentPlayer, countL, countR, countC, game_dice_.CountStar());

		if (countL > 0) {
			for (int i = 0; i < countL; i++) {
				currentPlayer.RemoveOneChip();
				leftPlayer.AddOneChip();
			}
			game_ui_.ShowChipPass(currentPlayer, leftPlayer, true, countL);
		}

		if (countR > 0) {
			for (int i = 0; i < countR; i++) {
				currentPlayer.RemoveOneChip();
				rightPlayer.AddOneChip();
			}
			game_ui_.ShowChipPass(currentPlayer, rightPlayer, false, countR);
		}

		if (countC > 0) {
			for (int i = 0; i < countC; i++) {
				currentPlayer.RemoveOneChip();
				center_chips_++;
			}
			game_ui_.ShowChipCenter(currentPlayer, center_chips_, countC);
			// TODO show updated player chip count
		}
	}
	else {
		// Player has no chips and can't take a turn
		game_ui_.ShowCurrentPlayerTurn(currentPlayer);
	}
}
