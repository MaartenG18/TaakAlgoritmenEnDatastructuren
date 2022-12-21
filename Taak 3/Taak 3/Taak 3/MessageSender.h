// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include <memory>
#include <string>
#include "Io.h"
#include "Parser.h"
#include "Graph.h"

class MessageSender 
{
public:
	MessageSender(); // Constructor

	void start(); // Method to start sending the messages

private:
	std::shared_ptr<Io> m_io{};
	std::shared_ptr<Parser> m_parser{};
	std::shared_ptr<Graph> m_graph{};

	void setIo(std::shared_ptr<Io> io); // Setter
	void setParser(std::shared_ptr<Parser> parser); // Setter
	void setGraph(std::shared_ptr<Graph> graph); // Setter

	std::shared_ptr<Io> getIo() const; // Getter
	std::shared_ptr<Parser> getParser() const; // Getter
	std::shared_ptr<Graph> getGraph() const; // Getter
};