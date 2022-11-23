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
	bool search(std::string str); // Method to search in the trie

private:
	Node* m_root{};

	Node* makeNewNode();

	void setRoot(Node* root); // Setter

	Node* getRoot() const; // Getter
};