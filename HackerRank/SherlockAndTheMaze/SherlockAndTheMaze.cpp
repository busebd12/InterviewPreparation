#include <iostream>
#include <cstdlib>
using namespace std;

bool isEndingPoint(pair<int, int> CurrentPoint, pair<int, int> EndPoint)
{
	return (CurrentPoint.first==EndPoint.first && CurrentPoint.second==EndPoint.second);
}

int findNumberOfWays(pair<int, int> CurrentPoint, pair<int, int> EndPoint, int K, int Turns, int Ways)
{
	if(isEndingPoint(CurrentPoint, EndPoint) && Turns <= K)
	{
		++Ways;
	}
}

int findNumberOfWaysHelper(int N, int M, int K)
{

}

int main(int argc, char** argv)
{
	/*
	int n=2;

	int m=2;

	int k=3;

	int turns=0;

	//returns 2
	*/


	/*
	int n=2;

	int m=3;

	int k=1;

	int turns=0;

	//returns 2
	*/
	


	
	int n=4;

	int m=4;

	int k=4;

	int turns=0;

	//returns 18
	

	cout << findNumberOfWays(n, m, k, turns) << endl;
}