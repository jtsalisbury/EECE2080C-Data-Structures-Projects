// Lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Classes.h";

using namespace std;

int main()
{
	cout << "Enter 1 to create blank graph.\n";
	cout << "Enter 2 to create a graph from an Adjacency Matrix.\n";
	cout << "Enter option: ";
	
	int option;
	string path;
	cin >> option;

	// Validate
	while (option != 1 && option != 2) {
		cout << "Invalid input! Try again: ";
		cin >> option;
	}

	Graph* g;
	ifstream input;

	// Blank graph
	if (option == 1) {
		
		cout << "Enter number of vertices: ";
		cin >> option;

		g = new Graph(option);
	} else {

		// Request path to file. 
		cout << "Note: Do NOT include row and column headers, and include no trailing spaces.\n";
		cout << "Enter full path to file: ";
		cin.ignore();
		getline(cin, path);
		input.open(path);

		// Ensure path is correct
		while (input.fail()) {
			cout << "Invalid path! Try again: ";
			getline(cin, path);

			input.open(path);
		}

		vector<string> rows;
		string str;
		int to;
		int col;

		// Push each row to a vector
		while (!input.eof()) {
			getline(input, str);

			rows.push_back(str);
		}

		// The number of rows is the number of vertices
		g = new Graph(rows.size());

		// Loop through each row in the row vector
		for (int row = 0; row < rows.size(); row++) {
			istringstream r(rows[row]);

			col = 0;

			// Loop through each split character (split using a space)
			while (getline(r, str, ' ')) {

				// If there's a 1, add an edge
				if (str == "1") {
					g->addEdge(row, col);
				}

				col++;
			}
		}

		// Close the file connection and print the matrix!
		input.close();

		cout << "\nSuccessfully imported matrix!\n\n";
		g->printMatrix();
	}

	int i, j;

	while (true) {		
		cout << "\n---------------------------------------------\n";
		cout << "Enter 1 to add an edge to graph." << endl;
		cout << "Enter 2 remove an edge from graph." << endl;
		cout << "Enter 3 Find an edge in the graph." << endl;
		cout << "Enter 4 Find the out edges of a vertices" << endl;
		cout << "Enter 5 Find the in edges of a vertices" << endl;
		cout << "Enter 6 To Print out Adjacency Matrix" << endl;
		cout << "Enter 7 to quit." << endl;

		cout << "Enter option: ";

		cin >> option;

		while (option > 7 || option < 0) {
			cout << "Invalid option! Try again: ";
			cin >> option;
		}

		if (option == 1) {

			cout << "What edge would you like to add? (Edge(i,j))" << endl;
			cout << "i: ";
			cin >> i;
			cout << "j: ";
			cin >> j;
			g->addEdge(i, j);
		}
		if (option == 2) {

			cout << "What edge would you like to remove? (Edge(i,j))" << endl;
			cout << "i: ";
			cin >> i;
			cout << "j: ";
			cin >> j;
			g->removeEdge(i, j);
		}
		if (option == 3) {

			cout << "What edge would you like to find? (Edge(i,j))" << endl;
			cout << "i: ";
			cin >> i;
			cout << "j: ";
			cin >> j;
			cout << (g->hasEdge(i, j) ? "Found!" : "Not found!");
		}
		if (option == 4) {

			int from;
			cout << "Enter the from edge" << endl;
			cout << "From: ";
			cin >> from;
			vector<int> out = g->outEdges(from);
			for(int i=0; i<out.size();i++){
				cout << out[i] << ", ";
			}
			cout << endl;
		}
		if (option == 5) {

			int to;
			cout << "Enter the to edge" << endl;
			cout << "To: ";
			cin >> to;
			vector<int> in = g->inEdges(to);
			for (int i = 0; i < in.size(); i++) {
				cout << in[i] << ", ";
			}
			cout << endl;
		}
		if (option == 6) {

			g->printMatrix();
		}
		if (option == 7) {

			break;
		}
	}

	return 0;
}
