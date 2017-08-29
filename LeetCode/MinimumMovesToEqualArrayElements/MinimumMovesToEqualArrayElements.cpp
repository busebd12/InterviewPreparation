#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minMoves(vector<int> & nums)
{
	if(nums.empty())
	{
		return 0;
	}

	int minimum=nums[0];

	for(const auto & number : nums)
	{
		minimum=min(number, minimum);
	}

	int answer=0;

	for(auto & number : nums)
	{
		answer+=(number-minimum);
	}

	return answer;
}