#pragma once

#include "Trie.h"
#include <string>
#include <vector>

class Parser
{
public:
	Parser();
	void readActors(Trie* trie, std::string fileName); // Method that reads the actors and inserts it into the trie
	void readMovies(Trie* trie, std::string fileName, std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map); // Method that reads the movies and inserts it into the trie

private:
	std::vector<std::string> splitLineActor(std::string line); // Method that splits the line in the usefull parts
	std::vector<std::string> splitLineMovie(std::string line); // Method that spltis the line in the usefull parts
	void makeYearMap(std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map, std::vector<std::string> movie);
};