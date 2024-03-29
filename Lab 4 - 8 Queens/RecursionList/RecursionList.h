// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RECURSIONLIST_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RECURSIONLIST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RECURSIONLIST_EXPORTS
#define RECURSIONLIST_API __declspec(dllexport)
#else
#define RECURSIONLIST_API __declspec(dllimport)
#endif
#include <vector>

class  RECURSIONLIST_API IFactorialComputer
{
public:
	IFactorialComputer() { };
	virtual int CalculateFactorial(int numberToComputer) =0;
};


class  RECURSIONLIST_API FactorialByLoop : public IFactorialComputer
{
public:
	FactorialByLoop();
	int CalculateFactorial(int num);
};

class  RECURSIONLIST_API FactorialByRecursion : public IFactorialComputer
{
public:
	FactorialByRecursion();
	int CalculateFactorial(int num);
};

class  RECURSIONLIST_API FactorialByStack : public IFactorialComputer
{
public:
	FactorialByStack();
	int CalculateFactorial(int num);
};

class RECURSIONLIST_API MyException : public std::exception
{
public:
	virtual char const* what() const throw();
};

extern RECURSIONLIST_API void SimpleExceptionMethod(int i);


// This class is exported from the RecursionList.dll
class RECURSIONLIST_API ChessBoard {
public:
	ChessBoard() 
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				m_board[i][j] = 0;
			}
		}
	}

	ChessBoard(int board[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				m_board[i][j] = board[i][j];
			}
		}
	}

	std::string ToString();
	void Solve();

	

private:
	bool CheckQueenSafe(int row, int col);
	bool PlaceQueens(int row, int col);

	int m_board[8][8]; //zero is free, while 1 is a placed queen
};


