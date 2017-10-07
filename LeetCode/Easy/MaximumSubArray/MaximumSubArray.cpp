#include <iostream>
#include <vector>
#include <cmath>

int maxSubArray(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    
    const size_t numsSize=nums.size();
    
    int maxSumEndingHere=nums[0];
    
    int maxSumSoFar=nums[0];
    
    for(int index=1;index<numsSize;++index)
    {
        maxSumEndingHere=max(nums[index], maxSumEndingHere+nums[index]);
        
        maxSumSoFar=max(maxSumSoFar, maxSumEndingHere);
    }
    
    return maxSumSoFar;
}