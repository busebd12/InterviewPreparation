#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <limits>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int getNumberOfSteps(vector<int> ChocolateValues, int Minimum)
{
	int totalSteps{};

	for(auto number : ChocolateValues)
	{
		int currentValue=number;

		int steps{};

		while(currentValue!=Minimum)
		{
			if(currentValue-5 >= Minimum)
			{
				currentValue-=5;

				++steps;
			}
			else if(currentValue-2 >= Minimum)
			{
				currentValue-=2;

				++steps;
			}
			else if(currentValue-1 >= Minimum)
			{
				currentValue-=1;

				++steps;
			}
		}

		totalSteps+=steps;
	}

	return totalSteps;
}

int findMinimumSteps(vector<int> ChocolateValues)
{
	int minimum=*(min_element(begin(ChocolateValues), end(ChocolateValues)));

	vector<int> candidates;

	for(int value=0;value<=5;++value)
	{
		int steps=getNumberOfSteps(ChocolateValues, minimum-value);

		candidates.emplace_back(steps);
	}

	int answer=*(min_element(begin(candidates), end(candidates)));

	return answer;
}

int main(int argc, char** argv)
{
	int T;

	int numberOfElements;

	cin >> T;

	cin >> numberOfElements;

	for(int count=0;count<T;++count)
	{
		vector<int> chocolateValues;

		for(int counter=0;counter<numberOfElements;++counter)
		{
			int element;

			cin >> element;

			chocolateValues.emplace_back(element);
		}

		cout << findMinimumSteps(chocolateValues) << endl;
	}
}