// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "StackQueues.h"
#include <iostream>

/*
	Array Based Stack Implementation
*/
ArrayBasedStack::ArrayBasedStack() 
{
	m_count = 0;
}

ArrayBasedStack::~ArrayBasedStack() 
{
	m_count = NULL;
}

// Returns whether the stack is empty
bool ArrayBasedStack::isEmpty() const 
{
	return m_count == 0;
}

// Push a new value to the stack or throw an exception if it is full
bool ArrayBasedStack::push(int val) {
	if (m_count == STACK_SIZE)
	{
		std::cout << "Stack is full!" << std::endl;

		return false;
	} 
	else
	{
		m_stack[m_count] = val;

		m_count++;
	
		return true;
	}
}

// Remove the latest value from the stack. Throw an exception if the stack is empty.
bool ArrayBasedStack::pop() {
	if (this->isEmpty())
	{
		std::cout << "Stack is empty!" << std::endl;

		return false;
	}
	else
	{		
		m_count--;

		return true;
	}
}

// Return the latest value from the stack or throw an exception if it is empty.
int ArrayBasedStack::peek()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";

		return -1;
	}
	else
	{
		return m_stack[m_count - 1]; // 0 indexed
	}
}

std::string ArrayBasedStack::toString() 
{
	if (this->isEmpty()) 
	{
		return "";
	}

	std::string str = "";

	for (int i = m_count - 1; i >= 0; i--) {
		str = str + " " + std::to_string(m_stack[i]);
	}

	return str.substr(1, str.length());
}

// Return the number of elements in the stack
int ArrayBasedStack::length()
{
	return m_count;
}

// Pop all the items from the stack
void ArrayBasedStack::empty()
{
	while (m_count > 0) {
		this->pop();
	}
}


/*
	Array Based Queue Implementation (Circular design)
*/
ArrayBasedQueue::ArrayBasedQueue()
{
	m_count = 0;
	m_head = 0;
	m_tail = -1;
}

ArrayBasedQueue::~ArrayBasedQueue()
{
	m_count = NULL;
	m_head = NULL;
	m_tail = NULL;
}

bool ArrayBasedQueue::isEmpty() const 
{
	return m_count == 0;
}

// Add an element to the queue at the tail
// We will enQueue at the tail, and deQueue at the head
bool ArrayBasedQueue::enQueue(std::string val)
{
	if (m_count + 1 == QUEUE_SIZE) 
	{
		std::cout << "Queue is full!" << std::endl;

		return false;
	}
	else
	{
		// If we are at the last element, set the tail to 0, else set the tail to the current + 1
		if (m_tail + 1 == QUEUE_SIZE)
		{
			m_tail = 0;
		}
		else
		{
			m_tail++;
		}

		// Add the value to the queue
		m_queue[m_tail] = val;

		m_count++;

		return true;
	}
}

// Remove the first element from the queue (at the head)
bool ArrayBasedQueue::deQueue() 
{
	if (this->isEmpty()) 
	{
		std::cout << "Queue is empty!" << std::endl;

		return false;
	}
	else
	{

		// The head is the last index of the queue, move it to the beginning, else add 1 to it.
		if (m_head + 1 == QUEUE_SIZE) 
		{
			m_head = 0;
		}
		else 
		{
			m_head++;
		}

		m_count--;

		return true;
	}
}

// Return the value of the element in the queue at the head
std::string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";

		return "";
	}
	else
	{
		return m_queue[m_head];
	}
}

// Return the number of elements in the queue
int ArrayBasedQueue::length()
{
	return m_count;
}

// Dequeue all elements
void ArrayBasedQueue::empty()
{
	while (m_count > 0) 
	{
		this->deQueue();
	}
}
