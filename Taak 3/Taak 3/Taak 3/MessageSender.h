#pragma once

#include <memory>
#include <string>
#include "Io.h"
#include "Parser.h"

class MessageSender 
{
public:
	MessageSender(); // Constructor

	void start(); // Method to start sending the messages

private:
	std::shared_ptr<Io> m_io{};
	std::shared_ptr<Parser> m_parser{};

	void setIo(std::shared_ptr<Io> io); // Setter
	void setParser(std::shared_ptr<Parser> parser); // Setter

	std::shared_ptr<Io> getIo() const; // Getter
	std::shared_ptr<Parser> getParser() const; // Getter
};