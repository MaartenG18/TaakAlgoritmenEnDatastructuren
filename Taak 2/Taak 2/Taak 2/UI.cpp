#include "UI.h"
#include <string>
#include <iostream>

std::string UI::askInput(Trie* trie) {
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
		input.pop_back();

		std::cout << input << std::endl;
		return input;
	}
	else 
	{
		auto results = trie->searchAndAutoComplete(input);
		for (int i = 0; i < results->size(); i++)	//in principe maar 1 resultaat in de vector dus i kan door 0 vervangen worden
		{
			for (int j = 0; j < results->at(i).length(); j++)
			{
				if (results->at(i).at(j) == '_')	// Search for Firstname Lastname
				{
					std::string id = results->at(i).substr(j+1, results->at(i).length() - (j+1));
					std::cout << results->at(i).substr(0, j) << " (" << id << ")" << std::endl;
				}
				if (results->at(i).at(j) == '$')	// Search for Lastname Firstname
				{
					std::string id = results->at(i).substr(j + 1, results->at(i).length() - (j + 1));
					std::cout << results->at(i).substr(0, j) << " (" << id << ")" << std::endl;
				}
			}
		}
	}
}