// Classes.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Classes.h"

#include <iostream>

enum colors
{
	RED,
	BLACK
};

// Node constructor
Node::Node() {
	m_count = 0;
	color = RED;
}

// Node constructor
Node::Node(int s) {
	m_val = s;
	m_count = 0;
	color = RED;
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
int Node::getValue() {
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

void Node::setParent(Node* n) {
	parent = n;
}

Node* Node::getParent() {
	return parent;
}

bool Node::getColor() {
	return color;
}

void Node::setColor(bool c) {
	color = c;
}

Tree::Tree() {
	m_size = 0;
}

Tree::~Tree() {
	EmptyTree();

	delete m_head;
}

// Private helper find method.
// Takes the string, current node, and a reference to a pointer for the parent.
Node* Tree::find(int s, Node*& parent) {
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
Node* Tree::find(int s) {
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
void Tree::inorder(std::vector<int>* v, Node* c) {
	
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
std::vector<int> Tree::GetAllAscending() {

	std::vector<int> v;

	if (m_size == 0) {
		return v;
	}

	inorder(&v, m_head);

	return v;
}

// Gets the tree's values in deschending order.
std::vector<int> Tree::GetAllDescending() {

	std::vector<int> v;

	if (m_size == 0) {
		return v;
	}

	inorder(&v, m_head);

	std::reverse(v.begin(), v.end());

	return v;
}

void Tree::printTree(Node* p, int depth) {

	for (int i = 0; i < depth; i++) {
		std::cout << "-";
	}

	std::cout << p->getValue() << std::endl;

	if (p->getLeft() != nullptr) {
		printTree(p->getLeft(), depth + 1);
	}

	if (p->getRight() != nullptr) {
		printTree(p->getRight(), depth + 1);
	}
}

void Tree::printTree() {
	if (m_size == 0) {
		return;
	}

	printTree(m_head, 0);
}


// Remove a node
// Will replace all child nodes of the removed node.
Node* Tree::Remove(int s) {
	if (size() == 0) {
		return nullptr;
	}
	
	

	return nullptr;
}

void Tree::insert(int i) {

	Node* n = new Node(i);

	// Update the head node if the size is 0
	if (m_size == 0) {

		m_head = n;

		m_size++;

		return;
	}

	Node* curNode = m_head;
	int target = n->getValue();

	bool greaterThan;
	while (curNode != nullptr) {
		greaterThan = target > curNode->getValue();

		if (curNode->getValue() == target) {
			curNode->setCount(curNode->getCount() + 1);
			delete n;

			n = curNode;
			curNode = curNode->getParent();

			break;
		}

		if (curNode->getLeft() == nullptr && !greaterThan) {
			curNode->setLeft(n);
			n->setParent(curNode);

			break;
		}
		else if (curNode->getRight() == nullptr && greaterThan) {
			curNode->setRight(n);
			n->setParent(curNode);

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

	fixViolation(n);

	m_size++;
}


// Code for rotateLeft, rotateRight, fixViolation adapted from following resources
// https://en.wikipedia.org/wiki/Tree_rotation#/media/File:Tree_Rotations.gif
// https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

void Tree::rotateLeft(Node* pivot) {
	Node* temp = pivot->getRight();

	if (temp != nullptr)
		pivot->setRight(temp->getLeft());

	if (temp != nullptr && temp->getLeft() != nullptr) {
		temp->getLeft()->setParent(pivot);
	}

	if (temp != nullptr) {
		temp->setParent(pivot->getParent());
		temp->setLeft(pivot);
	}

	if (pivot->getParent() == nullptr) {
		m_head = temp;
	}
	else if (pivot == pivot->getParent()->getLeft()) {
		pivot->getParent()->setLeft(temp);
	}
	else {
		pivot->getParent()->setRight(temp);
	}

	pivot->setParent(temp);
}

void Tree::rotateRight(Node* pivot) {
	Node* temp = pivot->getLeft();

	if (temp != nullptr)
		pivot->setLeft(temp->getRight());

	if (temp != nullptr && temp->getRight() != nullptr) {
		temp->getRight()->setParent(temp);
	}

	if (temp != nullptr) {
		temp->setParent(pivot->getParent());
		temp->setRight(pivot);
	}

	if (pivot->getParent() == nullptr) {
		m_head = temp;
	}
	else if (pivot == pivot->getParent()->getLeft()) {
		pivot->getParent()->setLeft(temp);
	}
	else {
		pivot->getParent()->setRight(temp);
	}

	pivot->setParent(temp);
}

void Tree::fixViolation(Node* pivot) {
	bool left;
	Node* pivot_uncle = nullptr;
	Node* pivot_gp = nullptr;
	Node* t;

	if (pivot->getParent() != nullptr && pivot->getParent()->getParent() != nullptr) {
		pivot_gp = pivot->getParent()->getParent();

		pivot_uncle = (pivot_gp->getLeft() == pivot->getParent()) ? pivot_gp->getRight() : pivot_gp->getLeft();
	}

	if (pivot->getParent() == nullptr) {
		// Case 1

		pivot->setColor(BLACK);
	}
	else if (pivot->getParent()->getColor() == BLACK) {
		// case 2

		return;
	}
	else if (pivot_uncle != nullptr && pivot_uncle->getColor() == RED) {
		// case 3

		pivot->getParent()->setColor(BLACK);
		pivot_uncle->setColor(BLACK);
		pivot_gp->setColor(RED);

		fixViolation(pivot_gp);
	}
	else {
		// case 4

		if (pivot_gp != nullptr && pivot_gp->getLeft() != nullptr && pivot == pivot_gp->getLeft()->getRight()) {
			rotateLeft(pivot->getParent());
			pivot = pivot->getLeft();
		}
		else if (pivot_gp != nullptr && pivot_gp->getRight() != nullptr && pivot == pivot_gp->getRight()->getLeft()) {
			rotateRight(pivot->getParent());
			pivot = pivot->getRight();
		}

		if (pivot_gp != nullptr && pivot == pivot->getParent()->getLeft()) {
			rotateRight(pivot_gp);
		}
		else {

			if (pivot_gp != nullptr) {
				rotateLeft(pivot_gp);
				pivot_gp->setColor(RED);
			}
			
			pivot->getParent()->setColor(BLACK);
			
		}
	}
}