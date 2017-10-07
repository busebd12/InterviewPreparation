#include <iostream>
#include <vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    
    const size_t numsSize=nums.size();
    
    int currentLength=1;
    
    int maxLength=0;
    
    bool alwaysIncreasing=true;
    
    for(int index=0;index<numsSize-1;++index)
    {   
        if(nums[index+1] > nums[index])
        {
            ++currentLength;
        }
        else
        {
            alwaysIncreasing=false;
            
            if(currentLength > maxLength)
            {
                maxLength=currentLength;
            }
            
            currentLength=1;
        }
    }
    
    if(alwaysIncreasing)
    {
        maxLength=currentLength;
    }
    
    if(currentLength > maxLength)
    {
        maxLength=currentLength;
    }
    
    return maxLength;
}