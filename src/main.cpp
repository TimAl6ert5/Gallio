/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include <iostream>
#include "..\test\test_config.h"

#ifdef RUN_TEST_SUITE
#include "..\test\test_suite.h"
#else
#include "game_gallery.h"
#endif // RUN_TEST_SUITE

int main() {
	std::set_terminate([]() { std::cout << "Unhandled exception" << std::endl; std::abort(); });

#ifdef RUN_TEST_SUITE
	TestSuite tests;
	return tests.Run();

#else
	// Init the mighty randomizer
	srand((unsigned int)time(NULL));

	GameGallery game_gallery;
	return game_gallery.MainGallery();

#endif // RUN_TEST_SUITE
}
