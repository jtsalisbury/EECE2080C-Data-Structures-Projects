// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CLASSES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CLASSES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CLASSES_EXPORTS
#define CLASSES_API __declspec(dllexport)
#else
#define CLASSES_API __declspec(dllimport)
#endif

#include <vector>
#include <iostream>


class CLASSES_API Node
{
private:
	int m_value;

public:
	Node();
	Node(int val);

	int getValue();
	void setValue(int i);
};

// This class is exported from the dll
class CLASSES_API Graph {
private:
	std::vector<std::vector<Node*>> m_vertices;

public:
	Graph();
	Graph(int size) :m_vertices(size) {};

	~Graph();

	void addEdge(int from, int to);
	void removeEdge(int from, int to);
	
	void printMatrix();

	int getSize();

	bool hasEdge(int from, int to);

	std::vector<int> outEdges(int from); // return all tos from a node
	std::vector<int> inEdges(int to); //return all froms to a node
};