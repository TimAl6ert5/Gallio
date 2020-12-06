/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef CONSOLE_UI_H_
#define CONSOLE_UI_H_

#include <iostream>
#include <string>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class ConsoleUI {
public:
	void Clear() const;
	void ShowMessageFragment(const std::string& msg) const;
	void ShowMessageLine(const std::string& msg) const;

	bool ReadUserInteger(int& user_int, bool (*ValidValue)(int)) const;

};

#endif // CONSOLE_UI_H_
