#include "pch.h"
#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

int main()
{
	// Values to add to the tree
	string a[4] = { "Star Wars", "Star Trek", "Space Balls", "Galaxy Quest" };
	string b[4] = { "Cars", "Monsters , Inc", "The Incredibles", "Wall - E" };
	string c[4] = { "Halloween", "A Nightmare On Elm Street", "Hocus Pocus", "Beetlejuice" };

	// Tree instantiation
	Tree* tree = new Tree();
	Node* n;

	cout << "------------- TESTING INSERTION ------------- " << endl;
	cout << "a)" << endl;

	// Add the values from array a to the tree
	for (int i = 0; i < 4; i++) {
		n = new Node(a[i]);
		tree->insert(n);
	}

	// Print the tree in ascending and descending order
	cout << "Ascending: ";
	vector<string> v = tree->GetAllAscending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << "\nDescending: ";
	v = tree->GetAllDescending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}

	// The values from array b into the tree
	for (int i = 0; i < 4; i++) {
		n = new Node(b[i]);
		tree->insert(n);
	}

	// Print the tree in ascending and descending order
	cout << "\n\nb)" << endl;
	cout << "Ascending: ";
	v = tree->GetAllAscending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << "\nDescending: ";
	v = tree->GetAllDescending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}

	// Add the values from array c into the three
	for (int i = 0; i < 4; i++) {
		n = new Node(c[i]);
		tree->insert(n);
	}

	// Print the values from the tree in ascending and descending order
	cout << "\n\nc)" << endl;
	cout << "Ascending: ";
	v = tree->GetAllAscending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << "\nDescending: ";
	v = tree->GetAllDescending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}

	cout << "\n\n\n\n";
	cout << "------------- TESTING FIND -------------" << endl;

	// Try to find a node in the tree
	n = tree->find("Cars");
	cout << "Target: Cars" << endl << "Actual: " << n->getValue() << endl;
	n = tree->find("Aasdf");
	cout << "Target: Aasdf" << endl << "Actual: " << ((n == nullptr) ? "nullptr" : "err") << endl;


	cout << "\n\n\n";
	cout << "------------- TESTING REMOVAL -------------" << endl;

	// Try to remove a node from the tree
	cout << "Removing Cars..\n";

	Node* removed = tree->Remove("Cars");
	cout << "Node value: " << removed->getValue() << endl;

	// Reprint the tree to ensure it's correct
	cout << "Re-ordered tree (ascending): ";
	v = tree->GetAllAscending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;

	// Test the size of the tree
	cout << "Target Size: 11" << endl;
	cout << "Actual Size: " << tree->size() << endl;

	cout << "\n\n\n";
	cout << "------------- TESTING EMPTYING -------------" << endl;

	// Try emptying the tree
	cout << "Removing all nodes.." << endl;
	tree->EmptyTree();

	// Print the tree in ascending order
	cout << "Re-ordered tree (ascending): ";
	v = tree->GetAllAscending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;

	// Test the size of the tree
	cout << "Target Size: 0" << endl;
	cout << "Actual Size: " << tree->size() << endl;

	// Try to re-add to an emptied list
	cout << "Attempting to re-add set (a) strings.." << endl;

	for (int i = 0; i < 4; i++) {
		n = new Node(a[i]);
		tree->insert(n);
	}

	// Print the values of the tree in ascending and descending order
	cout << "Ascending: ";
	v = tree->GetAllAscending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << "\nDescending: ";
	v = tree->GetAllDescending();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}

	cout << "\n\n";
}
