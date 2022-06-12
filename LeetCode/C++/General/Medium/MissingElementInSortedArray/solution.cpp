#include <vector>
using namespace std;

/*
Solution 1: linear scan

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int countMissingNumbers(vector<int> & nums, int index)
        {
            return (nums[index] - nums[0]) - index;
        }
    
        int missingElement(vector<int> & nums, int k)
        {
            int result=0;
            
            int n=nums.size();
            
            for(int i=1;i<n;i++)
            {
                int missing=(nums[i] - nums[i - 1]) - 1;
                
                if(missing >= k)
                {
                    result=nums[i - 1] + k;
                    
                    return result;
                }
                else
                {
                    k-=missing;
                }
            }
            
            result=nums[n - 1] + k;
            
            return result;
        }
};

/*
Solution 2: binary search

Time complexity: O(log(n)) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int countMissingNumbers(vector<int> & nums, int index)
        {
            return (nums[index] - nums[0]) - index;
        }
    
        int missingElement(vector<int> & nums, int k)
        {
            int result=0;
            
            int n=nums.size();
            
            int low=0;
            
            int high=n - 1;
            
            while(low <= high)
            {
                int middle=(low + (high - low)/2);
                
                int missing=countMissingNumbers(nums, middle);
                
                if(missing >= k)
                {
                    high=middle - 1;
                }
                else
                {
                    low=middle + 1;
                }
            }
            
            int missingFoundInNums=(nums[high] - nums[0]) - high;
            
            result=nums[high] + (k - missingFoundInNums);
            
            return result;
        }
};