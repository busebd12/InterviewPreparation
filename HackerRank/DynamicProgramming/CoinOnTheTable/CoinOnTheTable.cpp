#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
using namespace std;

bool stillOnBoard(int Row, int Column, int N, int M)
{
	if((Row >= 0 && Row <= N) && (Column >= 0 && Column <= M))
	{
		return true;
	}

	return false;
}

vector<vector<char>> createBoard()
{
	vector<vector<char>> board;

	ifstream file;

	file.open("./TestCase.txt");

	string line;

	while(getline(file, line))
	{
		vector<char> row;

		for(int index=0;index<line.size();++index)
		{
			row.emplace_back(line[index]);
		}

		board.emplace_back(row);
	}

	for(const auto & row : board)
	{
		for(const auto & element : row)
		{
			cout << element << " ";
		}

		cout << endl;
	}

	cout << endl;

	return board;
}

int main(int argc, char* argv [])
{
	/*
	vector<vector<char>> board={ {'R', 'D'}, {'*', 'L'} };

	int n=2;

	int m=2;
	*/

	vector<vector<char>> board=createBoard();

	int n=18;

	int m=42;

	int row=0;

	int column=0;

	int cost=0;

	int k=42;

	int currentTime=0;

	cout << findMinimumMoves(board, costBoard, row, column, cost, currentTime, k, n, m) << endl;
}