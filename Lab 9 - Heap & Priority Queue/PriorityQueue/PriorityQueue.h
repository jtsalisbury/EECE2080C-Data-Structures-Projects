// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PRIORITYQUEUE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PRIORITYQUEUE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PRIORITYQUEUE_EXPORTS
#define PRIORITYQUEUE_API __declspec(dllexport)
#else
#define PRIORITYQUEUE_API __declspec(dllimport)
#endif

#include <vector>
#include <string>
#include <algorithm>


// This class is exported from the dll
class PRIORITYQUEUE_API CPriorityQueue {
private:
	std::vector<int> m_queue;
	int m_size;

public:
	CPriorityQueue();

	int getSize();
	std::string getString();

	void insert(int num);
	void remove();
	void PrintQueue();
};
