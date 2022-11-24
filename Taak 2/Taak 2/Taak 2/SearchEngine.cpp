#include "SearchEngine.h"
#include <iostream>


// ----- Constructors -----

SearchEngine::SearchEngine()
{

}


// ----- Methods -----

void SearchEngine::start()
{
	UI* ui = new UI();
	setUi(ui);

	Trie* trie = new Trie();
	setTrie(trie);

	Parser* parser = new Parser();
	setParser(parser);

	auto map = std::make_shared<std::unordered_map<std::string, std::vector<std::string>>>();
	setMovieMap(map);

	getParser()->readActors(trie, "actorsKort.txt");
	getParser()->readMovies(trie, "moviesKort.txt", getMovieMap());

	while (true)
	{
		std::string input = ui->askInput(trie);
		if (input != "q")
		{
			processInput(input);
		}
		else
		{
			return;
		}
	}
}

void SearchEngine::processInput(std::string input)
{
	if (input.size() == 4 && (input[0] == '1' || input[0] == '2')) {
		if (m_movieMap->find(input) == m_movieMap->end()) {
			getUi()->printError(UI::ErrorType::wordNotFound);
		}
		else {
			getUi()->printFilmsFromYear(m_movieMap->at(input));
		}
	}
	else if (input.back() == '#')
	{
		input.pop_back();
		auto results = getTrie()->searchAndAutoComplete(input);

		if (results->size() == 0)
		{
			getUi()->printError(UI::ErrorType::wordNotFound);
		}

		getUi()->printResults(results);
	}
	else
	{
		auto results = getTrie()->searchAndAutoComplete(input);

		if (results->empty())
		{
			getUi()->printError(UI::ErrorType::wordNotFound);
			getUi()->askInput(getTrie());
		}

		getUi()->printResults(results);
	}
}


// ----- Setters -----

void SearchEngine::setUi(UI* ui)
{
	m_ui = ui;
}

void SearchEngine::setTrie(Trie* trie)
{
	m_trie = trie;
}

void SearchEngine::setParser(Parser* parser)
{
	m_parser = parser;
}

void SearchEngine::setMovieMap(std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map) {
	m_movieMap = map;
}


// ----- Getters -----

UI* SearchEngine::getUi() const
{
	return m_ui;
}

Trie* SearchEngine::getTrie() const
{
	return m_trie;
}

Parser* SearchEngine::getParser() const
{
	return m_parser;
}

std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> SearchEngine::getMovieMap()
{
	return m_movieMap;
}