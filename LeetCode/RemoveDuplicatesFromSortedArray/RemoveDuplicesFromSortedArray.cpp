#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int> & nums)
{
	if(nums.empty())
	{
		return 0;
	}

	if(nums.size()==1)
	{
		return 1;
	}

	const size_t numsSize=nums.size();

	int minimumElement=nums[0];

	int replacementValue=minimumElement-1;

	int replacements{};

	for(int index=0;index<numsSize;++index)
	{
		if(nums[index]==nums[index+1])
		{
			nums[index]=replacementValue;

			++replacements;
		}
	}

	return numsSize-replacements;
}