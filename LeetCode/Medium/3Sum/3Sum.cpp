#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
{
    const size_t numsSize=nums.size();
    
    if(numsSize < 3)
    {
        return {};
    }

    vector<vector<int>> result;
    
    sort(begin(nums), end(nums));

    for(int i=0;i<numsSize;)
    {
        int start=i+1

        int end=numsSize-1;

        while(start < end)
        {
            if(nums[i]+nums[start]+nums[end]==0)
            {
                result.push_back({nums[i],nums[start],nums[end]});
                
                start++;
                
                end--;
                
                while(start < end && nums[start]==nums[start-1])
                {
                    start++;
                }
                
                while(start < end && nums[end]==nums[end+1])
                {
                    end--;
                }

            }
            else if(nums[i] + nums[start] + nums[end] < 0)
            {
                start++;
                
                while(start < end && nums[start]==nums[start-1])
                {
                    start++;
                }
            }
            else
            {
                end--;
                
                while(start < end && nums[end]==nums[end+1])
                {
                    end--;
                }
            }
        }

        i++;
        
        while(i< numsSize && nums[i]==nums[i-1])
        {
            i++;
        }
    }
    
    return result;
}