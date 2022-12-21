// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include <string>

class Vertex
{
public:
	Vertex(std::string message); // Constructor

	std::string getMessage() const; // Getter

private:
	std::string m_message{};
};