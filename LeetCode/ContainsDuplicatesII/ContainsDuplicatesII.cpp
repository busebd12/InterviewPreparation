#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsNearbyDuplicates(vector<int> & Nums, int K)
{
	unordered_set<int> numsSet;

	size_t numsSize=nums.size();

	for(int index=0;index<numsSize;++index)
	{
		if(index > K)
		{
			numsSet.erase(Nums[index-k-1]);
		}

		if(numsSet.find(Nums[index])!=end(numsSet))
		{
			return true;
		}

		numsSet.insert(Nums[index]);
	}

	return false;
}