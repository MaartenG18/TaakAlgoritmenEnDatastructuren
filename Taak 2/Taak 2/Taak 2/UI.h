// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include "Trie.h"
#include <iostream>

class UI
{
public:
	enum class ErrorType {
		wordNotFound
	};

	UI();

	std::string askInput(Trie* trie);
	void printError(ErrorType errorType);
	void printResults(std::shared_ptr<std::vector<std::string>> results);
	void printFilmsFromYear(std::vector<std::string> FilmList);
};