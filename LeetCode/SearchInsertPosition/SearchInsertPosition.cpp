#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchInsert(vector<int> & nums, int target)
{
	if(nums.empty())
	{
		return 0;
	}

	const size_t numsSize=nums.size();

	for(int index=0;index<numsSize;++index)
	{
		if(nums[index]==target)
		{
			return index;
		}
	}

	int minimum=nums[0];

	int maximum=nums[numsSize-1];

	if(target < minimum)
	{
		return 0;
	}

	if(target > maximum)
	{
		return numsSize;
	}

	for(int index=0;index<numsSize;++index)
	{
		if(nums[index] < target && target < nums[index+1])
		{
			return index+1;
		}
	}
}