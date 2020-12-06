/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "dice.h"

Dice::Dice() {
	this->roll();
}

Dice::~Dice() {}

unsigned int Dice::roll() {
	currentRoll = (rand() % NUMBER_OF_SIDES) + 1;
	return currentRoll;
}

unsigned int Dice::getValue() const {
	return currentRoll;
}
