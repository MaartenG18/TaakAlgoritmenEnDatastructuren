#include "Graph.h"
#include <unordered_map>
#include <iostream>
#include "Io.h"

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
	// van 'indexMap' misschien een membervariabele maken om makkelijker de output van graph colouring te kunnen verwerken
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

bool Graph::graphColouringIsSafe(int v, int c)  // [1]
{
	for (int i = 0; i < getNumberOfVertices(); i++)
	{
		if (getAdjacencyMatrix()->at(v)[i] && c == getColours()->at(i))
		{
			return false;
		}
	}
	return true;
}

bool Graph::graphColoringUtil(int v)  // [1]
{
	if (v == getNumberOfVertices())
	{
		return true;
	}

	for (int c = 1; c <= getNumberOfVertices(); c++)
	{
		if (graphColouringIsSafe(v, c))
		{
			getColours()->at(v) = c;

			if (graphColoringUtil(v + 1) == true)
			{
				return true;
			}

			getColours()->at(v) = 0;
		}
	}
	return false;
}

bool Graph::graphColouring() // [1]
{
	auto colours = std::make_shared<std::vector<int>>(getNumberOfVertices());
	setColours(colours);

	for (int i = 0; i < getNumberOfVertices(); i++)
	{
		getColours()->at(i) = 0;
	}

	if (graphColoringUtil(0) == true)
	{
		//doorgeven van de array met kleuren en op de juiste manier verwerken, dit is maar om te testen
		return true;
	}

	return false;
}

void Graph::rotateGraph()
{
	std::vector<int> row1{};
	std::vector<int> column1{};

	for (int j = getAdjacencyMatrix()->size() - 1; j >= 0; j--) {
		row1.push_back(getAdjacencyMatrix()->at(0)[j]);
	}

	for (int i = getAdjacencyMatrix()->size() - 1; i >= 0 ; i--) {
		column1.push_back(getAdjacencyMatrix()->at(i)[0]);
	}

	for (int i = 1; i < getAdjacencyMatrix()->size(); i++) {
		for (int j = 1; j < getAdjacencyMatrix()->size(); j++) {
			getAdjacencyMatrix()->at(i-1)[j-1] = getAdjacencyMatrix()->at(i)[j];
		}
	}

	for (int j = 0; j < row1.size(); j++) {
		getAdjacencyMatrix()->at(getAdjacencyMatrix()->size() - 1)[j] = row1[j];
	}

	for (int i = 0; i < column1.size(); i++) {
		getAdjacencyMatrix()->at(i)[getAdjacencyMatrix()->size() - 1] = column1[i];
	}


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

/*
Bronvermelding:
[1] GeeksforGeeks. (2022, 23 september). m Coloring Problem | Backtracking-5. 
https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
*/