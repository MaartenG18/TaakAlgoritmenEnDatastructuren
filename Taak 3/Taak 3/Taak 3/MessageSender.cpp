// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "MessageSender.h"


// ----- Constructors -----

MessageSender::MessageSender()
{

}


// ----- Methods

void MessageSender::start()
{
	auto parser = std::make_shared<Parser>();
	setParser(parser);

	auto graph = std::make_shared<Graph>();
	setGraph(graph);

	getGraph()->makeGraph(getParser()->readMessages("Messages.txt"), getParser()->readCompatibilities("Messages.txt"));

	getGraph()->changeGraphToComplement();

	if (getGraph()->graphColouring() == true)
	{
		getIo()->printSolution(getGraph());
	}

	for (int i = 0; i < getGraph()->getNumberOfVertices()-1; i++)
	{
		if (getGraph()->graphColouring() == true)
		{
			getIo()->printSolution(getGraph());
		}
		getGraph()->rotateGraph();

	}
}


// ----- Setters -----

void MessageSender::setIo(std::shared_ptr<Io> io)
{
	m_io = io;
}

void MessageSender::setParser(std::shared_ptr<Parser> parser)
{
	m_parser = parser;
}

void MessageSender::setGraph(std::shared_ptr<Graph> graph)
{
	m_graph = graph;
}


// ----- Getters -----

std::shared_ptr<Io> MessageSender::getIo() const
{
	return m_io;
}

std::shared_ptr<Parser> MessageSender::getParser() const
{
	return m_parser;
}

std::shared_ptr<Graph> MessageSender::getGraph() const
{
	return m_graph;
}