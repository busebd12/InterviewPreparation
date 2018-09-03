#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums)
{
    if(nums.empty())
    {
        return -1;
    }

    int numsSize=int(nums.size());

    if(numsSize==1)
    {
        return 0;
    }

    for(int i=0;i<numsSize;++i)
    {
        if(nums[i] > nums[i+1])
        {
            return i;
        }
    }

    return numsSize-1;
}