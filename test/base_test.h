/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef BASE_TEST_H_
#define BASE_TEST_H_

#include <iostream>
#include <string>
#include <sstream>
#include "test_config.h"

/*
* A naive implementation of a simple testing framework to standardize test
* output and provide resusable comparison test functions.
*/
class BaseTest {
 protected:
	void LogInfo(std::string message);
	void LogError(std::string message);

	bool IsEquals(std::string note, std::string expected, std::string actual);
	bool IsEquals(std::string note, int expected, int actual);

};

#endif // BASE_TEST_H_
