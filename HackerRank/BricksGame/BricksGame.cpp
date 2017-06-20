#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iterator>
#define MAXINDEX 100001
using namespace std;

long long bricksGame(const vector<long long int> Bricks, int N)
{
	//store the sum of the bricks up the current brick
	vector<long long int> prefixSum;

	prefixSum.reserve(MAXINDEX);

	prefixSum[0]=Bricks[0];

	for(int index=1;index<N;++index)
	{
		prefixSum[index]=prefixSum[index-1] + Bricks[index];
	}

	vector<long long int> dpTable;

	dpTable.reserve(MAXINDEX);

	dpTable[0]=Bricks[0];

	dpTable[1]=dpTable[0] + Bricks[1];

	dpTable[2]=dpTable[1] + Bricks[2];

	//for each brick, we add together the sum of the bricks up to this point, the value of the curent brick, and subtract the amount that the opponent chose before this turn
	//we apply this in the case of taking one brick, two bricks, or three bricks
	for(int index=3;index<N;++index)
	{
		long long int takeOneBrick=prefixSum[index-1] + Bricks[index] - dpTable[index-1];

		long long int takeTwoBricks=prefixSum[index-2] + Bricks[index] + Bricks[index-1] - dpTable[index-2];

		long long int takeThreeBricks=prefixSum[index-3] + Bricks[index] + Bricks[index-1] + Bricks[index-2]  - dpTable[index-3];

		dpTable[index]=max(max(takeOneBrick, takeTwoBricks), takeThreeBricks);
	}

	return dpTable[N-1];
}

int main(int argc, char* argv [])
{
	int numberOfTestCases;

	cin >> numberOfTestCases;

	for(int count=0;count<numberOfTestCases;++count)
	{
		int N;

		cin >> N;

		vector<long long int> bricks;

		bricks.reserve(MAXINDEX);

		for(int counter=0;counter<N;++counter)
		{
			long long int brick;

			cin >> brick;

			bricks.emplace_back(brick);
		}

		reverse(begin(bricks), end(bricks));

		cout << bricksGame(bricks, N) << endl;
	}
}