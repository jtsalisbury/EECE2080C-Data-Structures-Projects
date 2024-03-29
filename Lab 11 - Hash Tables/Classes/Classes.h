// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CLASSES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CLASSES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CLASSES_EXPORTS
#define CLASSES_API __declspec(dllexport)
#else
#define CLASSES_API __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <vector>

// This class is exported from the dll
class CLASSES_API CNode {
	std::string m_key;
	int m_data;

public:
	CNode();
	CNode(std::string key, int data);

	std::string getKey();
	int getData();

	void setKey(std::string key);

	bool operator ==(CNode* target);
};

class CLASSES_API CHash{
private:
	int m_size = 0;
	int m_maxsize;

	std::vector<CNode*> m_stor;

public:
	CHash();
	CHash(int maxSize);

	int hash(std::string key);

	bool addItem(CNode* n);
	CNode* removeItem(std::string key);
	CNode* getItem(std::string key);
	int getLength();
	void printTable();
	~CHash();
};
