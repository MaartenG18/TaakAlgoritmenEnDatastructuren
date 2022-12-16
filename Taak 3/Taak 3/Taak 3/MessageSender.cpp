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

	//getParser()->readMessages("Messages.txt");
	//getParser()->readCompatibilities("Messages.txt");

	getGraph()->makeGraph(getParser()->readMessages("Messages.txt"), getParser()->readCompatibilities("Messages.txt"));

	// om te checken
	getGraph()->visualizeGraph();

	getGraph()->changeGraphToComplement();

	// om te checken
	getGraph()->visualizeGraph();

	getGraph()->graphColouring();
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