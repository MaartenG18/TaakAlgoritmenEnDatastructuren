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
	Node* m_root{};

	Node* makeNewNode();
	void collectAllWords(Node* node, std::string prefix, std::string word, std::shared_ptr<std::vector<std::string>> words);

	void setRoot(Node* root); // Setter

	Node* getRoot() const; // Getter
};