// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include <fstream>
#include <vector>

class Parser
{
public:
	Parser(); // Constructor

	std::shared_ptr<std::vector<std::string>> readMessages(std::string fileName); // Method to read all the messages
	std::shared_ptr<std::vector<std::pair<std::string, std::string>>> readCompatibilities(std::string fileName); // Method to read all the compatible messages

private:
	void splitMessages(std::string messageLine, std::shared_ptr<std::vector<std::string>> messages); // Method to split the line of messages into all the separate messages
	void splitCompatibilities(std::string compatibilityLine, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> compatibilities); // Method to split a line of compatibilities
};