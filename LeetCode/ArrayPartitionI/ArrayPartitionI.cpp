#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arrayPairSum(vector<int> & nums)
{
	if(nums.empty())
	{
		return 0;
	}

	if(!is_sorted(begin(nums), end(nums)))
	{
		sort(begin(nums), end(nums));
	}

	const size_t numsSize=nums.size();

	int sum=0;

	for(int index=0;index<=numsSize-2;index+=2)
	{
		sum+=nums[index];
	}

	return sum;
}