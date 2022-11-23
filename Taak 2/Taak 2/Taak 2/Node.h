#pragma once

#include <unordered_map>
#include <memory>

class Node
{
public:
	Node(bool endOfWord); // Constructor for a Node

	void setEndOfWord(bool endOfWord); // Setter

	bool getEndOfWord() const; // Getter
	std::shared_ptr<std::unordered_map<char, Node*>> getMap(); // Getter

private:
	bool m_endOfWord{};
	std::shared_ptr<std::unordered_map<char, Node*>> m_map{};

	void setMap(std::shared_ptr<std::unordered_map<char, Node*>> map); // Setter
};