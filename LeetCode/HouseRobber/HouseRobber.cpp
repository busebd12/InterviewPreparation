#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> & nums)
{
	if(nums.empty())
	{
		return 0;
	}

	const size_t numsSize=nums.size();

	int evenHouseTotal=0;

	int oddHouseTotal=0;

	for(int index=0;index<numsSize;++index)
	{
		if(index%2==0)
		{
			evenHouseTotal=max(evenHouseTotal+nums[index], oddHouseTotal);
		}
		else
		{
			oddHouseTotal=max(evenHouseTotal, oddHouseTotal+nums[index]);
		}
	}

	return max(evenHouseTotal, oddHouseTotal);
}