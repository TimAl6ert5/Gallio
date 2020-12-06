/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef _DICE_H
#define _DICE_H

#define NUMBER_OF_SIDES 6

#include <cstdlib>

using namespace std;

/*
* Represents a 6 sided dice with values 1...6
*/
class Dice
{
public:
	Dice();
	~Dice();

	unsigned int roll();
	unsigned int getValue() const;

private:
	unsigned int currentRoll;

};

#endif // _DICE_H
