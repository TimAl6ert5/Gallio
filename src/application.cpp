/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "application.h"

int Application::Run() {
	stringstream ss;

	// Init the mighty randomizer
	srand( (unsigned int) time(NULL));

	showWelcome();
	showRules();

	while (getPlayerFromUser()) {}

	Player& winner = game_lcr_.PlayGame(players_list_);
	winner.IncrementGamesWon();

	showResults(winner);
	savePlayersList();

	return 0;
}

void Application::showWelcome() {
	stringstream ss;

	ss << "Hello! Welcome to " << game_lcr_.GetTitle() << "\n";
	console_ui_.ShowMessageLine(ss.str());
}

void Application::showRules() {
	stringstream ss;

	ss << "\n\nGame Rules:\n" << game_lcr_.GetRules() << "\n";
	console_ui_.ShowMessageLine(ss.str());
}

bool Application::getPlayerFromUser() {

	string inputName;

	cout << "Enter players name (enter * for no more players): ";
	// TODO handle names with spaces (i.e. first last).
	cin >> inputName;

	if (inputName == "*") {
		if (players_list_.GetNumberOfPlayers() >= 3) {
			return false;
		}
		else {
			cout << "The game requires at least 3 players." << endl;
			return true;
		}
	}
	else {
		Player newPlayer(inputName);
		players_list_.AddPlayer(newPlayer);
		return true;
	}
}

void Application::showResults(const Player winner) {
	stringstream ss;

	ss << "The Winner is: " << winner.GetPlayerName()
		<< "\nCongratulations!";
	console_ui_.ShowMessageLine(ss.str());
}

void Application::savePlayersList() const {
	string save_buffer;

	ofstream save_file(kSavePlayersFilename, ios::out | ios::trunc);
	if (!save_file) {
		// create the file
		cout << "[ERROR] File write failed." << endl;
	}

	// Write the file
	players_list_.Serialize(save_buffer);
	save_file << save_buffer;

	// Close the file
	save_file.close();
}

const string Application::kSavePlayersFilename = "save_players.txt";
