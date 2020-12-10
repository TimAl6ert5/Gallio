/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "lcr_game.h"

LcrGame::LcrGame()
	: center_chips_(0), turns_(0)
{}

std::string LcrGame::GetGameTitle() {
	return title_;
}

std::string LcrGame::GetGameRules() {
	if (rules_.size() < 1) {
		std::ifstream ifs("rules_lcr.txt");
		rules_.assign((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
	}
	return rules_;
}

const std::string LcrGame::title_{ "Left-Center-Right (LCR)" };

Player& LcrGame::PlayGame(std::set<Player>& players) {

	// Setup a new game
	LcrPlayersList lcr_players;
	for (std::set<Player>::iterator iter = players.begin(); iter != players.end(); ++iter) {
		Player p = *iter;
		LcrPlayer lcr_player(p);
		lcr_player.SetPlayerChipCount(3);
		lcr_players.AddPlayer(lcr_player);
	}
	center_chips_ = 0;
	turns_ = 0;

	// Show ready state
	game_ui_.ShowGameStart(lcr_players);

	// Play game rounds
	while (lcr_players.CountPlayersWithChips() > 1) {
		++turns_;
		game_ui_.ShowGameRound(turns_, ((turns_ - 1) / lcr_players.GetNumberOfPlayers()) + 1);

		TakeTurn(lcr_players);

		lcr_players.NextPlayer();
	}

	// Return the last player that still has chips
	LcrPlayer winner = lcr_players.GetPlayerWithChips();
	game_ui_.ShowWinner(winner, turns_);
	return winner.GetPlayer();
}

void LcrGame::TakeTurn(LcrPlayersList& playersList) {

	LcrPlayer& currentPlayer = playersList.GetCurrentPlayer();
	LcrPlayer& leftPlayer = playersList.GetPlayerToLeft();
	LcrPlayer& rightPlayer = playersList.GetPlayerToRight();
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
