#include "Parser.h"

int main()
{
	Parser* parser = new Parser();
	parser->readActors("actorsKort.txt");
	parser->readMovies("moviesKort.txt");
}