/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#include "application.h"

Application::Application() {}
Application::~Application() {}

int Application::run() {
	stringstream ss;

	// Init the mighty randomizer
	srand( (unsigned int) time(NULL));

	showWelcome();
	showRules();

	while (getPlayerFromUser()) {}

	// TODO make sure there's enough players

	Player winner = gameLCR.PlayGame(playersList);

	showResults(winner);

	return 0;
}

void Application::showWelcome() {
	stringstream ss;

	ss << "Hello! Welcome to " << gameLCR.getTitle() << "\n";
	console_ui.ShowMessageLine(ss.str());
}

void Application::showRules() {
	stringstream ss;

	ss << "\n\nGame Rules:\n" << gameLCR.getRules() << "\n";
	console_ui.ShowMessageLine(ss.str());
}

bool Application::getPlayerFromUser() {

	string inputName;

	cout << "Enter players name (enter * for no more players): ";
	cin >> inputName;

	if (inputName == "*") {
		return false;
	}
	else {
		Player newPlayer(inputName);
		playersList.addPlayer(newPlayer);
		return true;
	}
}

void Application::showResults(const Player winner) {
	stringstream ss;

	ss << "The Winner is: " << winner.getPlayerName()
		<< "\nCongratulations!";
	console_ui.ShowMessageLine(ss.str());
}
