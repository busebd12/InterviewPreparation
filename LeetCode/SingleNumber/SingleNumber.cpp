#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    
    if(nums.size()==1)
    {
        return nums[0];
    }
    
    unordered_map<int, int> numsMap;
    
    const size_t numsSize=nums.size();
    
    for(int index=0;index<numsSize;++index)
    {
        int number=nums[index];
        
        numsMap[number]++;
    }
    
    for(const auto & element : numsMap)
    {
        if(element.second==1)
        {
            return element.first;
        }
    }
}

//no extra space version using XOR instead
int singleNumber(vector<int> & nums)
{
    int answer=0;

    for(int index=0;index<nums.size();++index)
    {        
        answer^=nums[index];
    }

    return answer;
}