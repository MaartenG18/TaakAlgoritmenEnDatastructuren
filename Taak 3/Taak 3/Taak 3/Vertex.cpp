// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "vertex.h"


// ----- Constructors -----

Vertex::Vertex(std::string message) : m_message{ message }
{

}


// ----- Getters -----

std::string Vertex::getMessage() const
{
	return m_message;
}