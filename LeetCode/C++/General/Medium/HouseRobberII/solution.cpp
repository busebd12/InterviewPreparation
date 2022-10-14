#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursive depth-first search.

Time complexity: O(2^n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int rob(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            if(n==1)
            {
                result=nums[0];
                
                return result;
            }
            
            if(n==2)
            {
                result=max(nums[0], nums[1]);
                
                return result;
            }
            
            int end=n-1;
            
            int index=0;
            
            int option1=helper(nums, end, index);
            
            end=n;
            
            index=1;
            
            int option2=helper(nums, end, index);
            
            result=max(option1, option2);
            
            return result;
        }
    
        int helper(vector<int> & nums, int end, int index)
        {
            if(index >= end)
            {
                return 0;
            }
            
            int subproblemSolution=0;
            
            int robCurrentHouse=nums[index] + helper(nums, end, index + 2);
            
            int skipCurrentHouse=helper(nums, end, index + 1);
            
            subproblemSolution=max(robCurrentHouse, skipCurrentHouse);
            
            return subproblemSolution;
        }
};

/*
Solution 1: recursive depth-first search with memoization

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int rob(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            if(n==1)
            {
                result=nums[0];
                
                return result;
            }
            
            if(n==2)
            {
                result=max(nums[0], nums[1]);
                
                return result;
            }
            
            vector<int> memo(n, -1);
            
            int end=n-1;
            
            int index=0;
            
            int option1=helper(nums, memo, end, index);
            
            memo.assign(n, -1);
            
            end=n;
            
            index=1;
            
            int option2=helper(nums, memo, end, index);
            
            result=max(option1, option2);
            
            return result;
        }
    
        int helper(vector<int> & nums, vector<int> & memo, int end, int index)
        {
            if(index >= end)
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            int subproblemSolution=0;
            
            int robCurrentHouse=nums[index] + helper(nums, memo, end, index + 2);
            
            int skipCurrentHouse=helper(nums, memo, end, index + 1);
            
            subproblemSolution=max(robCurrentHouse, skipCurrentHouse);
            
            memo[index]=subproblemSolution;
            
            return subproblemSolution;
        }
};