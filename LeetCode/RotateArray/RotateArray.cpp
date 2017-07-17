#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> & nums, int k)
{
	for(int count=0;count<k;++count)
	{
		int number=nums.back();

		nums.pop_back();

		nums.insert(begin(nums), number);
	}
}