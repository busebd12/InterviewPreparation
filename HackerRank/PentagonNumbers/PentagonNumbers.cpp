#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <utility>
#include <chrono>
using namespace std;

//naive solution: just using recursion
//complexity ---> O(3^N)
int pentagonNumbers(const int & N)
{
	if(N==1)
	{
		return 1;
	}
	else if (N==2)
	{
		return 5;
	}
	else
	{
		return ((pentagonNumbers(N-1)-pentagonNumbers(N-2))+3) + pentagonNumbers(N-1);
	} 
}

//solution using dynamic programming
//complexity --> linear
int memoizationPentagonNumbers(const int & N)
{
	if(N==1)
	{
		return 1;
	}
	else if(N==2)
	{
		return 5;
	}

	vector<int> memoization;

	memoization.resize(N);

	//pre-seed our vector
	memoization[0]=1;

	memoization[1]=5;

	//now, go thorugh and calcuate future values based off of past values
	for(int index=2;index<N;++index)
	{
		memoization[index]=( (memoization[index-1]-memoization[index-2]) + 3 ) + memoization[index-1];
	}

	//retrieve already computed values
	return ( (memoization[N-1]-memoization[N-2]) + 3 ) + memoization[N-1];	
}

int main(int argc, char *argv [])
{
	int input;

	while(cin.good())
	{
		cin >> input;

		auto start=chrono::steady_clock::now();

		int answer=memoizationPentagonNumbers(input);

		auto end=chrono::steady_clock::now();

		auto difference=end-start;

		cout << "The answer, " << answer << ", was found in " << chrono::duration <double, milli> (difference).count() << " ms" << endl;
	}
}