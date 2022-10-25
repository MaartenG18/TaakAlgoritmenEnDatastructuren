// Yara Mijnendonckx
// Simon Knuts
// Maarten Gielkens

#include "WordSeeker.h"

int main()
{
	WordSeeker * wordSeeker = new WordSeeker();

	// ----- KEYWORDS INLEZEN -----
	wordSeeker->readKeywords("keywords.txt");

	// ----- ALGORITME UITVOEREN -----
	wordSeeker->algorithm("SampleText1.txt");
	
	// ----- RESULTATEN TEKENEN -----
	wordSeeker->draw();

	return 0;
}

