/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef GAME_GALLERY_H_
#define GAME_GALLERY_H_

#include <iostream>
#include <fstream>
#include <set>
#include "game_gallery_ui.h"
#include "player.h"
#include "lcr_player.h"
#include "lcr_game.h"
#include "serializable.h"

class GameGallery : public Serializable {
 public:
	int MainGallery();

	void Serialize(std::string& store_string) const;
	bool Deserialize(std::string& store_string);

 private:
	void ActionPlayerAdd();
	void ActionPlayerRemove();
	void ActionGameLCR();

	void SaveSession() const;
	void RestoreSession();

	std::set<Player> game_players_;
	GameGalleryUI game_gallery_ui_;
	LcrGame lcr_game_;

	static const std::string kSaveGameFilename;
};

#endif // GAME_GALLERY_H_
