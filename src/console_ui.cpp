/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

#include "console_ui.h"

ConsoleUI::ConsoleUI() {}
ConsoleUI::~ConsoleUI() {}

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
