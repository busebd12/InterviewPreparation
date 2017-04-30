#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

void getCombinations(vector<int> Numbers, vector<int> Combination, int StartingIndex, int Level, size_t CombinationSize)
{
	size_t numbersSize=Numbers.size();

	if(Level==CombinationSize)
	{
		copy(begin(Combination), end(Combination), ostream_iterator<int>(cout, " "));

		cout << endl;

		return;
	}

	for(int index=StartingIndex;index<numbersSize;++index)
	{
		Combination[Level]=Numbers[index];

		getCombinations(Numbers, Combination, index+1, Level+1, CombinationSize);
	}
}

void getCombinationsHelper(vector<int> Numbers, size_t CombinationSize)
{
	vector<int> combination;

	combination.resize(CombinationSize);

	size_t combinationSize=CombinationSize;

	int level=0;

	int startingIndex=0;

	getCombinations(Numbers, combination, startingIndex, level, combinationSize);
}