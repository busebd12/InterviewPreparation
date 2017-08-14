#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> & nums)
{
    if(nums.empty())
    {
        return;
    }

    int zeroCount=0;

    for(int index=0;index<nums.size();)
    {
        if(nums[index]==0)
        {
            nums.erase(begin(nums)+index);

            ++zeroCount;
        }
        else
        {
            ++index;
        }
    }

    for(int count=0;count<zeroCount;++count)
    {
        nums.emplace_back(0);
    }
}