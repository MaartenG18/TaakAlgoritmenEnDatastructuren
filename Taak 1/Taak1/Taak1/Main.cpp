// Yara Mijnendonckx
// Simon Knuts
// Maarten Gielkens

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>

int lineNumber{ 0 };
int totalWordsRead{ 0 };
int totalKeywords{ 0 };
std::string keyWord;
std::string token;
std::string line;
std::unordered_map<std::string, std::vector<int>> hash;

void readKeywords();
std::string getLines(std::vector<int> lineNumbers);
void draw();
void algorithm(std::string fileName);

int main()
{
	// ----- READING KEYWORDS -----
	readKeywords();

	// ----- EXUCUTING ALGORITHM -----
	algorithm("SampleText2.txt");
	
	// ----- DRAWING RESULTS -----
	draw();

	return 0;
}

void readKeywords() // Reads the keywords from a txt file and puts them in an unordered map
{
	std::ifstream keyWordFile("keywords.txt");


	while (std::getline(keyWordFile, keyWord)) {
		hash[keyWord].push_back(0);
	}

	keyWordFile.close();
}

void draw() // Draws the correct output.
{
	std::cout << "**********************" << std::endl;
	std::cout << "***** Statistics *****" << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "Total lines read: " << lineNumber << std::endl;
	std::cout << "Total words read: " << totalWordsRead << std::endl;
	std::cout << "Break down by key word\n";

	for (auto x : hash) {
		std::cout << "\t" << x.first << ": " << x.second[0] << " Lines: " << getLines(x.second) << std::endl;
	}

	std::cout << "Total key words: " << totalKeywords << std::endl;
}

std::string getLines(std::vector<int> lineNumbers)
{
	std::string lines;
	for (int i = 1; i < lineNumbers.size(); i++) {
		lines += std::to_string(lineNumbers[i]);
		if (i != lineNumbers.size() - 1) {
			lines += ", ";
		}
	}
	return lines;
}

void algorithm(std::string fileName)
{
	std::ifstream sampleTextFile(fileName);
	std::vector<std::string> tokens;
	std::vector<std::string> punctuation{ ",", "!", "?", "." };
	std::string lastLetter;

	//punctuation.push_back(",");

	// ",", "!", "?", "." 

	while (std::getline(sampleTextFile, line)) {
		
		if (line.length() > 0)
			lineNumber++;

		for (int i = 0; i < line.length(); i++){

			if ((isspace(line[i])) || (i == line.length() - 1)) { // TODO Code properder schrijven, misschien een functie voor maken
				if (i < line.length() - 1)
					token = line.substr(0, i); // selecting the first word and passing it to the translate function.
				else
					token = line.substr(0, i + 1);

				line = line.substr(i + 1); // removing the first word from the sentence
				i = 0; // starting again at the start of the sentence
				std::transform(token.begin(), token.end(), token.begin(), ::tolower); //transforming the string to all lowercase

				// check on punctuation (, ! ? .) and remove the punctuation if there is punctuation
				lastLetter = token.back();
				for (int j = 0; j < 4; j++) {
					if (lastLetter == punctuation[j]) {
						token.pop_back();
					}
				}

				tokens.push_back(token);
				totalWordsRead++;
				if (hash.find(token) != hash.end()) {
					hash[token][0]++;    // increment map's value for key
					hash[token].push_back(lineNumber);
					totalKeywords++;
				}
			}
		}
	}
	sampleTextFile.close();
}