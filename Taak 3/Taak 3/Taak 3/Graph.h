#pragma once

#include <vector>
#include <memory>
#include "Vertex.h"

class Graph
{
public:
	Graph(); // Constructor

	void makeGraph(std::shared_ptr<std::vector<std::string>> vertices, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> edges);
	void changeGraphToComplement();
	void visualizeGraph();
	void graphColouring(int numberOfVertices);

private:
	void addVertex(std::string message); // Method to add a new vertex
	void addEdge(int i, int j); // Method to add an edge between two vertices
	void removeEdge(int i, int j); // Method to remove an edge between two vertices
	bool graphColouringIsSafe(int v, std::shared_ptr<std::vector<std::vector<int>>> graph, std::shared_ptr<int[]> colours, int c, int numberOfVertices);
	bool graphColoringUtil(std::shared_ptr<std::vector<std::vector<int>>> graph, int numberOfVertices, std::shared_ptr<int[]> colours, int v);

	std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> m_vertices;
	int m_numberOfVertices;
	std::shared_ptr<std::vector<std::vector<int>>> m_adjacencyMatrix;
	std::shared_ptr<int[]> m_colours;

	void setVertices(std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> vertices); // Setter
	void setNumberOfVertices(int numberOfVertices); // Setter
	void setAdjacencyMatrix(std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix); // Setter
	void setColours(std::shared_ptr<int[]> colours); // Setter

	std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> getVertices(); // Getter
	int getNumberOfVertices(); // Getter
	std::shared_ptr<std::vector<std::vector<int>>> getAdjacencyMatrix() const; // Getter
	std::shared_ptr<int[]> getColours(); // Getter
};