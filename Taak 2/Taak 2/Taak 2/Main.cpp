// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "SearchEngine.h"

int main()
{
	SearchEngine* searchEngine = new SearchEngine();
	searchEngine->start();

	delete searchEngine;
	return 0;
}