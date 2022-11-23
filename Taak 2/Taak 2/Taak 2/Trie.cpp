#include "Trie.h"
#include <string>


// ----- Constructors -----

Trie::Trie()
{
	setRoot(nullptr);
}


// ----- Methods -----

Node* Trie::makeNewNode()
{
	Node* node = new Node(false);
	return node;
}

void Trie::insert(std::string str)
{
	if (getRoot() == nullptr)
	{
		setRoot(makeNewNode());
	}

	Node* temp = getRoot();

	for (int i = 0; i < str.length(); i++) 
	{
		char x = str[i];
		if (temp->getMap()->find(x) == temp->getMap()->end())
		{
			std::pair<char, Node*> pair{ x, makeNewNode() };
			temp->getMap()->insert(pair);
		}

		temp = temp->getMap()->at(x);
	}

	temp->setEndOfWord(true);
}

//search functie maakt nog een fout, insert werkt denk ik
bool Trie::search(std::string str)
{
	if (getRoot() == nullptr)
	{
		return false;
	}

	Node* temp = getRoot();

	for (int i = 0; i < str.length(); i++) 
	{
		char x = str[i];
		if (temp->getMap()->find(x) == temp->getMap()->end())
		{
			return false;
		}
		else
		{
			temp = temp->getMap()->at(str[i]);
		}

		if (temp == nullptr)
			return false;
	}

	return temp->getEndOfWord();
}


// ----- Setters -----

void Trie::setRoot(Node* root)
{
	m_root = root;
}


// ----- Getters -----

Node* Trie::getRoot() const
{
	return m_root;
}