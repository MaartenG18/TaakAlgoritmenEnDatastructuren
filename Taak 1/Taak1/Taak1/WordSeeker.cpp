#include "WordSeeker.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>


WordSeeker::WordSeeker() {

}

void WordSeeker::readKeywords(std::string fileName) // Leest de keywords in vanuit een .txt file en plaatst ze in een unordered map.
{
	std::ifstream keyWordFile(fileName);

	// de keys zijn de keywords waarnaar gezocht wordt en de values van de hashmap zijn vectoren van ints
	// in deze vectoren is het eerste element altijd de teller van hoe vaak de key of keyword voorkomt in de tekst
	// en alle ints erachter zijn de lijnnummers van waar de keys of keywords in voorkomen
	while (std::getline(keyWordFile, keyWord))
		hash[keyWord].push_back(0);

	keyWordFile.close();
}

void WordSeeker::draw() // Tekent de output.
{
	std::cout << "**********************" << std::endl;
	std::cout << "***** Statistics *****" << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "Total lines read: " << lineNumber << std::endl;
	std::cout << "Total words read: " << totalWordsRead << std::endl;
	std::cout << "Break down by key word\n";

	for (auto x : hash)
		std::cout << "\t" << x.first << ": " << x.second[0] << "\t" << " Lines: " << getLines(x.second) << std::endl;

	std::cout << "Total key words: " << totalKeywords << std::endl;
}

std::string WordSeeker::getLines(std::vector<int> lineNumbers) // we vragen de lijnnummers van de keywords op, door over de vector (die de value is van de key) te loopen
{
	std::string lines;
	for (int i = 1; i < lineNumbers.size(); i++) {
		lines += std::to_string(lineNumbers[i]);
		if (i != lineNumbers.size() - 1)
			lines += ", ";
	}
	return lines;
}

void WordSeeker::algorithm(std::string fileName) // Zoekt en telt alle keywords.
{
	std::ifstream sampleTextFile(fileName);
	std::vector<std::string> tokens;
	std::vector<std::string> punctuation{ ",", "!", "?", "." }; // er kan nog extra punctuatie toegevoegd worden
	std::string lastLetter;

	while (std::getline(sampleTextFile, line)) {

		// enkel lijnen met tekst worden geteld
		if (line.length() > 0)
			lineNumber++;

		for (int i = 0; i < line.length(); i++) {

			if ((isspace(line[i])) || (i == line.length() - 1)) {
				if (i < line.length() - 1)
					token = line.substr(0, i);
				else
					token = line.substr(0, i + 1);

				line = line.substr(i + 1); // het eerste woord van de lijn verwijderen
				i = 0; // terug aan het begin van een lijn beginnen
				std::transform(token.begin(), token.end(), token.begin(), ::tolower); // de string tansformeren naar lowwercase

				// checkt of er punctuatie (, ! ? .) is en als dat het geval is, wordt deze verwijderd
				lastLetter = token.back();
				for (int j = 0; j < 4; j++) {
					if (lastLetter == punctuation[j]) {
						token.pop_back();
					}
				}

				tokens.push_back(token);
				totalWordsRead++;

				// we zoeken het huidige woord binnen de hashmap, als dit aanwezig is verhogen we de eerste waarde van de 
				// achterliggende vector met 1 (dit getal staat voor het aantal keer dat een bepaalde key in de tekst voorkomt)
				// vervolgens zetten we het lijnnummer, op welke lijn we het woord vonden, bij vanachter in de vector
				// er is voor een hashmap gekozen omdat zoeken in een hashmap worst-case tijdscomplexiteit O(1) heeft
				if (hash.find(token) != hash.end()) {
					hash[token][0]++;	// waarde verhogen voor de key van de unordered map
					hash[token].push_back(lineNumber);
					totalKeywords++;
				}
			}
		}
	}
	sampleTextFile.close();
}