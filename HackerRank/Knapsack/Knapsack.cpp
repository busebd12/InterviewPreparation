#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int knapsack(const vector<int> Numbers, int Index, int Sum)
{
	if(Index <= 0 || Sum <= 0)
	{
		return 0;
	}

	//if the current number we are looking at is larger than the sum, we obviously can't include it in our knapsack; skip it
	while(Numbers[Index-1] > Sum)
	{
		--Index;
	}

	//calulate the max sum using the rest of the vector without the currrent number
	int currentNumberNotUsed=knapsack(Numbers, Index-1, Sum);

	//calculate the max sum using the current number more than once along with the rest of the vector
	int currentNumberUsedMoreThanOnce=Numbers[Index-1] + knapsack(Numbers, Index, Sum-Numbers[Index-1]);

	//calculate the max sum using the current number only once along with the rest of the vector
	int currentNumberUsedOnlyOnce=Numbers[Index-1] + knapsack(Numbers, Index-1, Sum-Numbers[Index-1]);

	return max(max(currentNumberNotUsed, currentNumberUsedMoreThanOnce), max(currentNumberUsedMoreThanOnce, currentNumberUsedOnlyOnce));
}

int main(int argc, char* argv [])
{
	int numberOfTestCases;

	cin >> numberOfTestCases;

	for(int count=0;count<numberOfTestCases;++count)
	{
		size_t N;

		int Sum;

		cin >> N >> Sum;

		vector<int> numbers;

		for(int counter=0;counter<N;++counter)
		{
			int number;

			cin >> number;

			numbers.emplace_back(number);
		}

		cout << knapsack(numbers, N, Sum) << endl;
	}
}