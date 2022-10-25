// Yara Mijnendonckx
// Simon Knuts
// Maarten Gielkens

// Aanpassingen tov de eerste versie:
// 1. Met klasses gewerkt waardoor er ook geen globale variabelen meer zijn
// 2. De punctuatie in een hashmap gezet ipv een vector, hierdoor is dit stukje qua tijdscomplexiteit beter

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