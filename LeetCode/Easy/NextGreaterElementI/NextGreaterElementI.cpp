#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> & findNums, vector<int> & nums)
{
	vector<int> result;

	if(findNums.empty() || nums.empty())
	{
		return result;
	}

	unordered_map<int, int> table;

	const size_t findNumsSize=findNums.size();

	const size_t nums=nums.size();

	for(int index=0;index<numsSize;++index)
	{
		table.emplace(nums[index], index);
	}

	for(int i=0;i<findNumsSize;++i)
	{
		int findNumsElement=findNums[i];

		if(table.find(findNumsElement)!=end(table))
		{
			int index=table[findNumsElement];

			int value=-1;

			for(int j=index+1;j<numsSize;++j)
			{
				int numsElement=nums[j];

				if(numsElement > findNumsElement)
				{
					value=numsElement;

					break;
				}
			}

			result.emplace_back(value);
		}
	}

	return result;
}