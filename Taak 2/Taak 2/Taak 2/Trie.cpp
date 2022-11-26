// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "Trie.h"


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

std::shared_ptr<std::vector<std::string>> Trie::searchAndAutoComplete(std::string str)
{
	auto results = std::make_shared<std::vector<std::string>>();

	if (getRoot() == nullptr)
	{
		return results;
	}

	Node* temp = getRoot();

	for (int i = 0; i < str.length(); i++) 
	{
		char x = str[i];
		if (temp->getMap()->find(x) == temp->getMap()->end())
		{
			return results;
		}
		else
		{
			temp = temp->getMap()->at(x);
		}
	}

	std::string word{};

	// Einde van de searchAndAutoComplete string bereikt
	collectAllWords(temp, str, word, results);
	return results;
}

void Trie::collectAllWords(Node* node, std::string prefix, std::string word, std::shared_ptr<std::vector<std::string>> words)
{
	Node* temp = node;

	for (auto i = temp->getMap()->begin(); i != temp->getMap()->end(); i++)
	{
		if (temp->getEndOfWord() == true)
		{
			words->push_back(prefix + word);
			word = "";
		}
		else
		{
			collectAllWords(temp->getMap()->at(i->first), prefix, word + i->first, words);
		}
	}

	if (temp->getEndOfWord() == true)
	{
		words->push_back(prefix + word);
		word = "";
	}
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