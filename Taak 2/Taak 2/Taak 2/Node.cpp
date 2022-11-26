// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "Node.h"


// ----- Constructors -----

Node::Node(bool endOfWord) : m_endOfWord{ endOfWord }
{
	auto map = std::make_shared<std::unordered_map<char, Node*>>();
	setMap(map);
}


// ----- Setters -----

void Node::setEndOfWord(bool endOfWord)
{
	m_endOfWord = endOfWord;
}

void Node::setMap(std::shared_ptr<std::unordered_map<char, Node*>> map)
{
	m_map = map;
}


// ----- Getters -----

bool Node::getEndOfWord() const
{
	return m_endOfWord;
}

std::shared_ptr<std::unordered_map<char, Node*>> Node::getMap()
{
	return m_map;
}