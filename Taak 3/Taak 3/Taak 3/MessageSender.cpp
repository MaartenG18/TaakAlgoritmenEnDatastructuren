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

	// om te checken
	getIo()->visualizeGraph(getGraph());

	getGraph()->changeGraphToComplement();

	// om te checken
	if (getGraph()->graphColouring() == true)
	{
		getIo()->printSolution(getGraph());
	}
	getIo()->visualizeGraph(getGraph());


	for (int i = 0; i < getGraph()->getNumberOfVertices()-1; i++)
	{
		getIo()->visualizeGraph(getGraph());
		getGraph()->rotateGraph();

		if (getGraph()->graphColouring() == true)
		{
			getIo()->printSolution(getGraph());
		}
	}

	getIo()->visualizeGraph(getGraph());
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