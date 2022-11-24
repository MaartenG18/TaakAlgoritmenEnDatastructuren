#include "UI.h"
#include <string>
#include <iostream>


// ----- Constructors -----

UI::UI()
{

}


// ----- Methods -----


std::string UI::askInput(Trie* trie)
{
	std::string input;
	std::cout << "Enter search string, end in a '#' for suggestions. q to quit" << std::endl;
	std::getline(std::cin, input);

	return input;
}

void UI::printError(ErrorType errorType)
{
	switch (errorType)
	{
	case UI::ErrorType::wordNotFound:
		std::cout << "We cannot find anything like that." << std::endl;
		break;
	default:
		break;
	}
}

void UI::printResults(std::shared_ptr<std::vector<std::string>> results)
{
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