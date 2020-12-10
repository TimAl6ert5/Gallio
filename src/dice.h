/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef DICE_H_
#define DICE_H_

#define NUMBER_OF_SIDES 6

#include <cstdlib>

/*
* Represents a 6 sided dice with values 1...6
*/
class Dice {
 public:
	Dice();

	unsigned int Roll();
	unsigned int GetValue() const;

 private:
	unsigned int current_roll_;

};

#endif // DICE_H_
