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
	void makeGraph(std::shared_ptr<std::vector<std::string>> vertices, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> edges);
	void changeGraphToComplement();
	void visualizeGraph();

private:
	std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> m_vertices;
	std::shared_ptr<std::vector<std::vector<int>>> m_adjacencyMatrix;

	void setVertices(std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> vertices);
	void setAdjacencyMatrix(std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix);

	std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> getVertices(); // Getter
	std::shared_ptr<std::vector<std::vector<int>>> getAdjacencyMatrix() const; // Getter
};