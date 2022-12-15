#include "Graph.h"
#include <unordered_map>
#include <iostream> // niet vergeten weg te doen

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
	//dit werkt nie 
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
	// we kunnen de functies van addEdge en removeEdge ook ineens omkeren (de true en false)
	// dan hebben we direct de complement graaf

	std::unordered_map<std::string, int> indexMap;
	int index = 0;

	for (const auto& vertex : *vertices)
	{
		addVertex(vertex);
		indexMap[vertex] = index;
		index++;
	}
	for (int k = 0; k < index; k++) {
		getAdjacencyMatrix()->push_back(std::vector<int>(index, 0));
	}
	// om de map te testen
	for (auto& x : indexMap) {
		std::cout << x.first << ": " << x.second << std::endl;
	}

	for (const auto& edge : *edges)
	{
		int i = indexMap.at(edge.first);
		int j = indexMap.at(edge.second);

		// deze regel crasht omdat de size van de adjacency matrix nergens bepaald is volgens mij
		addEdge(i, j);
	}
	visualizeGraph();
	std::cout << getAdjacencyMatrix()->at(2)[1] << std::endl;
	changeGraphToComplement();
	std::cout << getAdjacencyMatrix()->at(2)[1] << std::endl;
	visualizeGraph();
	
}

void Graph::changeGraphToComplement()
{
	for (int i = 0; i < getAdjacencyMatrix()->size(); i++) {
		for (int j = 0; j < getAdjacencyMatrix()->size(); j++) {
			if (i != j) {
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