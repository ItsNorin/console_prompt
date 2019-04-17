#include "console_prompt.h"

// displays msg, gets user's input, returns entire line as string
std::string prompt(const char *msg) {
	std::string repsonseStr;
	std::cout << msg;
	std::getline(std::cin, repsonseStr);
	return repsonseStr;
}


// avoids crashing if user doesnt enter anything for a prompt<char>
template<>
char prompt(const char *msg) {
	std::string response = prompt(msg);
	return (response.size() == 0) ? '\0' : response[0];
}


// gets a single keypress from user
// does not require enter key to be pressed
char promptChar_noEnter(const char *msg) {
	std::cout << msg;
	return _getch();
}

// gets a character from user, must be within the given valid list
// will keep asking until user enters a valid character
// will display failMessage after each failed attempt
char promptCharRestricted(const char *msg, std::string valid, std::string failMessage) {
	while (true) {
		char got = prompt<char>(msg);
		for (unsigned i = 0; i < valid.size(); i++)
			if (got == valid[i])
				return got;
		std::cout << failMessage;
	}
}

// forces user to respond either yes (y) or no (n) to asked message msg
// true if user enters a y or Y
// msg should inform user that they can only enter one of these characters: "yYnN"
bool promptYesNo(const char *msg) {
	return tolower(promptCharRestricted(msg, "yYnN", "Enter y or n\n")) == 'y';
}


