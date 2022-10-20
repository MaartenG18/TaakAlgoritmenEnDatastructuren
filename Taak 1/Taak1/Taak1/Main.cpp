// Yara Mijnendonckx
// Simon Knuts
// Maarten Gielkens

#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string myText;

	std::ifstream myReadFile("keywords.txt");

	while (std::getline(myReadFile, myText))
		std::cout << myText << std::endl;
	myReadFile.close();

	return 0;
}

