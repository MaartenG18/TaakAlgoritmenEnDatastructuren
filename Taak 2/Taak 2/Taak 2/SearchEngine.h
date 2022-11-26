// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include "Parser.h"
#include "Trie.h"
#include "UI.h"

class SearchEngine
{
public:
	SearchEngine(); // Constructor

	void start(); // Method to start the search 

private:
	std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> m_movieMap{};
	UI* m_ui{};
	Trie* m_trie{};
	Parser* m_parser{};

	void processInput(std::string input);

	void setUi(UI* ui); // Setter
	void setTrie(Trie* trie); // Setter
	void setParser(Parser* parser); // Setter
	void setMovieMap(std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map); // Setter

	UI* getUi() const; // Getter
	Trie* getTrie() const; // Getter
	Parser* getParser() const; // Getter
	std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> getMovieMap(); // Getter
};