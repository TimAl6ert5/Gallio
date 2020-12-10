/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef GAME_GALLERY_H_
#define GAME_GALLERY_H_

#include <set>
#include "game_gallery_ui.h"
#include "player.h"
#include "lcr_player.h"
#include "lcr_game.h"

class GameGallery {
 public:
	int MainGallery();

 private:
	void ActionPlayerAdd();
	void ActionPlayerRemove();
	void ActionGameLCR();

	std::set<Player> game_players_;
	GameGalleryUI game_gallery_ui_;
	LcrGame lcr_game_;

};

#endif // GAME_GALLERY_H_
