#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
#include <algorithm>
#include <type_traits>
#include <tuple>
#include <cmath>
using namespace std;

void modifiedFibonacci(int First, int Second, int N)
{
	vector<long double> memoization;

	memoization.resize(N);

	//pre-seed our vector
	memoization[0]=First;

	memoization[1]=Second;

	for(int index=0;index<N;++index)
	{
		int partOne=pow(memoization[index+1], 2);

		int partTwo=memoization[index];

		memoization[index+2]=partOne + partTwo;

		memoization[index+2]=pow(memoization[index+1], 2) + memoization[index];

		cout << "For index " << index << ": " << endl;

		cout << "part that will be squared: " << memoization[index+1] << endl;

		cout << "first part: " << partOne << endl;

		cout << "second part: " << partTwo << endl;

		cout << "answer: " << memoization[index+2] << endl;

		cout << endl; 

		cout << endl;
	}

	cout << memoization[N-1] << endl;
}

int main(int argc, char* argv [])
{
	
	int first=0;

	int second=1;

	int N=10;

	//cin >> first >> second >> N;

	/*
	cout << "first: " << first << endl;

	cout << "second: " << second << endl;

	cout << "N: " << N << endl;
	*/

	modifiedFibonacci(first, second, N);
}