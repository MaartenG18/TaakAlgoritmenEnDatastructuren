#include "Trie.h"
#include <string>

Trie* Trie::getNewTrieNode()
{
	Trie* node = new Trie;
	node->endOfWord = false;
	return node;
}

void Trie::insert(Trie*& root, std::string str)
{
	if (root == nullptr)
		root = getNewTrieNode();

	Trie* temp = root;
	for (int i = 0; i < str.length(); i++) {
		char x = str[i];
		if (temp->map.find(x) == temp->map.end())
			temp->map[x] = getNewTrieNode();

		temp = temp->map[x];
	}

	temp->endOfWord = true;
}

//search functie maakt nog een fout, insert werkt denk ik
/*bool Trie::search(Trie* root, std::string str)
{
	if (root == nullptr)
		return false;

	Trie* temp = root;
	for (int i = 0; i < str.length(); i++) {

		temp = temp->map[str[i]];

		if (temp == nullptr)
			return false;
	}

	return temp->endOfWord;
}*/
