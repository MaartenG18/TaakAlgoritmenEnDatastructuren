#include "Graph.h"
#include <unordered_map>
#include <iostream>

// ----- Constructors -----

Graph::Graph()
{
	auto vertices = std::make_shared<std::vector<std::shared_ptr<Vertex>>>();
	auto adjacencyMatrix = std::make_shared<std::vector<std::vector<int>>>();
	setVertices(vertices);
	setAdjacencyMatrix(adjacencyMatrix);
}


// ----- Methods -----

void Graph::addVertex(std::string message)
{
	auto vertex = std::make_shared<Vertex>(message);
	getVertices()->push_back(vertex);
}

void Graph::addEdge(int i, int j)
{
	getAdjacencyMatrix()->at(i)[j] = true;
	getAdjacencyMatrix()->at(j)[i] = true;
}

void Graph::removeEdge(int i, int j)
{
	getAdjacencyMatrix()->at(i)[j] = false;
	getAdjacencyMatrix()->at(j)[i] = false;
}

void Graph::makeGraph(std::shared_ptr<std::vector<std::string>> vertices, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> edges)
{
	std::unordered_map<std::string, int> indexMap;
	setNumberOfVertices(static_cast<int>(vertices->size()));
	
	for (int index = 0; index < getNumberOfVertices(); index++)
	{
		addVertex(vertices->at(index));
		indexMap[vertices->at(index)] = index;
	}

	for (int k = 0; k < getNumberOfVertices(); k++)
	{
		getAdjacencyMatrix()->push_back(std::vector<int>(getNumberOfVertices(), 0));
	}

	for (const auto& edge : *edges)
	{
		int i = indexMap.at(edge.first);
		int j = indexMap.at(edge.second);

		addEdge(i, j);
	}
}

void Graph::changeGraphToComplement()
{
	for (int i = 0; i < getAdjacencyMatrix()->size(); i++)
	{
		for (int j = 0; j < getAdjacencyMatrix()->size(); j++)
		{
			if (i < j)
			{
				if (getAdjacencyMatrix()->at(j)[i] == 0)
				{
					addEdge(i, j);
				}
				else
				{
					removeEdge(i, j);
				}
			}
		}
	}
}

bool Graph::graphColouringIsSafe(int v, std::shared_ptr<std::vector<std::vector<int>>> graph, std::shared_ptr<std::vector<int>> colours, int c, int numberOfVertices)
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (graph->at(v)[i] && c == colours->at(i))
		{
			return false;
		}
	}
	return true;
}

bool Graph::graphColoringUtil(std::shared_ptr<std::vector<std::vector<int>>> graph, int numberOfVertices, std::shared_ptr<std::vector<int>> colours, int v)
{
	if (v == numberOfVertices)
	{
		return true;
	}

	for (int c = 1; c <= numberOfVertices; c++)
	{
		if (graphColouringIsSafe(v, graph, colours, c, numberOfVertices))
		{
			colours->at(v) = c;

			if (graphColoringUtil(graph, numberOfVertices, colours, v + 1) == true)
			{
				return true;
			}

			colours->at(v) = 0;
		}
	}
	return false;
}

void Graph::graphColouring()
{
	auto colours = std::make_shared<std::vector<int>>(getNumberOfVertices());
	setColours(colours);

	for (int i = 0; i < getNumberOfVertices(); i++)
	{
		getColours()->at(i) = 0;
	}

	if (graphColoringUtil(getAdjacencyMatrix(), getNumberOfVertices(), getColours(), 0) == true)
	{
		//doorgeven van de array met kleuren en op de juiste manier verwerken, dit is maar om te testen
		printSolution(getColours());
	}
}

// om te testen:
void Graph::printSolution(std::shared_ptr<std::vector<int>> colours)
{
	std::cout << "Oplossing:" << std::endl;
	for (int i = 0; i < getNumberOfVertices(); i++)
		std::cout << " " << colours->at(i) << " ";

	std::cout << "\n";
}

void Graph::visualizeGraph()
{
	for (int i = 0; i < getAdjacencyMatrix()->size(); i++) {
		std::cout << " ---------------------------------" << std::endl;
		for (int j = 0; j < getAdjacencyMatrix()->size(); j++) {
			std::cout << " | ";
			std::cout << getAdjacencyMatrix()->at(i)[j];
			
		}
		std::cout << " |" << std::endl;
	}
	std::cout << " ---------------------------------" << std::endl;
}

// ----- Setters -----

void Graph::setVertices(std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> vertices)
{
	m_vertices = vertices;
}

void Graph::setNumberOfVertices(int numberOfVertices)
{
	m_numberOfVertices = numberOfVertices;
}

void Graph::setAdjacencyMatrix(std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix)
{
	m_adjacencyMatrix = adjacencyMatrix;
}

void Graph::setColours(std::shared_ptr<std::vector<int>> colours)
{
	m_colours = colours;
}


// ----- Getters -----

std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> Graph::getVertices()
{
	return m_vertices;
}

int Graph::getNumberOfVertices()
{
	return m_numberOfVertices;
}

std::shared_ptr<std::vector<std::vector<int>>> Graph::getAdjacencyMatrix() const
{
	return m_adjacencyMatrix;
}

std::shared_ptr<std::vector<int>> Graph::getColours()
{
	return m_colours;
}