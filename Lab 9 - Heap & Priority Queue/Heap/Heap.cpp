// Heap.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Heap.h"

CHeap::CHeap() { }

// Insert a new item into the heap
void CHeap::insert(int num) {
	m_heap.push_back(num);

	bubbleUp(m_heap.size() - 1);
}

// Remove the max value of the heap
void CHeap::remove() {
	int len = m_heap.size();

	if (len == 0) {
		return;
	}

	// Set the last value as the first then bubble it down
	m_heap[0] = m_heap[len - 1];

	m_heap.pop_back();

	bubbleDown(0);
}

// Print the heap
void CHeap::PrintHeap() {
	std::cout << getString();
}

// Return the number of nodes in the heap
int CHeap::getSize() {
	return m_heap.size();
}

// Start at an index, test the parent against the item and see if we need to move it up
void CHeap::bubbleUp(int i) {
	if (i == 0) {
		return;
	}

	int parent = (i - 1) / 2;
	
	// Parent < Child, move child up and continue testing at the new index
	if (m_heap[parent] < m_heap[i]) {
		int t = m_heap[parent];

		m_heap[parent] = m_heap[i];
		m_heap[i] = t;

		bubbleUp(parent);
	}
}

// Start at an index and test the children. See if any are larger; if so trickle the item down.
void CHeap::bubbleDown(int i) {
	int len = m_heap.size();
	int leftIndex = i * 2 + 1;
	int rightIndex = i * 2 + 2;

	int trickleIndex = i;

	if (i >= len) {
		return;
	}

	// Move down on the left child
	if (leftIndex < m_heap.size() && m_heap[leftIndex] >= m_heap[i]) {
		trickleIndex = leftIndex;
	}

	// Move down on the right child
	if (rightIndex < m_heap.size() && m_heap[rightIndex] >= m_heap[i]) {
		trickleIndex = rightIndex;
	}

	// Children are not greater than the parent
	if (trickleIndex == i) {
		return;
	}

	// Swap them
	int t = m_heap[trickleIndex];
	m_heap[trickleIndex] = m_heap[i];
	m_heap[i] = t;

	bubbleDown(i);
}

// Return a string of the heap
std::string CHeap::getString() {
	std::string s;

	for (int i = 0; i < m_heap.size(); i++) {
		s += std::to_string(m_heap[i]) + " ";
	}

	return s.substr(0, s.length() - 1);
}