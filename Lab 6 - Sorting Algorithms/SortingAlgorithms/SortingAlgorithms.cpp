// SortingAlgorithms.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SortingAlgorithms.h"

#include <iostream>
#include <chrono>

// Implementation of bubble sort of an array
void SortHandler::bubbleSort(int *arr, const int len) {
	bool switched = true;
	int i, t;

	while (switched) {
		switched = false;

		for (i = 0; i < len - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				switched = true;

				t = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = t;
			}
		}
	}
}

// Implementation of insertion sort of an array
void SortHandler::insertionSort(int *arr, const int len) {
	for (int i = 1; i < len; i++) {
		int next = arr[i];
		int loc = i - 1;

		while (loc >= 0 && arr[loc - 1] > next) {
			arr[loc + 1] = arr[loc];
			loc--;
		}

		arr[loc + 1] = next;
	}
}

// Helper function for merge sort. "Merge" together two parts of an array
void SortHandler::merge(int *arr, int first, int mid, int last) {
	int temp[25000];

	int first1 = first;
	int last1 = mid;

	int first2 = mid + 1;
	int last2 = last;

	int i = first1;
	while ((first1 <= last1) && (first2 <= last2)) {
		if (arr[first1] <= arr[first2]) {
			temp[i] = arr[first1];
			first1++;
		}
		else {
			temp[i] = arr[first2];
			first2++;
		}
		i++;
	}

	while (first1 <= last1) {
		temp[i] = arr[first1];
		first1++;
		i++;
	}

	while(first2 <= last2) {
		temp[i] = arr[first2];
		first2++;
		i++;
	}

	for (i = first; i <= last; i++) {
		arr[i] = temp[i];
	}
}

// Implementation of merge sort of an array
void SortHandler::mergeSort(int *arr, int first, int last) {
	if (first < last) {

		int mid = first + (last - first) / 2;

		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		
		merge(arr, first, mid, last);
	}
}

// Helper function for quick sort
int SortHandler::partition(int *arr, int first, int last) {
	int pi = arr[last];
	int i = (first - 1);
	int t;

	for (int j = first; j <= last - 1; j++) {
		if (arr[j] <= pi) {
			i++;

			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	t = arr[i + 1];
	arr[i + 1] = arr[last];
	arr[last] = t;
	return (i + 1);
}

// Implementation of quick sort of an array
void SortHandler::quickSort(int *arr, int first, int last) {
	if (first < last) {
		int pivot = partition(arr, first, last);

		quickSort(arr, first, pivot - 1);
		quickSort(arr, pivot + 1, last);
	}
}

// Helper function to grab the maximum value in a range of an array
int SortHandler::arrMax(int *arr, int first, int last) {
	int runningMax = arr[first];

	for (int i = first + 1; i < last; i++) {
		if (arr[i] > runningMax) {
			runningMax = arr[i];
		}
	}

	return runningMax;
}

// Implementation of radix sort using an array
void SortHandler::radixSort(int *arr, int first, int last) {
	int maxVal = arrMax(arr, first, last);

	std::vector<std::vector<int>> buckets(10);
	int i = 1;

	while (maxVal != 0) {
		for (int iter = first; iter != last; iter++) {
			int num = arr[iter];

			int remainder = (num / i) % 10;
			buckets[remainder].push_back(num);
		}

		int iter = first;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < buckets[j].size(); k++) {
				arr[iter] = buckets[j][k];
				iter++;
			}
		}

		for (int j = 0; j < 10; j++) {
			buckets[j].clear();
		}

		maxVal /= 10;
		i *= 10;
	}
}