#include "Graph.h"
#include <unordered_map>
#include <iostream> // niet vergeten weg te doen

// ----- Constructors -----

Graph::Graph()
{
	auto vertices = std::make_shared<std::vector<std::shared_ptr<Vertex>>>();
	setVertices(vertices);
}


// ----- Methods -----

void Graph::addVertex(std::string message)
{
	auto vertex = std::make_shared<Vertex>(message);
	//dit werkt nie 
	getVertices()->push_back(vertex);
	getAdjacencyMatrix().push_back(std::vector<int>(getVertices()->size(), 0));
}

void Graph::addEdge(int i, int j)
{
	getAdjacencyMatrix()[i][j] = true;
	getAdjacencyMatrix()[j][i] = true;
}

void Graph::removeEdge(int i, int j)
{
	getAdjacencyMatrix()[i][j] = false;
	getAdjacencyMatrix()[j][i] = false;
}

void Graph::makeGraph(std::shared_ptr<std::vector<std::string>> vertices, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> edges)
{
	// we kunnen de functies van addEdge en removeEdge ook ineens omkeren (de true en false)
	// dan hebben we direct de complement graaf

	Graph graph{};
	std::unordered_map<std::string, int> indexMap;
	int index = 0;

	for (const auto& vertex : *vertices)
	{
		graph.addVertex(vertex);
		indexMap[vertex] = index;
		index++;
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
		graph.addEdge(i, j);
	}
	
}

// ----- Setters -----

void Graph::setVertices(std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> vertices)
{
	m_vertices = vertices;
}


// ----- Getters -----

std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> Graph::getVertices()
{
	return m_vertices;
}

std::vector<std::vector<int>> Graph::getAdjacencyMatrix() const
{
	return m_adjacencyMatrix;
}