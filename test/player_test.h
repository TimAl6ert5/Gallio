/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include "base_test.h"
#include "../src/player.h"

class PlayerTest : public BaseTest
{
public:
	int Run();

private:
	int TestPlayerSerialize();
	int TestPlayerDeserialize();

};

#endif // PLAYER_TEST_H
