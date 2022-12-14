// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include <unordered_map>
#include <memory>

class Node
{
public:
	Node(bool endOfWord); // Constructor for a Node

	void setEndOfWord(bool endOfWord); // Setter

	bool getEndOfWord() const; // Getter
	std::shared_ptr<std::unordered_map<char, std::shared_ptr<Node>>> getMap(); // Getter

private:
	bool m_endOfWord{};
	std::shared_ptr<std::unordered_map<char, std::shared_ptr<Node>>> m_map{};

	void setMap(std::shared_ptr<std::unordered_map<char, std::shared_ptr<Node>>> map); // Setter
};