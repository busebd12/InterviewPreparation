#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename Type>
void printMatrix(const vector<vector<Type>> & Matrix)
{
	for(const auto & row : Matrix)
	{
		for(const auto & element : row)
		{
			cout << element << " ";
		}

		cout << endl;
	}
}

decltype(auto) createMatrix(const vector<vector<char>> & Land, int M, int N)
{
	vector<vector<int>> matrix(M, vector<int>(N));

	for(int start=0;start<M-1;++start)
	{
		//cout << "START: " << start << endl;

		//cout << "LOOKING AT ROW: " << start << endl;

		int previousDistance {};

		for(int column=start;column<N;++column)
		{
			//cout << "column: " << column << endl;

			//cout << "Looking at character: " << Land[start][column] << endl;

			if(Land[start][column]=='#')
			{
				//cout << "At (" << start << ", " << column << ") before assignment: " << matrix[start][column] << endl;

				matrix[start][column]=previousDistance;

				//cout << "At (" << start << ", " << column << ") after assignment: " << matrix[start][column] << endl;

				++previousDistance;
			}
			else
			{
				//cout << "At (" << start << ", " << column << ") before assignment: " << matrix[start][column] << endl;

				matrix[start][column]=-1;

				//cout << "At (" << start << ", " << column << ") after assignment: " << matrix[start][column] << endl;

				previousDistance=0;
			}
		}

		previousDistance=0;

		//cout << endl;

		//cout << endl;

		//cout << "LOOKING AT COLUMN: " << start << endl;

		for(int row=start;row<M;++row)
		{
			//cout << "row: " << row << endl;

			//cout << "Looking at character: " << Land[row][start] << endl;

			if(Land[row][start]=='#')
			{
				//cout << "At (" << row << ", " << start << ") before assignment: " << matrix[row][start] << endl;

				matrix[row][start]=previousDistance;

				//cout << "At (" << row << ", " << start << ") after assignment: " << matrix[row][start] << endl;

				++previousDistance;
			}
			else
			{
				//cout << "At (" << row << ", " << start << ") before assignment: " << matrix[row][start] << endl;

				matrix[row][start]=-1;

				//cout << "At (" << row << ", " << start << ") after assignment: " << matrix[row][start] << endl;

				previousDistance=0;
			}
		}

		//cout << endl;

		//cout << endl;
	}

	//cout << endl;

	//cout << endl;

	//cout << "FINAL MATRIX: " << endl;

	//printMatrix(matrix);

	return matrix;
}

void solution(const vector<vector<int>> & Matrix, int M, int N)
{
	int leftMax {};

	int upMax {};

	for(int start=0;start<M-1;++start)
	{
		//cout << "START: " << start << endl;

		//cout << endl;

		//cout << "LOOKING AT ROW: " << start << endl;

		//cout << "Before first inner for loop" << endl;

		for(int column=start;column<N;++column)
		{
			//cout << "column: " << column << endl;

			//cout << "At (" << start << ", " << column << "): " << Matrix[start][column] << endl;

			if(Matrix[start][column] > leftMax)
			{
				//cout << "leftMax before: " << leftMax << endl;

				leftMax=Matrix[start][column];

				//cout << "leftMax after: " << leftMax << endl;
			}
			
			if(Matrix[start][column]==-1)
			{
				//cout << "At (" << start << ", " << column << "): " << Matrix[start][column] << endl;

				break;
			}
		}

		//cout << endl;

		//cout << endl;

		//cout << "Before second inner for loop" << endl;

		for(int row=start;row<M;++row)
		{
			//cout << "row: " << row << endl;

			//cout << "At (" << row << ", " << start << "): " << Matrix[row][start] << endl;

			if(Matrix[row][start] > upMax)
			{
				//cout << "upMax before: " << upMax << endl;

				upMax=Matrix[row][start];

				//cout << "upMax after: " << upMax << endl;
			}

			if(Matrix[row][start]==-1)
			{
				//cout << "At (" << row << ", " << start << "): " << Matrix[row][start] << endl;

				break;
			}
		}

		//cout << endl;

		//cout << endl;
	}

	if(upMax==0 || leftMax==0)
	{
		cout << "impossible" << endl;
	}
	else
	{
		cout << (2*(upMax) + 2*(leftMax)) << endl;
	}
}

int main(int argc, char* argv[])
{
	cout << "TEST CASE 1:" << endl;

	vector<vector<char>> testCase1={ {'#', '#', '#', '#', '#'},  {'#', 'x', '#', 'x', '#'}, {'#', '#', '#', '#', '#'}, {'#', '#', '#', '#', '#'} };

	auto matrix1=createMatrix(testCase1, 4, 5);

	cout << endl;

	solution(matrix1, 4, 5);

	cout << endl;

	
	cout << "TEST CASE 2:" << endl;
	
	vector<vector<char>> testCase2={{'#', '#', '#', '#'},  {'#', 'x', '#', 'x'}, {'#', '#', '#', '#'}, {'#', '#', '#', '#'} };

	auto matrix2=createMatrix(testCase1, 4, 5);

	cout << endl;

	solution(matrix2, 4, 4);

	cout << endl;
	

	cout << "TEST CASE 3:" << endl;

	vector<vector<char>> testCase3={ {'#', 'x'}, {'x', '#'} };

	auto matrix3=createMatrix(testCase3, 2, 2);

	cout << endl;

	solution(matrix3, 2, 2);

	cout << endl;
	

	cout << "TEST CASE 4:" << endl;

	vector<vector<char>> testCase4={ {'#', '#', '#', '#', '#'}, {'x', 'x', 'x', 'x', '#'} };

	auto matrix4=createMatrix(testCase4, 2, 5);

	cout << endl;

	solution(matrix4, 2, 5);

	cout << endl;
	
	
	cout << "TEST CASE 5:" << endl;
	
	vector<vector<char>> testCase5={ {'#', '#', '#', '#', '#'},  {'#', '#', '#', '#', '#'}, {'#', 'x', '#', 'x', '#'}, {'#', '#', 'x', 'x', '#'}, {'#', 'x', '#', '#', '#'} };

	auto matrix5=createMatrix(testCase5, 5, 5);

	cout << endl;

	solution(matrix5, 5, 5);
	
	

	/*
	int M;

	int N;

	cin >> M >> N;

	vector<vector<char>> land;

	for(int x=0;x<M;++x)
	{
		vector<char> v;

		for(int y=0;y<N;++y)
		{
			char c;

			cin >> c;
			
			v.emplace_back(c);
		}
	}

	auto matrix=createMatrix(land, M, N);

	solution(matrix, M, N);
	*/
}