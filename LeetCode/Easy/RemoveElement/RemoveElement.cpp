#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int removeElement(vector<int> & nums, int val)
{
	if(nums.empty())
	{
		return 0;
	}

	for(auto itr=begin(nums);itr!=end(nums);)
	{
		if((*itr)==val)
		{
			itr=nums.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	return nums.size();
}