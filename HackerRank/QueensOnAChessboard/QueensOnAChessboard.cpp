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
	for(int column=0;column<Column;++column)
	{
		if(Chessboard[Row][column]==1)
		{
			return false;
		}
	}

	for(int row=Row, column=Column;row>=0 && column>=0;--row, --column)
	{
		if(Chessboard[row][column]==1)
		{
			return false;
		}
	}

	for(int row=Row, column=Column;row<N && column>=0;++row, --column)
	{
		if(Chessboard[row][column]==1)
		{
			return false;
		}
	}

	return true;
}

bool solutionHelper(vector<vector<int>> Chessboard, int Column, int NumberOfPlacedQueens, size_t N)
{
	if(Column >= N)
	{
		cout << "Successfully placed " << NumberOfPlacedQueens << " queens" << endl;

		cout << endl;

		for(const auto & row : Chessboard)
		{
			for(const auto & number : row)
			{
				cout << number << " ";
			}

			cout << endl;
		}

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

void solution(vector<vector<int>> Chessboard, size_t N)
{
	int numberOfPlacedQueens{};

	if(N <= 0)
	{
		cout << "No solution" << endl;

		return;
	}
	else
	{
		solutionHelper(Chessboard, 0, numberOfPlacedQueens, N);
	}	
}

int main(int argc, char**argv)
{
	int n=4;

	auto chessboard=createChessboard(n);

	solution(chessboard, n);
}