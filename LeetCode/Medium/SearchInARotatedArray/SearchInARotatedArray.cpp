#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
    if(nums.empty())
    {
        return -1;
    }
    
    const size_t numsSize=nums.size();
    
    int index=-1;
    
    for(int i=0;i<numsSize;++i)
    {
        if(nums[i]==target)
        {
            index=i;
            
            break;
        }
    }
    
    return index;
}