// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "Parser.h"
#include <string>
#include <sstream>
#include <iostream>


// ----- Constructors -----

Parser::Parser()
{

}


// ----- Methods -----

std::shared_ptr<std::vector<std::string>> Parser::readMessages(std::string fileName)
{
	std::string messageLine{};

	auto messages = std::make_shared<std::vector<std::string>>();

	std::ifstream file(fileName);

	std::getline(file, messageLine);

	file.close();

	splitMessages(messageLine, messages);

	return messages;
}

std::shared_ptr<std::vector<std::pair<std::string, std::string>>> Parser::readCompatibilities(std::string fileName)
{
	std::string compatibilityLine{};

	auto compatibilities = std::make_shared<std::vector<std::pair<std::string, std::string>>>();

	std::ifstream file(fileName);

	// Reading and overwriting the first two lines
	std::getline(file, compatibilityLine);
	std::getline(file, compatibilityLine);

	while (std::getline(file, compatibilityLine))
	{
		splitCompatibilities(compatibilityLine, compatibilities);
	}

	return compatibilities;
}

void Parser::splitMessages(std::string messageLine, std::shared_ptr<std::vector<std::string>> messages)
{
	std::string message{};

	std::stringstream stream(messageLine);

	// Remove the first word "Message"
	stream >> message;

	while (stream >> message)
	{
		if (message.back() == ',')
		{
			message.pop_back();
		}
		messages->push_back(message);
	}
}

void Parser::splitCompatibilities(std::string compatibilityLine, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> compatibilities)
{
	int messageIndex = 1;
	std::string message{};
	std::pair<std::string, std::string> compatibility{};

	std::stringstream stream(compatibilityLine);

	while (stream >> message)
	{
		if (messageIndex == 1)
		{
			compatibility.first = message;
			messageIndex++;
		}
		else if (messageIndex == 2)
		{
			messageIndex++;
		}
		else if (messageIndex == 3)
		{
			if (message.back() == ';')
			{
				message.pop_back();
			}
			compatibility.second = message;
			compatibilities->push_back(compatibility);
			std::pair<std::string, std::string> compatibility{};
			messageIndex = 1;
		}	
	}
}