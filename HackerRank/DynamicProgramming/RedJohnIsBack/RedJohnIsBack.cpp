#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int Number)
{
	if(Number < 2)
	{
		return false;
	}

	for(int value=2;value<=sqrt(Number);++value)
	{
		if(Number%value==0)
		{
			return false;
		}
	}

	return true;
}

//complexity: O(2^n)
int recursiveSolutionHelper(int N)
{
	if(N==0 || N==1 || N==2 || N==3)
	{
		 return 1;
	}
	else
	{
		return recursiveSolutionHelper(N-1)+recursiveSolutionHelper(N-4);
	}
}

//complexity: O(n)
int dynamicProgrammingSolutionHelper(int N)
{
	vector<int> dpTable;

	dpTable.resize(40);

	//bases cases -> zero through three
	for(int index=0;index<4;++index)
	{
		dpTable[index]=1;
	}

	//calculate combinations for N larger than 3
	for(int index=4;index<=40;++index)
	{
		dpTable[index]=dpTable[index-1]+dpTable[index-4];
	}

	return dpTable[N];
}

int solution(int N)
{
	int combinations=dynamicProgrammingSolutionHelper(N);

	int P {};

	for(int value=2;value<=combinations;++value)
	{
		if(isPrime(value))
		{
			++P;
		}
	}

	return P;
}


int main(int argc, char* argv [])
{	
	int numberOfTestCases;

	cin >> numberOfTestCases;

	while(numberOfTestCases--)
	{
		int testCase;

		cin >> testCase;

		cout << solution(testCase) << endl;
	}
}