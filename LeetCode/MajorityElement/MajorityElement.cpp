#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    
    unordered_map<int, int> numsMap;
    
    const size_t numsSize=nums.size();
    
    for(int index=0;index<numsSize;++index)
    {
        int number=nums[index];
        
        numsMap[number]++;
    }
    
    int target=numsSize/2;
    
    for(const auto & element : numsMap)
    {
        if(element.second > target)
        {
            return element.first;
        }
    }
}