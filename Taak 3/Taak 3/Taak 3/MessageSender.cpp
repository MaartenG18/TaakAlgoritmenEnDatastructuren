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

	getParser()->readMessages("Messages.txt");
	getParser()->readCompatibilities("Messages.txt");
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


// ----- Getters -----

std::shared_ptr<Io> MessageSender::getIo() const
{
	return m_io;
}

std::shared_ptr<Parser> MessageSender::getParser() const
{
	return m_parser;
}