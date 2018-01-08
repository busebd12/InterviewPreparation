#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    if(nums.size() <= 1)
    {
        return;
    }

    const size_t numsSize=nums.size();

    int x=-1;

    for(int index=0;index<numsSize;++index)
    {
        if(index+1 <= numsSize-1)
        {
            if(nums[index] < nums[index+1])
            {
                x=index;
            }
        }
    }

    int y=-1;

    for(int spot=0;spot<numsSize;++spot)
    {
        if(nums[spot] > nums[x])
        {
            if(spot > x)
            {
                if(spot > y)
                {
                    y=spot;
                }
            }
        }
    }

    if(x==-1 || y==-1)
    {
        sort(begin(nums), end(nums));
    }
    else
    {
        swap(nums[x], nums[y]);

        auto start=begin(nums)+(x+1);

        reverse(start, end(nums));
    }
    
    return;
}