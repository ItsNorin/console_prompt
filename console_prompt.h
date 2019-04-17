#pragma once

// written by ItsNorin
// https://github.com/ItsNorin

#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>

// displays msg, gets user's input, returns entire line as string
std::string prompt(const char *msg);


// displays msg, gets user's input and streams it into to given type
// >> operator must be defined for given type
template<typename T> 
T prompt(const char *msg) {
	T response;
	std::stringstream(prompt(msg)) >> response;
	return response;
}



// gets a single keypress from user
// does not require enter key to be pressed
char promptChar_noEnter(const char *msg);


// gets a value from user, must be given range
// will display failMessage after each failed attempt
// >>, < and > operators must be defined for given type
template<typename T>
T promptRestricted(const char *msg, const T min, const T max, std::string failMessage = "Enter a number within range\n") {
	T response;
	while (true) {
		response = prompt<T>(msg);
		if (response < min || response > max)
			std::cout << failMessage;
		else
			return response;
	}
	return response;
}


// gets a character from user, must be within the given valid list
// will keep asking until user enters a valid character
// will display failMessage after each failed attempt
char promptCharRestricted(const char *msg, std::string valid, std::string failMessage = "Enter a valid character\n");


// forces user to respond either yes (y) or no (n) to asked message msg
// true if user enters a y or Y
// msg should inform user that they can only enter one of these characters: "yYnN"
bool promptYesNo(const char *msg);

