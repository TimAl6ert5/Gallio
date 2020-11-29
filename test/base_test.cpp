/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#include "base_test.h"

void BaseTest::LogInfo(std::string message) {
	std::cout << "[INFO] " << message << std::endl;
}

void BaseTest::LogError(std::string message) {
	std::cout << "[ERROR] " << message << std::endl;
}

bool BaseTest::IsEquals(std::string note, std::string expected, std::string actual) {
	std::stringstream ss;
	ss << "Test " << note << "\n\tExpected: " << expected << "\n\tActual: " << actual;

	if (expected == actual) {
		LogInfo(ss.str());
		return true;
	}
	else {
		LogError(ss.str());
		return false;
	}
}

bool BaseTest::IsEquals(std::string note, int expected, int actual) {
	std::stringstream ss;
	ss << "Test " << note << "\n\tExpected: (" << expected << ")\n\tActual: (" << actual << ").";

	if (expected == actual) {
		LogInfo(ss.str());
		return true;
	}
	else {
		LogError(ss.str());
		return false;
	}
}
