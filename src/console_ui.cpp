/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#include "console_ui.h"

void ConsoleUI::Clear() const {
	system(CLEAR);
}

void ConsoleUI::ShowMessageFragment(const std::string& msg) const {
	std::cout << msg;
}

void ConsoleUI::ShowMessageLine(const std::string& msg) const {
	std::cout << msg << std::endl;
}

/*
* Read an integer from console input and use the function to validate the
* value.
* 
* @param user_int reference location to store a valid value
* @param ValidValue function to validate the value
* @return True if the user input a valid value
*/
bool ConsoleUI::ReadUserInteger(int& user_int, bool (*ValidValue)(int)) const {
	std::string user_input;
	int in_buffer;

	std::cin >> user_input;
	
	try {
		in_buffer = stoi(user_input);
		if (ValidValue(in_buffer)) {
			user_int = in_buffer;
			return true;
		}
	} catch (...) {}
	return false;
}

/*
* Read a string from console input and use the function to validate the value.
*
* @param user_string reference location to store a valid value
* @param ValidValue function to validate the value
* @return True if the user input a valid value
*/
bool ConsoleUI::ReadUserString(std::string& user_string, bool (*ValidValue)(std::string&)) const {
	std::string user_input;

	// TODO figure out how to read a line with spaces in it
	std::cin >> user_input;

	try {
		if (ValidValue(user_input)) {
			user_string.assign(user_input);
			return true;
		}
	}
	catch (...) {}
	return false;
}

void ConsoleUI::ShowHorizontalLine() const {
	for (unsigned int i = 0; i < kConsoleWidth_; i++) {
		std::cout << kHorizontalLineChar;
	}
	std::cout << std::endl;
}
