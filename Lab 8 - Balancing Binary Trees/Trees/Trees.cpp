#include "pch.h"
#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

int main()
{

	Tree* t = new Tree();
	int option;
	int data;

	while (true) {
		system("cls");
		cout << "---------------------------" << endl;

		cout << "\n-+-Tree Structure-+-\n";
		t->printTree();

		cout << endl << endl;

		cout << "Choose an option:" << endl << "0. Quit" << endl << "1. Add item to tree" << endl << "2. Attempt to remove item from tree" << endl << "Choice: ";

		cin >> option;

		if (option == 0) {
			break;
		}

		while (option != 1 && option != 2) {
			cout << "Invalid option! Try again: ";

			cin >> option;
		}

		if (option == 1) {
			cout << "Enter value to add: ";

			cin >> data;

			t->insert(data);
		}
		else {
			cout << "Enter value to attemp to remove: ";

			cin >> data;

			if (t->find(data) == nullptr) {
				cout << "We can't find this value!\n";
			}
			else {
				//t->Remove(data);
			}
		}
	}
}
