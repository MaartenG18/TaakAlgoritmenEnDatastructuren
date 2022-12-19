#pragma once

#include "Graph.h"

class Io
{
public:
	Io(); // Constructor

	void visualizeGraph(std::shared_ptr<Graph> graph); // Method to visualize a graph
	void printSolution(std::shared_ptr<Graph> graph); // Method to print the solution
};