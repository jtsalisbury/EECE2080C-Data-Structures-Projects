// Classes.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Classes.h"

CNode::CNode() {

}

CNode::CNode(std::string key, int data) {
	m_key = key;
	m_data = data;
}

std::string CNode::getKey() {
	return m_key;
}

int CNode::getData() {
	return m_data;
}

void CNode::setKey(std::string key) {
	m_key = key;
}

bool CNode::operator ==(CNode* target) {
	return m_data == target->getData() && m_key == target->getKey();
}

CHash::CHash() {
	m_size = 100;
}

CHash::CHash(int maxSize) {
	m_maxsize = maxSize;

	m_stor = std::vector<CNode*>(maxSize, 0);
}

bool CHash::addItem(CNode* n) {

	if (m_size == m_maxsize) {
		return false;
	}

	int i = hash(n->getKey());

	int start = i;
	int stop = m_maxsize;

	while (m_stor[i] != nullptr) {
		if (i + 1 == m_maxsize) {
			i = -1;
			stop = start;
		}
		else if (i + 1 == start) {
			return false;
		}

		i++;
	}

	m_stor[i] = n;

	m_size++;

	return true;
}

CNode* CHash::removeItem(std::string key) {

	if (m_size == 0) {
		return nullptr;
	}

	int i = hash(key);
	int start = i;
	int stop = m_maxsize;

	while (m_stor[i] != nullptr && m_stor[i]->getKey() != key) {
		if (i + 1 == m_maxsize) {
			i = -1;
			stop = start;
		}
		else if (i + 1 == start) {
			return nullptr;
		}

		i++;
	}

	m_size--;

	CNode* temp = m_stor[i];
	m_stor[i] = nullptr;

	return temp;
}

CNode* CHash::getItem(std::string key) {

	if (m_size == 0) {
		return nullptr;
	}

	int i = hash(key);
	int start = i;
	int stop = m_maxsize;

	while (m_stor[i] != nullptr && m_stor[i]->getKey() != key) {
		if (i + 1 == m_maxsize) {
			i = -1;
			stop = start;
		}
		else if (i + 1 == start) {
			return nullptr;
		}

		i++;
	}
	return m_stor[i];
}

int CHash::getLength() {
	return m_size;
}

int CHash::hash(std::string key) {
	int sum = 0;

	for (int i = 0; i < key.length(); i++){
		sum += (int)key[i];
	}

	return sum % m_maxsize; 
}

void CHash::printTable() {
	for (int i = 0; i < m_maxsize; i++) {
		if (m_stor[i] != nullptr) {
			std::cout << i << ": (" << m_stor[i]->getKey() << ", " << m_stor[i]->getData() << "), ";
		}
	}
}

CHash::~CHash() {

	for (int i = 0; i < m_maxsize; i++) {
		if (m_stor[i] != nullptr) {
			delete m_stor[i];
			m_stor[i] = nullptr;
		}
	}

}