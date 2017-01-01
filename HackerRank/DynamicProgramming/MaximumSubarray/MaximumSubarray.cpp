#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cmath>
#include <type_traits>
#include <numeric>
using namespace std;

int findNonContiguousSum(vector<int> & Digits)
{
	int sum {};

	for(int index=0;index<Digits.size();++index)
	{
		if(Digits[index] > 0)
		{
			int num=Digits[index];

			sum+=num;
		}
	}

	return sum;
}

int findContiguousSum(vector<int> & Digits)
{
	int maxSoFar=0;

	int maxEndingHere=0;

	for(int index=0;index<Digits.size();++index)
	{
		maxEndingHere+=Digits[index];

		if(maxEndingHere < 0)
		{
			maxEndingHere=0;
		}

		if(maxSoFar < maxEndingHere)
		{
			maxSoFar=maxEndingHere;
		}
	}

	return maxSoFar;
}

void maximumSubarray(vector<int> & Digits)
{
	if(Digits.size()==0)
	{
		cout << 0 << " " << 0 << endl;
	}
	else
	{
		bool allSame=equal(Digits.begin(), Digits.end(), Digits.begin());

		bool allNegative=all_of(Digits.begin(), Digits.end(), [] (const auto & element) {return element < 0;});

		bool allPositive=all_of(Digits.begin(), Digits.end(), [] (const auto & element) {return element > 0;});
		
		if((allSame && allPositive) || allPositive)
		{
			cout << accumulate(Digits.begin(), Digits.end(), 0) << " " << accumulate(Digits.begin(), Digits.end(), 0) << endl;
		}
		else if((allSame && allNegative) || allNegative)
		{
			cout << *(min_element(Digits.begin(), Digits.end())) << " " << *(min_element(Digits.begin(), Digits.end())) << endl;
		}
		else
		{
			int contiguousSum=findContiguousSum(Digits);

			int nonContiguousSum=findNonContiguousSum(Digits);

			cout << contiguousSum << " " << nonContiguousSum << endl;	
		}	
	}
}

int main(int argc, char* argv [])
{
	vector<int> numbers={1, 2, 3, 4};

	maximumSubarray(numbers);

	/*
	int numberOfLoops;

	int numberOfElements;

	vector<int> numbers;

	cin >> numberOfLoops;

	for(int count=0;cout<numberOfLoops;++count)
	{
		cin >> numberOfElements;

		for(int digit=0;digit<numberOfElements;++digit)
		{
			numbers.push_back(digit);
		}

		maximumSubarray(numbers);
	}
	*/
}