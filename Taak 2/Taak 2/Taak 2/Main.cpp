#include "Parser.h"
#include "UI.h"
#include "SearchEngine.h"

int main()
{
	SearchEngine* searchEngine = new SearchEngine();
	searchEngine->start();

	return 0;
}