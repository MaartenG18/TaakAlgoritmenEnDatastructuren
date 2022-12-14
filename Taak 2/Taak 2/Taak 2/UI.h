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

	UI(); // UI constructor

	std::string askInput(); // Method to ask the input question
	void printError(ErrorType errorType); // Method to print an error
	void printResults(std::shared_ptr<std::vector<std::string>> results); // Method to print all the results
	void printFilmsFromYear(std::vector<std::string> FilmList); // Method to print all the movies from a given input
};