#include "Parser.h"
#include "UI.h"

int main()
{
	UI* ui = new UI();
	Trie* trie = new Trie();
	Parser* parser = new Parser();
	parser->readActors(trie, "actorsKort.txt");
	//parser->readMovies(trie, "moviesKort.txt");

	while (true)
	{
		std::string input = ui->askInput(trie);
		if (input != "q") {
			ui->processInput(trie, input);
		}
		else
		{
			return 0;
		}
	}
}