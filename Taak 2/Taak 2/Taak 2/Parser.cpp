#include "Parser.h"
#include <fstream>
#include <iostream>


// ----- Constructors -----

Parser::Parser() {

}


// ----- Methods ------

void Parser::readActors(Trie* trie, std::string fileName)
{
	std::string line;

	std::ifstream file(fileName);

	while (std::getline(file, line))
	{
		//std::cout << line << std::endl;
		std::vector<std::string> actor = splitLineActor(line);
		//std::cout << actor[1] + ' ' + actor[2] + ' ' + actor[0] << std::endl;
		//std::cout << actor[0] + ' ' + actor[2] + ' ' + actor[1] << std::endl;
		trie->insert(actor[1] + '_' + actor[2] + ' ' + actor[0]);
		trie->insert("Narayana_A.L. 100");
		trie->insert(actor[2] + '$' + actor[1] + ' ' + actor[0]);
		//std::cout << trie->search("simon knuts") << std::endl;
		auto results = trie->search("Narayan");
		for (int i = 0; i < results->size(); i++)
		{
			std::cout << results->at(i) << std::endl;
		}
	}

	file.close();
}

void Parser::readMovies(Trie* trie, std::string fileName) 
{
	std::string line;

	std::ifstream file(fileName);

	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
		splitLineMovie(line);
	}

	file.close();
}

std::vector<std::string> Parser::splitLineActor(std::string line)
{
	std::string id{};
	std::string lastName{};
	std::string firstName{};

	int wordIndex = 1;

	std::vector<std::string> words{};

	for (int i = 0; i < line.length(); i++) {
		if (line.at(i) == '\t' && wordIndex == 1) 
		{
			id = line.substr(0, i);
			line = line.substr(i + 1);

			wordIndex++;
			i = 0;

			words.push_back(id);
		}
		else if (line.at(i) == ' ' && wordIndex == 2)
		{
			firstName = line.substr(0, i);
			line = line.substr(i + 1);

			wordIndex++;
			i = 0;

			words.push_back(firstName);
		}
		else if (line.at(i) == '\t' && wordIndex == 3)
		{
			lastName = line.substr(0, i);

			wordIndex++;
			i = 0;

			words.push_back(lastName);
		}
	}
	return words;
}

std::vector<std::string> Parser::splitLineMovie(std::string line)
{
	std::string id{};
	std::string name{};
	std::string year{};

	int wordIndex = 1;

	std::vector<std::string> words{};

	for (int i = 0; i < line.length(); i++) {
		if (line.at(i) == '\t' && wordIndex == 1)
		{
			id = line.substr(0, i);
			line = line.substr(i + 1);
			std::cout << id << std::endl;

			wordIndex++;
			i = 0;

			words.push_back(id);
		}
		else if (line.at(i) == '\t' && wordIndex == 2)
		{
			name = line.substr(0, i);
			line = line.substr(i + 1);
			std::cout << name << std::endl;

			wordIndex++;
			i = 0;

			words.push_back(name);
		}
		else if (line.at(i) == ' ' && line.at(i + 1) == ' ') {
			line = line.substr(i + 2);
			i = 0;
		}
		else if (line.at(i) == ')' && wordIndex == 3)
		{
			year = line.substr(1, i-1);
			std::cout << year << std::endl;

			wordIndex++;
			i = 0;

			words.push_back(year);
		}	
	}
	return words;
}