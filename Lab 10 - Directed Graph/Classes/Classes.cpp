// Classes.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Classes.h"

Node::Node()
{

}

Node::Node(int val)
{
	m_value = val;
}

int Node::getValue()
{
	return m_value;
}

void Node::setValue(int i)
{
	m_value = i;
}


Graph::Graph() {}

Graph::~Graph() {

	// Loop through each vertex's related vector and delete nodes
	for (int i = m_vertices.size() - 1; i >= 0; i--) {
		for (int j = m_vertices[i].size() - 1; j >= 0; j--) {
			delete m_vertices[i][j];
			
			m_vertices[i].erase(m_vertices[i].end());
		}
	}
}

int Graph::getSize() {
	return m_vertices.size();
}

void Graph::addEdge(int from, int to) {
	if (from > (getSize() - 1) || from < 0) {
		return;
	}

	if (to > (getSize() - 1) || to < 0) {
		return;
	}

	if (hasEdge(from, to)) {
		return;
	}
	
	m_vertices[from].push_back(new Node(to));
}

void Graph::removeEdge(int from, int to) {
	if (from > (getSize() - 1) || from < 0) {
		return;
	}
	if (to > (getSize() - 1) || to < 0) {
		return;
	}

	if (!hasEdge(from, to)) {
		return;
	}

	// Find the index that the to node is at
	int i = 0;
	for (; i < m_vertices[from].size(); i++) {
		if (m_vertices[from][i]->getValue() == to) {
			break;
		}
	}

	if (i == 0) {
		i = 1;
		delete m_vertices[from][0];
	}
	else {
		delete m_vertices[from][i];
	}
	
	// Remove it!
	m_vertices[from].erase(m_vertices[from].begin() + i - 1);
}

bool Graph::hasEdge(int from, int to) {
	if (from > (getSize() - 1) || from < 0) {
		return false;
	}
	if (to > (getSize() - 1) || to < 0) {
		return false;
	}
	
	std::vector<Node*> edges = m_vertices[from];

	// Search the vector related to the from vertex
	for(int i = 0; i < edges.size(); i++){
		if (edges[i]->getValue() == to)
			return true;
	}

	return false;
}

std::vector<int> Graph::outEdges(int from) {
	std::vector<int> t;
	
	if (from > (getSize() - 1) || from < 0) {
		return t;
	}

	// Add all the values for the noes in the from vector
	for (int i = 0; i < m_vertices[from].size(); i++) {
		t.push_back(m_vertices[from][i]->getValue());
	}

	return t;
}

std::vector<int> Graph::inEdges(int to) {
	std::vector<int> t;

	if (to > (getSize() - 1) || to < 0) {
		return t;
	}

	// Search all vectors for the to node; if found, add the value to the temp vector
	for (int row = 0; row < m_vertices.size(); row++) {
		for (int col = 0; col < m_vertices[row].size(); col++) {
			if (m_vertices[row][col]->getValue() == to) {
				t.push_back(row);
			}
		}
	}

	return t;
}

void Graph::printMatrix() {

	// Print out the header
	std::cout << "     ";

	for (int i = 0; i < m_vertices.size(); i++) {
		std::cout << " " << i;
	}

	std::cout << std::endl;

	int size = m_vertices.size();

	// Print out each row
	for (int row = 0; row < size; row++) {
		std::cout << " " << row << " | ";
		
		// Search the vector for each index position; that is, each vertex
		for (int col = 0; col < size; col++) {

			std::cout << (hasEdge(row, col) ? " 1" : " 0");
		}

		std::cout << std::endl;
	}
}