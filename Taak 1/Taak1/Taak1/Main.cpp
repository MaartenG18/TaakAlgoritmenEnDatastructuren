// Yara Mijnendonckx
// Simon Knuts
// Maarten Gielkens

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
	std::string myText;

	std::ifstream myReadFile("keywords.txt");

	std::unordered_map<std::string, int> hash;

	while (std::getline(myReadFile, myText)) {
		hash[myText] = 0;
	}

	// Key en values van hashmap printen
	for (auto x : hash) {
		std::cout << x.first << " " << x.second << std::endl;
	}

	myReadFile.close();

	return 0;
}