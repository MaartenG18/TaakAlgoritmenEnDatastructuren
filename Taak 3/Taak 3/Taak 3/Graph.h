#pragma once

#include <vector>
#include <memory>
#include "Vertex.h"

class Graph
{
public:
	Graph(); // Constructor

	void addVertex(std::string message); // Method to add a new vertex
	void addEdge(int i, int j); // Method to add an edge between two vertices
	void removeEdge(int i, int j); // Method to remove an edge between two vertices

private:
	std::vector<std::shared_ptr<Vertex>> m_vertices;
	std::vector<std::vector<int>> m_adjacencyMatrix;

	std::vector<std::shared_ptr<Vertex>> getVertices(); // Getter
	std::vector<std::vector<int>> getAdjacencyMatrix() const; // Getter
};