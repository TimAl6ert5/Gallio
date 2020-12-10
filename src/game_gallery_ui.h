/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef GAME_GALLERY_UI_H_
#define GAME_GALLERY_UI_H_

#include <iostream>
#include <set>
#include "console_ui.h"
#include "player.h"

class GameGalleryUI : public ConsoleUI {
 public:
	int PromptMain() const;
	void ShowPlayers(std::set<Player> &game_players) const;
	std::string PromptPlayerName() const;
	void LeaveGallery() const;
	void ShowGameRules(const std::string& rules_text) const;
	void ShowMinPlayers(const std::string& game_name, unsigned int min_players) const;

};

#endif // GAME_GALLERY_UI_H_
