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
	std::shared_ptr<UI> m_ui{};
	std::shared_ptr<Trie> m_trie{};
	std::shared_ptr<Parser> m_parser{};

	void processInput(std::string input); // Method to process the input

	void setUi(std::shared_ptr<UI> ui); // Setter
	void setTrie(std::shared_ptr<Trie> trie); // Setter
	void setParser(std::shared_ptr<Parser> parser); // Setter
	void setMovieMap(std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map); // Setter

	std::shared_ptr<UI> getUi() const; // Getter
	std::shared_ptr<Trie> getTrie() const; // Getter
	std::shared_ptr<Parser> getParser() const; // Getter
	std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> getMovieMap(); // Getter
};