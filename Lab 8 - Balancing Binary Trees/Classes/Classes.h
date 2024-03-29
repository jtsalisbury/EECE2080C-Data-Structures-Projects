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
#include <vector>

// This class is exported from the dll
class CLASSES_API Node {
private:
	Node* m_left = nullptr;
	Node* m_right = nullptr;
	Node* parent = nullptr;

	bool color;

	int m_val;
	int m_count;

public:
	Node();
	Node(int i);
	~Node();

	Node* getLeft();
	Node* getRight();
	Node* getParent();

	bool getColor();

	int getValue();
	int getCount();

	void setLeft(Node* n);
	void setRight(Node* n);
	void setCount(int c);
	void setColor(bool c);
	void setParent(Node* n);
};

class CLASSES_API Tree {
private:
	Node* m_head;
	int m_size;

	void EmptyTree(Node* c);

	Node* find(int i, Node*& parent);

	void printTree(Node* p, int depth);

	void rotateLeft(Node* pivot);
	void rotateRight(Node* pivot);

	void fixViolation(Node* n);

public:
	Tree();
	~Tree();
	
	int size();

	void printTree();

	void inorder(std::vector<int>*, Node* c);
	void EmptyTree();
	void insert(int i);

	std::vector<int> GetAllAscending();
	std::vector<int> GetAllDescending();
	
	Node* Remove(int i);
	Node* find(int i);
};
