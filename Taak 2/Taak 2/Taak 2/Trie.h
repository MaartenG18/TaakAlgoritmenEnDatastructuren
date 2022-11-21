#pragma once
#include <string>
#include <unordered_map>
//deze size is voor nu random gekozen, exact getal nog te bepalen
#define SIZE 64
class Trie
{
private:

public:
	//deze moet miss nog private staan
	std::unordered_map<char, Trie*> map;
	bool endOfWord;
	//tot hier
	Trie* getNewTrieNode();
	void insert(Trie*& root, std::string str);
	bool search(Trie* root, std::string str);
};
