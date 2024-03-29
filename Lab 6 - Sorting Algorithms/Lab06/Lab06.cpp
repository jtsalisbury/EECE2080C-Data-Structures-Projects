// Lab06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "SortingAlgorithms.h"
#include <chrono>
#include <algorithm>
#include <thread>

using namespace std;
typedef std::chrono::high_resolution_clock Clock;

SortHandler* s;
thread* th;

bool finished = false;

// This is a helper function for the thread we will run the sorting in.
void doSortTask(int *arr, const int len, int method) {
	if (method == 0) {
		s->bubbleSort(arr, len);
	}
	else if (method == 1) {
		s->insertionSort(arr, len);
	}
	else if (method == 2) {
		s->quickSort(arr, 0, len - 1);
	}
	else if (method == 3) {
		s->mergeSort(arr, 0, len - 1);
	}
	else if (method == 4) {
		s->radixSort(arr, 0, len);
	}

	finished = true;
}

int main()
{
	// We will use one array, and only sort the first n entries, where n is the array size.
	int arr[25000];

	s = new SortHandler();

	auto t1 = Clock::now();
	auto averageTime = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count();

	int arrSizes[5] = { 10, 100, 500, 5000, 25000 };
	int len;

	// Loop through every sorting algorithm
	for (int s = 0; s < 5; s++) {

		cout << "\n\n------Algorithm: " << (s + 1) << "------";

		// Loop through each array size
		for (int a = 0; a < 5; a++) {

			averageTime = 0;

			cout << endl << endl << "Running Averages on array " << (a + 1) << endl;

			len = arrSizes[a];
			averageTime = 0;

			// Refill array with random values up to 2a
			for (int k = 0; k < len; k++) {
				arr[k] = rand() % (2 * len + 1);
			}

			// This is used to detect > 5 minute run times
			auto passedTime = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - Clock::now()).count();

			cout << "Iteration: ";
			
			// Run the sorting algorithm 10 times, computing the average
			for (int i = 0; i < 10; i++) {

				finished = false;

				cout << " " << i + 1;
				random_shuffle(begin(arr), begin(arr) + len);

				// Grab the current time and create a new thread to run the sorting.
				t1 = Clock::now();
				th = new thread(doSortTask, arr, len, s);
				
				// While the thread is alive, we haven't finished sorting, and we haven't passed 5 minutes
				while (th->joinable() && passedTime <= 300 && !finished) {

					passedTime = std::chrono::duration_cast<std::chrono::seconds>(Clock::now() - t1).count();
				}

				// If the thead is alive and we haven't finished, this means we have gone over 5 minutes. Kill the thread
				if (th->joinable() && !finished) {
					cout << "Iteration: " << i << " went over 5 minutes, aborting rest for this array size" << endl;

					delete th;

					break;
				}

				// Add to the average passed time for this array size
				averageTime += std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count();

			}

			cout << endl << "Average time: " << (averageTime / 10);
		}
	}
}