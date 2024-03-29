// Classes.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Classes.h"

#include <iostream>

// Node constructor
Node::Node() {
	m_count = 0;
}

// Node constructor
Node::Node(std::string s) {
	m_val = s;
	m_count = 0;
}

// Node destructor
Node::~Node() {
	m_left = nullptr;
	m_right = nullptr;
}

// Returns the node to the left of the current
Node* Node::getLeft() {
	return m_left;
}

// Returns the node to the right of the current
Node* Node::getRight() {
	return m_right;
}

// Return the value of the node
std::string Node::getValue() {
	return m_val;
}

// Return the count of repetitive nodes with that value
int Node::getCount() {
	return m_count;
}

void Node::setLeft(Node* n) {
	m_left = n;
}

void Node::setRight(Node* n) {
	m_right = n;
}

void Node::setCount(int c) {
	m_count = c;
}

Tree::Tree() {
	m_size = 0;
}

Tree::~Tree() {
	EmptyTree();

	delete m_head;
}

// Public insert method
void Tree::insert(Node* n) {

	// Update the head node if the size is 0
	if (m_size == 0) {
		
		m_head = n;
		m_size++;

		return;
	}

	Node* curNode = m_head;
	std::string targetString = n->getValue();

	bool greaterThan;
	while (curNode != nullptr) {
		greaterThan = targetString > curNode->getValue();

		if (curNode->getValue() == targetString) {
			curNode->setCount(curNode->getCount() + 1);

			break;
		}

		if (curNode->getLeft() == nullptr && !greaterThan) {
			curNode->setLeft(n);

			break;
		}
		else if (curNode->getRight() == nullptr && greaterThan) {
			curNode->setRight(n);

			break;
		}

		if (greaterThan) {
			curNode = curNode->getRight();
		}
		else {
			curNode = curNode->getLeft();
		}
	}
	
	//insert(n, m_head);

	m_size++;
}

// Private helper find method.
// Takes the string, current node, and a reference to a pointer for the parent.
Node* Tree::find(std::string s, Node*& parent) {
	Node* cur = m_head;

	while (cur != nullptr) {

		if (cur->getValue() == s) {
			return cur;
		}

		parent = cur;

		if (s < cur->getValue()) {
			cur = cur->getLeft();
		}
		else {
			cur = cur->getRight();
		}
	}

	return nullptr;
}

// Public find method
Node* Tree::find(std::string s) {
	if (size() == 0) {
		return nullptr;
	}

	Node* parent = nullptr;

	return find(s, parent);
}

int Tree::size() {
	return m_size;
}

// Private method to start recursively removing nodes from a tree
void Tree::EmptyTree(Node* c) {
	if (c->getLeft() != nullptr) {
		EmptyTree(c->getLeft());
	}
	
	if (c->getRight() != nullptr) {
		EmptyTree(c->getRight());
	}

	c->setLeft(nullptr);
	c->setRight(nullptr);

	m_size--;

	delete c;
}

// Public method to empty the tree
void Tree::EmptyTree() {
	if (m_size == 0) {
		return;
	}

	EmptyTree(m_head);
}

// Recursively push values of the tree to a vector. 
void Tree::inorder(std::vector<std::string>* v, Node* c) {
	
	if (c == nullptr) {
		return;
	}

	// Recursively do the left
	inorder(v, c->getLeft());

	// Then the current
	v->push_back(c->getValue());

	// Then recursively do the right
	inorder(v, c->getRight());
}

// Gets the tree's values in ascending order
std::vector<std::string> Tree::GetAllAscending() {

	std::vector<std::string> v;

	if (m_size == 0) {
		return v;
	}

	inorder(&v, m_head);

	return v;
}

// Gets the tree's values in deschending order.
std::vector<std::string> Tree::GetAllDescending() {

	std::vector<std::string> v;

	if (m_size == 0) {
		return v;
	}

	inorder(&v, m_head);

	std::reverse(v.begin(), v.end());

	return v;
}



Node* Tree::getMinFromTree(Node* subtree) {

	if (subtree->getLeft() == nullptr) {
		return subtree;
	}

	return getMinFromTree(subtree->getLeft());
}

// Remove a node
// Will replace all child nodes of the removed node.
Node* Tree::Remove(std::string s) {
	if (size() == 0) {
		return nullptr;
	}
	
	Node p;
	Node* parent = &p;
	Node* target = find(s, parent);

	if (target == nullptr) {
		return nullptr;
	}

	// both children
	if (target->getLeft() != nullptr && target->getRight() != nullptr) {
		Node* min = getMinFromTree(target);

		if (parent->getLeft() == target) {
			parent->setLeft(min);
		}
		else {
			parent->setRight(min);
		}
	}
	else if (target->getLeft() != nullptr) { //left child only
		if (parent->getLeft() == target) {
			parent->setLeft(target->getLeft());
		}
		else {
			parent->setRight(target->getRight());
		}
	}
	else if (target->getRight() != nullptr) { // right children only
		if (parent->getLeft() == target) {
			parent->setLeft(target->getLeft());
		}
		else {
			parent->setRight(target->getRight());
		}
	}

	m_size--;

	target->setLeft(nullptr);
	target->setRight(nullptr);

	return target;
}