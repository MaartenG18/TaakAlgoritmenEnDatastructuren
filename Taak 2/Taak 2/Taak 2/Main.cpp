#include "Parser.h"
#include "UI.h"

int main()
{
	UI* ui = new UI();
	Parser* parser = new Parser();
	parser->readActors("actorsKort.txt");
	//parser->readMovies("moviesKort.txt");
	while (ui->askInput() != "q") {
		ui->askInput();
	};
}