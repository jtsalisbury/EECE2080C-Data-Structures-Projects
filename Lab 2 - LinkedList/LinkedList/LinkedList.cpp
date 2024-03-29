// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "LinkedList.h"
#include <iostream>

Node::Node(): m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
}

PointerBasedLinkedList::PointerBasedLinkedList()
{

	// Create the head node and initialize the counter
	m_head = new Node();

	m_count = 0;
}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	return m_count == 0;
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	Node* newNode = new Node(val, nullptr);

	// Insert a new node at the beginning of the list, right after the head node
	newNode->setNext(m_head->getNext());
	m_head->setNext(newNode);

	m_count++;

	return true;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	if (this->isEmpty()) {
		return false;
	}

	Node* curNode = m_head;
	Node* previousNode = m_head;

	// While the node we are looking at is not a nullptr (ie, we are still a valid node)
	while (curNode != nullptr) {

		if (curNode->getItem() == val) {

			// Update the node before this one to point to the one after this one
			previousNode->setNext(curNode->getNext());
			
			m_count--;
	
			// Delete it! Must update the node next to nullptr to prevent undefined behavior
			curNode->setNext(nullptr);
			delete curNode;

			return true;
		}

		// Iterate to the next node
		previousNode = curNode;
		curNode = curNode->getNext();
	}

	return false;
}
/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	if (this->isEmpty()) {
		return;
	}

	// We start at the first node which isn't the head. This way, in case we call add after this we won't have an error.
	Node* curNode = m_head->getNext();
	Node* nextNode = nullptr;

	while (curNode != nullptr) {
		nextNode = curNode->getNext();

		// Delete it!
		curNode->setNext(nullptr);
		delete(curNode);
		curNode = nullptr;

		curNode = nextNode;
	}

	// Update the head node to a null pointer
	m_head->setNext(nullptr);

	m_count = 0;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	// Here we should clear the list and delete the head node.
	this->clear();

	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	if (this->isEmpty()) {
		return "";
	}

	Node* curNode = m_head->getNext();
	std::string curString = "";

	// Let's start pulling the items into a string. Since we insert values at the beginning, 
	//     the string will actually be the reverse if we were to just iterate through every item and concatenate it to a string.
	//     To counter this, just put the item before the previously concatenated string.
	while (curNode != nullptr) {
		curString = std::to_string(curNode->getItem()) + " " + curString;

		curNode = curNode->getNext();
	}

	// Return the string minus the last character
	return curString.substr(0, curString.length() - 1);
}

ArrayBasedLinkedList::ArrayBasedLinkedList()
{
	m_count = 0;
}

bool ArrayBasedLinkedList::isEmpty() const
{
	return m_count == 0;
}
bool ArrayBasedLinkedList::add(int val)
{
	if (m_count == 10) {
		return false;
	}
	
	// Since we keep track of the count, we can simply insert the new value at the next position (0 indexed array, 1 indexed m_count)
	m_values[m_count] = val;

	m_count++;

	return true;
}
bool ArrayBasedLinkedList::remove(int val)
{
	for (int i = 0; i < m_count; i++) {
		if (m_values[i] == val) {

			//Shift all the values down, this will allow us to easily insert new values without having to find an empty space (which would be wrong if you called to_string)
			for (int j = i; j < m_count; j++) {

				if (j == m_count - 1) {
					m_values[j] = NULL; // last node
				}
				else {
					m_values[j] = m_values[j + 1]; // update current = next
				}
			}

			m_count--;

			return true;
		}
	}

	return false;
}
void ArrayBasedLinkedList::clear()
{
	for (int i = 0; i < m_count; i++) {
		m_values[i] = NULL;
	}

	m_count = 0;
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{
	this->clear();
}

std::string ArrayBasedLinkedList::toString() const
{
	std::string curString = "";

	for (int i = 0; i < 10; i++) {
		if (m_values[i] == NULL) {
			continue;
		}

		curString = curString + " " + std::to_string(m_values[i]);
	}

	return curString.substr(1, curString.length()); // Return a string without the beginning space (due to how we traverse the list)
}
