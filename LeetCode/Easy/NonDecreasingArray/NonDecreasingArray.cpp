#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPossibility(vector<int>& nums)
{
    if(nums.empty())
    {
        return false;
    }

    const size_t numsSize=nums.size();

    for(int index=0;index<numsSize-1;++index)
    {
        if(nums[index] > nums[index+1])
        {
            int temp=nums[index];
            
            nums[index]=nums[index+1];
            
            if(is_sorted(begin(nums), end(nums)))
            {
                return true;
            }
            
            nums[index]=temp;
            
            nums[index+1]=nums[index];
            
            if(is_sorted(begin(nums), end(nums)))
            {
                return true;
            }
            
            return false;
        }
    }
    
    return true;
}