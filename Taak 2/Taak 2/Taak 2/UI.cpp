#include "UI.h"
#include <string>
#include <iostream>

std::string UI::askInput(Trie* trie)
{
	std::string input;
	std::cout << "Enter search string, end in a '#' for suggestions. q to quit" << std::endl;
	std::getline(std::cin, input);

	return input;
}

void UI::processInput(Trie* trie, std::string input)
{
	if (input == "q")
	{
		return;
	}
	else if (input.back() == '#')
	{
		input.pop_back();
		auto results = trie->searchAndAutoComplete(input);

		if (results->size() == 0)
		{
			std::cout << "We cannot find anything like that." << std::endl;
		}

		for (int i = 0; i < results->size(); i++)
		{
			for (int j = 0; j < results->at(i).length(); j++)
			{
				if (results->at(i).at(j) == '_')	// Search for Firstname Lastname
				{
					std::string id = results->at(i).substr(j + 1, results->at(i).length() - (j + 1));
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
	else
	{
		auto results = trie->searchAndAutoComplete(input);

		if (results->size() == 0)	// die geeft een 'abort error' als de zoekterm niet in de trie zit
		{
			std::cout << "We cannot find anything like that." << std::endl;
		}

		for (int j = 0; j < results->at(0).length(); j++)
		{
			if (results->at(0).at(j) == '_')	// Search for Firstname Lastname
			{
				std::string id = results->at(0).substr(j + 1, results->at(0).length() - (j + 1));
				std::cout << results->at(0).substr(0, j) << " (" << id << ")" << std::endl;
			}
			if (results->at(0).at(j) == '$')	// Search for Lastname Firstname
			{
				std::string id = results->at(0).substr(j + 1, results->at(0).length() - (j + 1));
				std::cout << results->at(0).substr(0, j) << " (" << id << ")" << std::endl;
			}
		}
	}
}