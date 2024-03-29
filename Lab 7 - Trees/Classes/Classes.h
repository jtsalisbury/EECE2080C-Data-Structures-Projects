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

	std::string m_val;
	int m_count;

public:
	Node();
	Node(std::string s);
	~Node();

	Node* getLeft();
	Node* getRight();

	std::string getValue();
	int getCount();

	void setLeft(Node* n);
	void setRight(Node* n);
	void setCount(int c);
};

class CLASSES_API Tree {
private:
	Node* m_head;
	int m_size;

	void EmptyTree(Node* c);

	Node* find(std::string s, Node*& parent);
	Node* getMinFromTree(Node* subtree);

public:
	Tree();
	~Tree();
	
	int size();

	void inorder(std::vector<std::string>*, Node* c);
	void EmptyTree();
	void insert(Node* n);

	std::vector<std::string> GetAllAscending();
	std::vector<std::string> GetAllDescending();
	
	Node* Remove(std::string s);
	Node* find(std::string s);
};
