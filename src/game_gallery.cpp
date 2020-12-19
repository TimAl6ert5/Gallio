/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "game_gallery.h"

const std::string GameGallery::kSaveGameFilename = "save_game.txt";

int GameGallery::MainGallery() {
	RestoreSession();
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

	SaveSession();

	return 0;
}

void GameGallery::Serialize(std::string& store_string) const {
	std::string s_buffer;
	for (Player p : game_players_) {
		p.Serialize(s_buffer);
		s_buffer += "\n";
		store_string += s_buffer;
		s_buffer.clear();
	}
}

bool GameGallery::Deserialize(std::string& store_string) {
	return false;
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

	const Player* winner_ptr = lcr_game_.PlayGame(game_players_);
	Player winner = *winner_ptr;
	std::set<Player>::iterator winner_it = game_players_.find(winner);
	if (winner_it != game_players_.end()) {
		game_players_.erase(winner_it);
		winner.IncrementGamesWon();
		game_players_.emplace(winner);
	}
}

void GameGallery::SaveSession() const {
	std::string save_buffer;

	std::ofstream save_file(kSaveGameFilename, std::ios::out | std::ios::trunc);
	if (!save_file) {
		std::cerr << "[ERROR] Save game failed." << std::endl;
		return; // TODO ensure file is closed
	}

	Serialize(save_buffer);
	save_file << save_buffer;

	save_file.close();
}

void GameGallery::RestoreSession() {
	std::ifstream save_file{ kSaveGameFilename };
	if (save_file.is_open()) {

		std::string read_buf;
		while (std::getline(save_file, read_buf)) {
			Player p;
			p.Deserialize(read_buf);
			game_players_.emplace(p);
		}

		save_file.close();
	}
}
