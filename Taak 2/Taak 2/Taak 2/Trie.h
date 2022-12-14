// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include "Node.h"
#include <string>

class Trie
{
public:
	Trie();

	void insert(std::string str); // Method to insert in the trie
	std::shared_ptr<std::vector<std::string>> searchAndAutoComplete(std::string str); // Method to search and auto complete in the trie

private:
	std::shared_ptr<Node> m_root{};

	std::shared_ptr<Node> makeNewNode(); // Method to make a new node
	void collectAllWords(std::shared_ptr<Node> node, std::string prefix, std::string word, std::shared_ptr<std::vector<std::string>> words); // Method that finds all the possible words for a search input

	void setRoot(std::shared_ptr<Node> root); // Setter

	std::shared_ptr<Node> getRoot() const; // Getter
};