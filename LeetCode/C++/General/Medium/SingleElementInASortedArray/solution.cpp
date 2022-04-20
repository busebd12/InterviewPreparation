#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: linear search

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique values in nums]
*/

class Solution
{
    public:
        int singleNonDuplicate(vector<int> & nums)
        {
            unordered_set<int> cache;
            
            for(auto & number : nums)
            {
                if(cache.find(number)==end(cache))
                {
                    cache.insert(number);
                }
                else
                {
                    cache.erase(number);
                }
            }
            
            return *(begin(cache));
        }
};

/*
Solution 2: binary search

Note: the critical observation needed in order to solve this problem --> https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/431425/Only-the-trick-that-is-required-to-be-able-to-solve-this(No-code)

Time complexity: O(log(n)) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int singleNonDuplicate(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            if(n==1)
            {
                return nums[0];
            }
            
            int left=0;
            
            int right=n - 1;
            
            while(left <= right)
            {
                int middle=(left + (right - left)/2);
                
                if(middle > 0 && middle < n-1)
                {
                    if(nums[middle - 1]!=nums[middle] && nums[middle]!=nums[middle + 1])
                    {
                        result=nums[middle];
                        
                        break;
                    }
                }
                else if(middle==0)
                {
                    if(nums[middle + 1]!=nums[middle])
                    {
                        result=nums[middle];
                        
                        break;
                    }
                }
                else if(middle==n-1)
                {
                    if(nums[middle - 1]!=nums[middle])
                    {
                        result=nums[middle];
                        
                        break;
                    }
                }
                
                if(nums[middle]==nums[middle + 1])
                {
                    if(middle%2==0 && (middle + 1)%2==1)
                    {
                        left=middle + 1;
                    }
                    else
                    {
                        right=middle - 1;
                    }
                }
                else if(nums[middle - 1]==nums[middle])
                {
                    if((middle - 1)%2==0 && middle%2==1)
                    {
                        left=middle + 1;
                    }
                    else
                    {
                        right=middle - 1;
                    }
                }
            }
            
            return result;
        }
};