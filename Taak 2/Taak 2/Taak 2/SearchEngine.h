#pragma once

#include <string>
#include "Parser.h"
#include "Trie.h"
#include "UI.h"

class SearchEngine
{
public:
	SearchEngine(); // Constructor

	void start(); // Method to start the search engine

private:
	UI* m_ui{};
	Trie* m_trie{};
	Parser* m_parser{};

	void processInput(std::string input);

	void setUi(UI* ui); // Setter
	void setTrie(Trie* trie); // Setter
	void setParser(Parser* parser); // Setter

	UI* getUi() const; // Getter
	Trie* getTrie() const; // Getter
	Parser* getParser() const; // Getter
};