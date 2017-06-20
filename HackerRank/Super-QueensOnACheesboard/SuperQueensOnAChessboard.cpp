#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<vector<int>> createChessboard(size_t N)
{
	return vector<vector<int>>(N, vector<int>(N));
}

bool canPlaceQueen(vector<vector<int>> Chessboard, int Row, int Column, size_t N)
{
	//check for other queens in the current row
	for(int column=0;column<Column;++column)
	{
		if(Chessboard[Row][column]==1)
		{
			return false;
		}
	}

	//check for queens in the upper left diagonal
	for(int row=Row, column=Column;row>=0 && column>=0;--row, --column)
	{
		if(Chessboard[row][column]==1)
		{
			return false;
		}
	}

	//check for queens in the lower left diagonal
	for(int row=Row, column=Column;row<N && column>=0;++row, --column)
	{
		if(Chessboard[row][column]==1)
		{
			return false;
		}
	}

	int row=Row;

	int column=Column;

	//check for knights attacks from the upper left
	if(row >= 1 && column >= 2 && Chessboard[row-1][column-2]==1)
	{
		return false;
	}

	if(row >= 2 && column >= 1 && Chessboard[row-2][column-1]==1)
	{
		return false;
	}

	//check for knights attacks from the lower left
	if(row+1 < N && column >= 2 && Chessboard[row+1][column-2]==1)
	{
		return false;
	}

	if(row+2 < N && column >= 1 && Chessboard[row+2][column-1]==1)
	{
		return false;
	}

	return true;
}

bool solutionHelper(vector<vector<int>> Chessboard, int Column, int NumberOfPlacedQueens, size_t N)
{
	if(Column >= N)
	{
		return true;
	}

	for(int row=0;row<N;++row)
	{
		if(canPlaceQueen(Chessboard, row, Column, N))
		{
			Chessboard[row][Column]=1;

			if(solutionHelper(Chessboard, Column+1, NumberOfPlacedQueens+1, N))
			{
				return true;
			}

			Chessboard[row][Column]=0;
		}
	}

	return false;
}

int solution(vector<vector<int>> Chessboard, size_t N)
{
	int numberOfPlacedQueens=1;

	if(N <= 0)
	{
		return 0;
	}

	int ways{};

	int column{};

	for(int row=0;row<N;++row)
	{
		Chessboard[row][column]=1;

		if(solutionHelper(Chessboard, column+1, numberOfPlacedQueens, N))
		{
			++ways;
		}

		Chessboard[row][column]=0;
	}

	return ways;
}