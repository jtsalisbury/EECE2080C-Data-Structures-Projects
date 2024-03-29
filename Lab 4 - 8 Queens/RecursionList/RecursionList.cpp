// RecursionList.cpp : Defines the exported functions for the DLL application.
//

#include <stack>
#include "header.h"
#include "RecursionList.h"
#include "string"
#include <iostream>

char const* MyException::what() const throw() {
	return "My exception!";
}

extern void SimpleExceptionMethod(int i) {
	MyException ex;

	if (i == 1)
		throw ex;
	if (i == -1)
		throw ex;
}

// Compute the factorial by a for loop
FactorialByLoop::FactorialByLoop() { }
int FactorialByLoop::CalculateFactorial(int num) {
	int res = 1;

	for (int i = 1; i <= num; i++) {
		res *= i;
	}

	return res;
}

// Compute the factorial by recursion
FactorialByRecursion::FactorialByRecursion() { }
int FactorialByRecursion::CalculateFactorial(int num) {
	if (num == 0) {
		return 1;
	}

	return num * CalculateFactorial(num - 1);
}

// Compute the factorial by stacks
FactorialByStack::FactorialByStack() { }
int FactorialByStack::CalculateFactorial(int num) {
	std::stack<int> numstor;
	int res = 1;

	for (int i = 1; i <= num; i++) {
		numstor.push(i);
	}

	while (!numstor.empty()) {
		res *= numstor.top();

		numstor.pop();
	}

	return res;
}


// Implementation of the ChessBoard class
void ChessBoard::Solve() {
	PlaceQueens(1, 1);
}

// Check to ensure this is a valid place. We only need to check on the left of the position.
bool ChessBoard::CheckQueenSafe(int row, int col) {
	
	// Check left of this row
	int i, j;
	for (i = 0; i < col; i++) {
		if (m_board[row - 1][i] == 1) {
			return false;
		}
	}
	
	// Top left diagonal
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (m_board[i][j] == 1) {
			return false;
		}
	}

	// Bottom left diagonal
	for (i = row - 1, j = col - 1; j >= 0 && i < 8; i++, j--) {
		if (m_board[i][j] == 1) {
			return false;
		}
	}

	return true;
}

bool ChessBoard::PlaceQueens(int row, int col) {
	// Start from the top left and move to the bottom right.

	if (col > 8) {
		return true;
	}

	// Try each row in the column, incrementing through.
	// If we can't find a solution get rid of the new queen and go to the next row. 
	// Otherwise, return true as we found a solution.
	for (int i = 0; i < 8; i++) {
		if (CheckQueenSafe(i + 1, col)) {
			m_board[i][col - 1] = 1;

			if (!PlaceQueens(i + 1, col + 1)) {
				m_board[i][col - 1] = 0;
			} else {
				return true;
			}
		}
	}

	return false;
}

std::string ChessBoard::ToString() {
	std::string str = "";

	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			str += " " + std::to_string(m_board[r][c]);
		}

		str += "\n";
	}

	return str;
}