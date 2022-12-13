#include "Graph.h"


// ----- Constructors -----

Graph::Graph()
{

}


// ----- Methods -----

void Graph::addVertex(std::string message)
{
	auto vertex = std::make_shared<Vertex>(message);
	getVertices().push_back(vertex);
	getAdjacencyMatrix().push_back(std::vector<int>(getVertices().size(), 0));
}

void Graph::addEdge(int i, int j)
{
	getAdjacencyMatrix()[i][j] = true;
}

void Graph::removeEdge(int i, int j)
{
	getAdjacencyMatrix()[i][j] = false;
}


// ----- Getters -----

std::vector<std::shared_ptr<Vertex>> Graph::getVertices()
{
	return m_vertices;
}

std::vector<std::vector<int>> Graph::getAdjacencyMatrix() const
{
	return m_adjacencyMatrix;
}