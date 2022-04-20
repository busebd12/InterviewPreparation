#include <algorithm>
#include <vector>

/*
Time complexity: O(n^2) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        long long subArrayRanges(vector<int> & nums)
        {
            long long result=0;
            
            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
                int maxValue=nums[i];
                
                int minValue=nums[i];
                
                for(int j=i+1;j<n;j++)
                {
                    maxValue=max(maxValue, nums[j]);
                    
                    minValue=min(minValue, nums[j]);
                    
                    result+=(maxValue - minValue);
                }
            }
            
            return result;
        }
};