/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "game_gallery.h"

int GameGallery::MainGallery() {
	bool exit = false;

	while (!exit) {
		int main_choice = game_gallery_ui_.PromptMain();

		switch (main_choice) {
		case 1:
			game_gallery_ui_.ShowPlayers(game_players_);
			break;
		case 2:
			ActionPlayerAdd();
			break;
		case 3:
			ActionPlayerRemove();
			break;
		case 4:
			ActionGameLCR();
			break;
		case 5:
			game_gallery_ui_.ShowGameRules(lcr_game_.GetGameRules());
			break;
		default:
			game_gallery_ui_.LeaveGallery();
			exit = true;
			break;
		}
	}

	return 0;
}

void GameGallery::ActionPlayerAdd() {
	std::string player_name = game_gallery_ui_.PromptPlayerName();

	Player p = Player(player_name);

	game_players_.emplace(p);
}

void GameGallery::ActionPlayerRemove() {
	std::string player_name = game_gallery_ui_.PromptPlayerName();

	Player p = Player(player_name);

	std::set<Player>::iterator iter;

	iter = game_players_.find(p);

	if (iter != game_players_.end()) {
		game_players_.erase(iter);
	}
}

void GameGallery::ActionGameLCR() {
	if (game_players_.size() < LcrGame::kMinPlayers) {
		game_gallery_ui_.ShowMinPlayers(lcr_game_.GetGameTitle(), lcr_game_.kMinPlayers);
		return;
	}

	Player& winner = lcr_game_.PlayGame(game_players_);
	winner.IncrementGamesWon();
}
