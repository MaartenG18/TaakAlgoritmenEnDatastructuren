#pragma once

#include <string>
#include <unordered_map>

class WordSeeker
{
public:
	WordSeeker();

	void readKeywords(std::string fileName);
	void algorithm(std::string fileName);
	void draw();

private:
	int lineNumber{ 0 };
	int totalWordsRead{ 0 };
	int totalKeywords{ 0 };
	std::string keyWord{};
	std::string token{};
	std::string line{};
	std::unordered_map<std::string, std::vector<int>> hash{};
	
	std::string getLines(std::vector<int> lineNumbers);
	
};