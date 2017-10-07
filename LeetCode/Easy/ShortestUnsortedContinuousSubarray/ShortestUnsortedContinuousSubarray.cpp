#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortedInReverse(const vector<int> & nums)
{
    const size_t numsSize=nums.size();

    for(int index=numsSize-1;index>=1;--index)
    {
        if(nums[index] > nums[index-1])
        {   
            return false;
        }
    }

    return true;
}

int findUnsortedSubarray(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    if(is_sorted(begin(nums), end(nums)))
    {   
        return 0;
    }

    if(sortedInReverse(nums))
    {
        return nums.size();
    }

    const size_t numsSize=nums.size();

    vector<int> sortedNums(begin(nums), end(nums));

    sort(begin(sortedNums), end(sortedNums));

    int start=-1;

    int end=-1;

    for(int index=0;index<numsSize;++index)
    {
        if(sortedNums[index]!=nums[index])
        {
            start=index;

            break;
        }
    }

    for(int index=numsSize-1;index>=0;--index)
    {
        if(sortedNums[index]!=nums[index])
        {
            end=index;

            break;
        }
    }

    return end-start+1;
}