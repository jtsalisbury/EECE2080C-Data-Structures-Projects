// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HEAP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HEAP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HEAP_EXPORTS
#define HEAP_API __declspec(dllexport)
#else
#define HEAP_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>
#include <string>

// This class is exported from the dll
class HEAP_API CHeap {
private:
	std::vector<int> m_heap;
	
	void bubbleUp(int i);
	void bubbleDown(int i);

public:
	CHeap();

	int getSize();
	std::string getString();

	void insert(int num);
	void remove();
	void PrintHeap();
};
