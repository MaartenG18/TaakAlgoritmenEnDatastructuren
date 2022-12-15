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
	

	for (int index = 0; index < vertices->size(); index++)
	{
		addVertex(vertices->at(index));
		indexMap[vertices->at(index)] = index;
	}

	for (int k = 0; k < vertices->size(); k++)
	{
		getAdjacencyMatrix()->push_back(std::vector<int>(vertices->size(), 0));
	}


	for (const auto& edge : *edges)
	{
		int i = indexMap.at(edge.first);
		int j = indexMap.at(edge.second);

		addEdge(i, j);
	}

	changeGraphToComplement();

	// om te checken
	visualizeGraph();
}

void Graph::changeGraphToComplement()
{
	for (int i = 0; i < getAdjacencyMatrix()->size(); i++) {
		for (int j = 0; j < getAdjacencyMatrix()->size(); j++) {
			if (i < j) {
				if (getAdjacencyMatrix()->at(j)[i] == 0) {
					addEdge(i, j);
				}
				else {
					removeEdge(i, j);
				}
			}
		}
	}
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

void Graph::setAdjacencyMatrix(std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix)
{
	m_adjacencyMatrix = adjacencyMatrix;
}


// ----- Getters -----

std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> Graph::getVertices()
{
	return m_vertices;
}

std::shared_ptr<std::vector<std::vector<int>>> Graph::getAdjacencyMatrix() const
{
	return m_adjacencyMatrix;
}