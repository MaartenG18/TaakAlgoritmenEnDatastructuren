// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#pragma once

#include <vector>
#include <memory>
#include "Vertex.h"

class Graph
{
public:
	Graph(); // Constructor

	void makeGraph(std::shared_ptr<std::vector<std::string>> vertices, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> edges);
	void changeGraphToComplement(); // Method to get the complement of the graph
	bool graphColouring(); // Method to colour the graph
	void rotateGraph(); // Method to get all the permutations of the graph
	
	int getNumberOfVertices(); // Getter
	std::shared_ptr<std::vector<int>> getColours(); // Getter
	std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> getVertices(); // Getter
	std::shared_ptr<std::vector<std::vector<int>>> getAdjacencyMatrix() const; // Getter

private:
	int m_numberOfVertices{};
	std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> m_vertices{};
	std::shared_ptr<std::vector<std::vector<int>>> m_adjacencyMatrix{};
	std::shared_ptr<std::vector<int>> m_colours{};

	void addVertex(std::string message); // Method to add a new vertex
	void addEdge(int i, int j); // Method to add an edge between two vertices
	void removeEdge(int i, int j); // Method to remove an edge between two vertices
	bool graphColouringIsSafe(int v, int c); // Method to check whether a colour can be used
	bool graphColoringUtil(int v); // Method to help the graphColouring method
	
	void setNumberOfVertices(int numberOfVertices); // Setter
	void setColours(std::shared_ptr<std::vector<int>> colours); // Setter
	void setVertices(std::shared_ptr<std::vector<std::shared_ptr<Vertex>>> vertices); // Setter
	void setAdjacencyMatrix(std::shared_ptr<std::vector<std::vector<int>>> adjacencyMatrix); // Setter

};