/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "game_gallery_ui.h"

bool ValidMainMenu(int choice) {
	return choice >= 1 && choice <= 6;
}

bool ValidPlayerName(std::string& player_name) {
	return player_name.length() >= 1;
}

int GameGalleryUI::PromptMain() const {
	ShowHorizontalLine();
	ShowMessageLine("Games Gallery - Main Menu\n");
	ShowMessageLine("1.\tShow All Players");
	ShowMessageLine("2.\tAdd Player");
	ShowMessageLine("3.\tRemove Player");
	ShowMessageLine("4.\tPlay Game - LCR");
	ShowMessageLine("5.\tShow Rules - LCR");
	ShowMessageLine("6.\tQuit\n");

	bool valid_input = false;
	int choice;

	do {
		valid_input = ReadUserInteger(choice, ValidMainMenu);
		if (!valid_input) {
			ShowMessageLine("Sorry, that is not a valid choice.");
		}
	} while (!valid_input);
	return choice;
}

void GameGalleryUI::ShowPlayers(std::set<Player>& game_players) const {
	ShowHorizontalLine();
	if (game_players.empty()) {
		ShowMessageLine("There are no players currently.");
	} else {
		ShowMessageLine("\tPlayer\t\tWins");
		for (std::set<Player>::iterator iter = game_players.begin(); iter != game_players.end(); ++iter) {
			std::cout << "\t- " << iter->GetPlayerName() << "\t\t" << iter->GetGamesWon() << std::endl;
		}
	}
}

std::string GameGalleryUI::PromptPlayerName() const {
	ShowHorizontalLine();
	ShowMessageFragment("Please enter the player name: ");

	bool valid_input = false;
	std::string player_name;
	do {
		valid_input = ReadUserString(player_name, ValidPlayerName);
		if (!valid_input) {
			ShowMessageLine("Sorry, that is not a valid name.");
		}
	} while (!valid_input);
	return player_name;
}

void GameGalleryUI::LeaveGallery() const {
	ShowHorizontalLine();
	ShowMessageLine("Thank you for playing.");
}

void GameGalleryUI::ShowGameRules(const std::string& rules_text) const {
	ShowHorizontalLine();
	ShowMessageLine(rules_text);
}

void GameGalleryUI::ShowMinPlayers(const std::string& game_name, unsigned int min_players) const {
	std::stringstream ss;
	ss << "The game " << game_name << " requires a minimum of "
		<< min_players << " players.";
	ShowMessageLine(ss.str());
}
