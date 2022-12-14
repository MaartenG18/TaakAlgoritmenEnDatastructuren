// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "SearchEngine.h"


// ----- Constructors -----

SearchEngine::SearchEngine()
{

}


// ----- Methods -----

void SearchEngine::start()
{
	auto ui = std::make_shared<UI>();
	setUi(ui);

	auto trie = std::make_shared<Trie>();
	setTrie(trie);

	auto parser = std::make_shared<Parser>();
	setParser(parser);

	auto map = std::make_shared<std::unordered_map<std::string, std::vector<std::string>>>();
	setMovieMap(map);

	getParser()->readActors(trie, "actors100K.txt");
	getParser()->readMovies(trie, "movies100K.txt", getMovieMap());

	while (true)
	{
		std::string input = ui->askInput();
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

void SearchEngine::processInput(std::string input) // Method that processes the input
{
	if (input.size() == 4 && (input[0] == '1' || input[0] == '2')) {
		if (getMovieMap()->find(input) == getMovieMap()->end()) {
			getUi()->printError(UI::ErrorType::wordNotFound);
		}
		else {
			getUi()->printFilmsFromYear(getMovieMap()->at(input));
		}
	}
	else if (input.back() == '#')
	{
		input.pop_back();
		auto results = getTrie()->searchAndAutoComplete(input);

		if (results->empty())
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
			//getUi()->askInput(getTrie());
		}

		getUi()->printResults(results);
	}
}


// ----- Setters -----

void SearchEngine::setUi(std::shared_ptr<UI> ui)
{
	m_ui = ui;
}

void SearchEngine::setTrie(std::shared_ptr<Trie> trie)
{
	m_trie = trie;
}

void SearchEngine::setParser(std::shared_ptr<Parser> parser)
{
	m_parser = parser;
}

void SearchEngine::setMovieMap(std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> map) {
	m_movieMap = map;
}


// ----- Getters -----

std::shared_ptr<UI> SearchEngine::getUi() const
{
	return m_ui;
}

std::shared_ptr<Trie> SearchEngine::getTrie() const
{
	return m_trie;
}

std::shared_ptr<Parser> SearchEngine::getParser() const
{
	return m_parser;
}

std::shared_ptr<std::unordered_map<std::string, std::vector<std::string>>> SearchEngine::getMovieMap()
{
	return m_movieMap;
}