#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    const int numsSize=int(nums.size());

    if(numsSize==1)
    {
        return numsSize;
    }

    int duplicates=0;

    for(int i=0;i<numsSize;++i)
    {
        if(nums[i]==nums[i-1])
        {
            duplicates++;
        }
        else
        {
            nums[i-duplicates]=nums[i];
        }
    }

    nums.erase(end(nums)-duplicates, end(nums));

    return int(nums.size());
}