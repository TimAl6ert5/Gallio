/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#include "player.h"


Player::Player()
	: name("No Name"), chipCount(3)
{}

Player::Player(string name)
	: name(name), chipCount(3)
{}

Player::~Player() {}

void Player::setPlayerName(string new_name) {
	name.assign(new_name);
}

string Player::getPlayerName() const {
	return name;
}

void Player::setPlayerChipCount(const int chips) {
	chipCount = chips;
}

int Player::getPlayerChipCount() const {
	return chipCount;
}

void Player::addOneChip() {
	chipCount++;
}

void Player::removeOneChip() {
	if (chipCount > 0) {
		chipCount--;
	}
}
