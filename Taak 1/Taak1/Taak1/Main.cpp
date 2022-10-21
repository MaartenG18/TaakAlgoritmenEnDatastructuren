// Yara Mijnendonckx
// Simon Knuts
// Maarten Gielkens

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int lineNumber{ 0 };
int totalWordsRead{ 0 };
int totalKeywords{ 0 };
std::string keyWord;
std::string token;
std::string line;
std::unordered_map<std::string, int> hash;

void readKeywords();
void draw();
void algorithm(std::string fileName);

int main() {

	// ----- READING KEYWORDS -----
	readKeywords();

	// ----- EXUCUTING ALGORITHM -----
	algorithm("SampleText1.txt");
	
	// ----- DRAWING RESULTS -----
	draw();

	return 0;
}

void readKeywords() // Reads the keywords from a txt file and puts them in an unordered map
{
	std::ifstream keyWordFile("keywords.txt");


	while (std::getline(keyWordFile, keyWord)) {
		hash[keyWord] = 0;
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
		std::cout << "\t" << x.first << ": " << x.second << " Lines: " << ", " << std::endl;
	}

	std::cout << "Total key words: " << totalKeywords << std::endl;
}

void algorithm(std::string fileName)
{
	std::ifstream sampleTextFile(fileName);

	while (std::getline(sampleTextFile, line)) {
		lineNumber++;
		std::vector<std::string> tokens;

		for (int i = 0; i < line.length(); i++)
		{
			if (isspace(line[i])) // TODO Code properder schrijven, misschien een functie voor maken
			{
				token = line.substr(0, i); // selecting the first word and passing it to the translate function.
				line = line.substr(i + 1); // removing the first word from the sentence
				i = 0; // starting again at the start of the sentence
				tokens.push_back(token);
				totalWordsRead++;
			}
			else if (i == line.length() - 1)
			{
				token = line.substr(0, i + 1); // selecting the first word and passing it to the translate function
				line = line.substr(i + 1); // removing the first word from the sentence
				i = 0; // starting again at the start of the sentence
				tokens.push_back(token);
				totalWordsRead++;
			}
		}

		
	}

	sampleTextFile.close();
}