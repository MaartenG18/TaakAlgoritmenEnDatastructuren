#pragma once

#include <string>
#include <vector>

class Parser
{
public:
	Parser();
	void readActors(std::string fileName);
	void readMovies(std::string fileName);

private:
	std::vector<std::string> splitLineActor(std::string line);
	std::vector<std::string> splitLineMovie(std::string line);
};