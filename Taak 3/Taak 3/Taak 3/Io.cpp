// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

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
	std::vector<std::vector<std::string>> solution;

	for (int i = 0; i < graph->getColours()->size(); i++)
	{
		if (solution.size() < graph->getColours()->at(i))
		{
			std::vector<std::string> newColour;
			newColour.push_back(graph->getVertices()->at(i)->getMessage());
			solution.push_back(newColour);
		}
		else
		{
			solution[graph->getColours()->at(i) - 1].push_back(graph->getVertices()->at(i)->getMessage());
		}
	}

	std::cout << "Oplossing:" << std::endl;

	for (int i = 0; i < graph->getNumberOfVertices(); i++)
	{
		std::cout << graph->getVertices()->at(i)->getMessage() << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < graph->getNumberOfVertices(); i++)
	{
		std::cout << "   " << graph->getColours()->at(i) << "   ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "De data zal dus worden verstuurd in " << solution.size() << " groepen, deze zijn: " << std::endl;

	for (int i = 0; i < solution.size(); i++)
	{
		std::cout << "Groep " << i + 1 << ": ";
		for (int j = 0; j < solution[i].size(); j++)
		{
			std::cout << solution[i][j];
			if (j != solution[i].size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}