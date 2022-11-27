// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "Parser.h"


// ----- Constructors -----

Parser::Parser()
{

}


// ----- Methods ------

void Parser::readActors(Trie* trie, std::string fileName) // Method to read the file with actors and to insert them into the trie
{
	std::string line;

	std::ifstream file(fileName);

	while (std::getline(file, line))
	{
		std::vector<std::string> actor = splitLineActor(line);

		trie->insert(actor[1] + ' ' + actor[2] + '_' + actor[0]);	// Firstname Lastname_id
		trie->insert(actor[2] + ' ' + actor[1] + '$' + actor[0]);	// Lastname Firstname$id
	}

	file.close();
}

void Parser::readMovies(Trie* trie, std::string fileName, std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map) // Method to read the file with movies and to insert them into the trie. If there is a year given for a movie it stores that movie in the hasmap to use for searching on year.
{
	std::string line;

	std::ifstream file(fileName);

	while (std::getline(file, line))
	{
		std::vector<std::string> movie = splitLineMovie(line);

		trie->insert(movie[1] + ' ' + movie[2] + 'µ' + movie[0]);
		makeYearMap(map, movie);
	}

	file.close();
}

std::vector<std::string> Parser::splitLineActor(std::string line) // Method that splits the line in the necessary parts needed for storing them into a trie.
{
	std::string id{};
	std::string lastName{};
	std::string firstName{};

	int wordIndex = 1;

	std::vector<std::string> words{};

	for (int i = 0; i < line.length(); i++) {
		if (line.at(i) == '\t' && wordIndex == 1) 
		{
			id = line.substr(0, i);
			line = line.substr(i + 1);

			wordIndex++;
			i = 0;

			words.push_back(id);
		}
		else if (line.at(i) == ' ' && wordIndex == 2)
		{
			firstName = line.substr(0, i);
			line = line.substr(i + 1);

			wordIndex++;
			i = 0;

			words.push_back(firstName);
		}
		else if (line.at(i) == '\t' && wordIndex == 3)
		{
			lastName = line.substr(0, i);

			wordIndex++;
			i = 0;

			words.push_back(lastName);
		}
	}
	return words;
}

std::vector<std::string> Parser::splitLineMovie(std::string line) // Method that splits the line in the necessary parts needed for storing them into a trie.
{
	std::string id{};
	std::string name{};
	std::string year{};

	int wordIndex = 1;

	std::vector<std::string> words{};

	for (int i = 0; i < line.length(); i++)
	{
		if (line.at(i) == '\t' && wordIndex == 1)
		{
			id = line.substr(0, i);
			line = line.substr(i + 1);

			wordIndex++;
			i = 0;

			words.push_back(id);
		}
		else if (line.at(i) == '\t' && wordIndex == 2)
		{
			name = line.substr(0, i);
			line = line.substr(i + 1);

			wordIndex++;
			i = 0;

			words.push_back(name);
			words.push_back(" ");
		}
		else if (line.at(i) == ' ' && line.at(i + 1) == ' ')
		{
			line = line.substr(i + 2);
			i = 0;
		}
		else if (line.at(i) == ')' && wordIndex == 3)
		{
			year = line.substr(1, i-1);

			wordIndex++;
			i = 0;

			words[2] = year;
		}	
	}
	return words;
}

void Parser::makeYearMap(std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map, std::vector<std::string> movie) // Method that stores the movies with a year in the movie hashmap
{
	if (map->find(movie[2]) == map->end())
	{
		std::vector<std::string> movies{};
		movies.push_back('(' + movie[0] + ')' + ':' + ' ' + movie[1]);
		map->insert({movie[2], movies });
	}
	else
	{
		map->at(movie[2]).push_back('(' + movie[0] + ')' + ':' + ' ' + movie[1]);
	}
}