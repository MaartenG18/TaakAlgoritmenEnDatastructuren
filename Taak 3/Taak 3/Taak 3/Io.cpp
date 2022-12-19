#include "Io.h"
#include <iostream>
#include <memory>


// ----- Constructors -----

Io::Io()
{

}


// ----- Methods -----

void Io::visualizeGraph(std::shared_ptr<Graph> graph)
{
	for (int i = 0; i < graph->getAdjacencyMatrix()->size(); i++) {
		std::cout << " ---------------------------------" << std::endl;
		for (int j = 0; j < graph->getAdjacencyMatrix()->size(); j++) {
			std::cout << " | ";
			std::cout << graph->getAdjacencyMatrix()->at(i)[j];

		}
		std::cout << " |" << std::endl;
	}
	std::cout << " ---------------------------------" << std::endl;
}

void Io::printSolution(std::shared_ptr<Graph> graph)
{
	std::vector<std::vector<std::string>> oplossing;
	for (int i = 0; i < graph->getColours()->size(); i++) {
		if (oplossing.size() < graph->getColours()->at(i)) {
			std::vector<std::string> nieuweKleur;
			nieuweKleur.push_back(graph->getVertices()->at(i)->getMessage());
			oplossing.push_back(nieuweKleur);
		}
		else {
			oplossing[graph->getColours()->at(i) - 1].push_back(graph->getVertices()->at(i)->getMessage());
		}
	}
	std::cout << "oplossing:" << std::endl;
	for (int i = 0; i < graph->getNumberOfVertices(); i++) {
		std::cout << graph->getVertices()->at(i)->getMessage() << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < graph->getNumberOfVertices(); i++) {
		std::cout << "   " << graph->getColours()->at(i) << "   ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "de data zal dus worden verstuurd in " << oplossing.size() << " groepen, deze zijn: " << std::endl;
	for (int i = 0; i < oplossing.size(); i++) {
		std::cout << "groep " << i + 1 << ": ";
		for (int j = 0; j < oplossing[i].size(); j++) {
			std::cout << oplossing[i][j];
			if (j != oplossing[i].size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
}