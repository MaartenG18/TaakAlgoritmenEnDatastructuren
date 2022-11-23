#pragma once

#include <string>
#include <unordered_map>
#include "Node.h"

//deze size is voor nu random gekozen, exact getal nog te bepalen
#define SIZE 64

class Trie
{
public:
	Trie();

	void insert(std::string str); // Method to insert in the trie
	std::shared_ptr<std::vector<std::string>> searchAndAutoComplete(std::string str); // Method to searchAndAutoComplete in the trie

private:
	Node* m_root{};

	Node* makeNewNode();
	void collectAllWords(Node* node, std::string prefix, std::string word, std::shared_ptr<std::vector<std::string>> words);

	void setRoot(Node* root); // Setter

	Node* getRoot() const; // Getter
};