#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> powerOfTwo(vector<int> & nums, int target)
{
	if(nums.empty())
	{
		return vector<int>();
	}

	size_t numsSize=nums.size();

	unordered_map<int, int> indices;

	vector<int> answer;

	for(int index=0;index<numsSize;++index)
	{
		int numberToFind=target-nums[index];

		if(indices.find(numerToFind)!=end(indices))
		{
			answer.emplace_back(index);

			answer.emplace_back(indices[numberToFind]);
		}

		indices[nums[index]]=index;
	}

	return answer;
}