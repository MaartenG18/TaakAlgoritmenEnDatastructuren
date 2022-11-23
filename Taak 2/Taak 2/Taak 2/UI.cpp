#include "UI.h"
#include <string>
#include <iostream>

std::string UI::askInput() {
	std::string input;
	std::cout << "Enter search string, end in a '#' for suggestions. q to quit" << std::endl;
	std::getline(std::cin, input);

	if (input == "q")
	{
		std::cout << "Quit succeeded." << std::endl;
		return "";
	}
	else if (input.back() == '#') 
	{
		input = input.substr(0, input.size() - 1);
		std::cout << input << std::endl;
		return input;
	}
	else 
	{
		std::cout << input << std::endl;
		return input;
	}
}