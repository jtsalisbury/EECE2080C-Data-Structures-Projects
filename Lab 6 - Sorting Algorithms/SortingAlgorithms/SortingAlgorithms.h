// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SORTINGALGORITHMS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SORTINGALGORITHMS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SORTINGALGORITHMS_EXPORTS
#define SORTINGALGORITHMS_API __declspec(dllexport)
#else
#define SORTINGALGORITHMS_API __declspec(dllimport)
#endif

#include <vector>

// Implementations of all sorting algorithms will modify the existing array
class SORTINGALGORITHMS_API SortHandler {

public:
	void bubbleSort(int *arr, const int len);
	void insertionSort(int *arr, const int len);

	void merge(int *arr, int first, int mid, int last);
	void mergeSort(int *arr, int first, int last);

	int partition(int *arr, int first, int last);
	void quickSort(int *arr, int first, int last);

	int arrMax(int *arr, int first, int last);
	void radixSort(int *arr, int first, int last);
};