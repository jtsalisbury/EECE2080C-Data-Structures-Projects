// Lab09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include "Heap.h"
#include "PriorityQueue.h"
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

void printDif(int t1, int t2) {

}

int main()
{
	CPriorityQueue * q = new CPriorityQueue();
	CHeap* h = new CHeap();

	int array[5000];
	int arraysizes[4] = { 500, 1000, 2000, 5000 };
	int length;

	for (int i = 0; i < 5000; i++) {
		array[i] = rand() % 5000;
	}

	auto t1 = Clock::now();
	auto t2 = t1;

	for (int i = 0; i < 2; i++) //iterate through heap and queue
	{ 
		for (int j = 0; j < 4; j++) //number of arrays
		{
			int length = arraysizes[j];

			for (int k = 0; k < length; k++)
			{
				array[k] = rand() % (length * 2);
			}

			cout << endl;
			// Priority Queue
			if (i == 0) {

				// Insertion of n elements on priority queue
				t1 = Clock::now();
				for (int i = 0; i < length; i++) {
					q->insert(i);
				}
				t2 = Clock::now();
				cout << "Priority Queue insertion of size " << length << ": " << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
			
				// Removal of n elements on priority queue
				t1 = Clock::now();
				for (int i = 0; i < length; i++) {
					q->remove();
				}
				t2 = Clock::now();
				cout << "Priority Queue removal of size " << length << ": " << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
			}

			// Heap
			if (i == 1) {

				// Insertion of n elements on heap
				t1 = Clock::now();
				for (int i = 0; i < length; i++) {
					h->insert(i);
				}
				t2 = Clock::now();
				cout << "Heap insertion of size " << length << ": " << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
			
				// Removal of n elements on heap
				t1 = Clock::now();
				for (int i = 0; i < length; i++) {
					h->remove();
				}
				t2 = Clock::now();
				cout << "Heap removal of size " << length << ": " << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
			}
		}
	}
}