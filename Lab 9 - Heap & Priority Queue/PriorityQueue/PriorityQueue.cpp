// PriorityQueue.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PriorityQueue.h"
#include <iostream>

CPriorityQueue::CPriorityQueue() { 
	m_size = 0;
}

void CPriorityQueue::insert(int num) {
	m_queue.push_back(num);
	
	// Resort the queue in ascending order
	std::sort(m_queue.begin(), m_queue.end());
}

// Return the size of the queue
int CPriorityQueue::getSize() {
	return m_queue.size();
}

// Remove the last value in the queue
void CPriorityQueue::remove() {
	if (m_queue.size() == 0) {
		return;
	}

	m_queue.erase(m_queue.end() - 1);
}

// Print the queue 
void CPriorityQueue::PrintQueue() {
	std::cout << getString();
}

// Return a string of the queue
std::string CPriorityQueue::getString() {
	std::string s = "";

	// Traverse backwards
	for (int i = m_queue.size() - 1; i >= 0; i--) {
		s += std::to_string(m_queue[i]) + " ";
	}

	return s.substr(0, s.length() - 1);
}