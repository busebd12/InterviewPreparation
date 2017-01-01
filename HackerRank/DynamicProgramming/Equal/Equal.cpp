#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

int solution(vector<int> ChocolateValues)
{
	int minimum=*(min_element(begin(ChocolateValues), end(ChocolateValues)));

	int answer=numeric_limits<int>::max();

	for(int currentMinimum=minimum-4;currentMinimum<=minimum;++currentMinimum)
	{
		int moves {};

		for(int index=0;index<ChocolateValues.size();++index)
		{	
			int current=ChocolateValues[index];

			if(current!=currentMinimum)
			{
				while(current!=currentMinimum)
				{
					if(current-5 >= currentMinimum)
					{
						current-=5;
					}
					else if(current-2 >= currentMinimum)
					{
						current-=2;
					}
					else if(current-1 >= currentMinimum)
					{
						current-=1;
					}

					++moves;
				}
			}
		}

		if(moves < answer)
		{
			answer=moves;
		}
	}

	return answer;
}

int main(int argc, char* argv [])
{
	int numberOfTestCases;

	int numberOfColleagues;

	cin >> numberOfTestCases;

	for(int counter=0;counter<numberOfTestCases;++counter)
	{
		cin >> numberOfColleagues;

		vector<int> chocolateValues;

		for(int people=0;people<numberOfColleagues;++people)
		{
			int chocolateValue;

			cin >> chocolateValue;

			chocolateValues.emplace_back(chocolateValue);
		}

		cout << solution(chocolateValues) << endl;

		chocolateValues.clear();
	}
}