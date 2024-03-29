// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Classes.h"
#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
using namespace std;

// Random string generator modified from: https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random(const int len) {
	std::string s;

	char arr[52] = {
		'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K',
		'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'n', 'o', 'p',
		'q', 'r', 's', 't', 'u',
		'v', 'w', 'x', 'y', 'z'};

	for (int i = 0; i < len; ++i) {
		s += arr[rand() % 52];
	}

	return s;
}

void runTests() {
	int arraySizes[4] = { 500, 1000, 2000, 5000 };
	double hashSizes[4] = { 1, 1.5, 2, 5 };

	auto t1 = Clock::now();
	auto t2 = t1;

	auto sum = t1 - t2;

	for (int i = 0; i < 4; i++) { // array size

		cout << endl << "---------------------- Array Size: " << arraySizes[i] << " ----------------------" << endl;

		for (int j = 0; j < 4; j++) { // hash size modifier

			CHash* hash = new CHash(hashSizes[j] * arraySizes[i]);

			sum = (sum - sum); //idk how to set sum = 0

			for (int k = 0; k < arraySizes[i]; k++) {
				CNode* n = new CNode(gen_random(10), rand() * arraySizes[i]);

				t1 = Clock::now();
				hash->addItem(n);
				t2 = Clock::now();

				sum += t2 - t1;
			}

			cout << "Hash Size %: " << hashSizes[j] * 100 << ", time: " << chrono::duration_cast<std::chrono::nanoseconds>(sum).count() << endl;
		}
	}
}

int main() {
	int option = 1;
	string key;
	int value;

	cout << "1. Create and Test a New Hash\n2. Run Performance Tests\nEnter an option: ";
	cin >> option;

	while (option != 1 && option != 2) {
		cout << "Invalid option! Try again: ";
		cin >> option;
	}

	if (option == 2) {

		runTests();
		
		return 0;
	}

	cout << "Enter the size of the hash: ";
	cin >> option;

	CHash* c = new CHash(option);

	while (option != 0) {
		cout << "\n---------------------------------------\n";
		cout << "0. Quit\n1. Add an Item\n2. Remove an Item\n3. Get Item\n4. Get Length\n5. Print Out";
		cout << "\nEnter an option: ";
		cin >> option;

		while (option < 0 || option > 5) {
			cout << "\nInvalid input entered! Try again: ";
			cin >> option;
		}

		if (option == 1) {
			cout << "Enter the key: ";
			cin >> key;
			cout << "Enter the value: ";
			cin >> value;

			CNode* t = new CNode(key, value);
			bool res = c->addItem(t);

			if (res) {
				cout << "Successfully added!" << endl;
			}
			else {
				cout << "Failed to add item!" << endl;
			}
		}
		else if (option == 2) {
			cout << "Enter the key: ";
			cin >> key;

			CNode* t = c->removeItem(key);

			if (t == nullptr) {
				cout << "Couldn't find item!" << endl;
			}
			else {
				cout << "Found item! (" << t->getKey() << ", " << t->getData() << ")" << endl;
			}
		}
		else if (option == 3) {
			cout << "Enter the key: ";
			cin >> key;

			CNode* t = c->getItem(key);

			if (t == nullptr) {
				cout << "Couldn't find item!" << endl;
			}
			else {
				cout << "Found item! (" << t->getKey() << ", " << t->getData() << ")" << endl;
			}
		}
		else if (option == 4) {
			cout << "Length of hash table: " << c->getLength() << endl;
		}
		else if (option == 5) {
			c->printTable();
		}
	}

	return 0;
}
