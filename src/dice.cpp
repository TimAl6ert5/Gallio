/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "dice.h"

Dice::Dice() {
	this->Roll();
}

unsigned int Dice::Roll() {
	current_roll_ = (rand() % NUMBER_OF_SIDES) + 1;
	return current_roll_;
}

unsigned int Dice::GetValue() const {
	return current_roll_;
}
