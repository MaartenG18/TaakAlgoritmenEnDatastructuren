#include "Parser.h"
#include "UI.h"

int main()
{
	UI* ui = new UI();
	Trie* trie = new Trie();
	Parser* parser = new Parser();
	parser->readActors(trie, "actorsKort.txt");
	//parser->readMovies(trie, "moviesKort.txt");

	ui->askInput(trie);
}