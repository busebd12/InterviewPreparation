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
#include <cmath>
using namespace std;

unsigned long int numberOfBinarySearchTreesHelper(unsigned int N, unsigned int K)
{
	unsigned long int result=1;

	if(K > N-K)
	{
		K=N-K;
	}

	for(int i=0;i<K;++i)
	{
		result*=(N-i);

		result/=(i+1);
	}

	return result;
}


int numberOfBinarySearchTrees(const unsigned int N)
{
	unsigned long int answer=numberOfBinarySearchTreesHelper(2*N, N);

	return answer/(N+1);
}

int main(int argc, char * argv [])
{
	int input;

	auto start=chrono::steady_clock::now();

	cout << "Enter a number: " << endl;

	cin >> input;

	for(int index=0;index<input;++index)
	{
		cout << numberOfBinarySearchTrees(index) << " ";
	}

	cout << endl;

	auto end=chrono::steady_clock::now();

	auto difference=end-start;

	cout << "runtime: " << chrono::duration <double, milli> (difference).count() << " ms" << endl;
}