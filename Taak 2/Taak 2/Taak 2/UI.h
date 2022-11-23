#pragma once

#include "Trie.h"
#include <string>

class UI
{
public:
	std::string askInput(Trie* trie);
	void processInput(Trie* trie, std::string input);
};