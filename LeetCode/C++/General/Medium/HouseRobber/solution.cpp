#include <algorithm>
#include <vector>
using namespace std;

/*
Solutions are inspired by this post --> https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
*/

class Solution
{
    public:
        int dfs(vector<int> & nums, int index)
        {
            if(index < 0)
            {
                return 0;
            }
            
            int subproblem=0;
            
            int robCurrentHouse=nums[index] + dfs(nums, index - 2);
            
            int skipCurrentHouse=dfs(nums, index - 1);
            
            subproblem=max(robCurrentHouse, skipCurrentHouse);
            
            return subproblem;
        }
    
        int rob(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            int index=n-1;
            
            result=dfs(nums, index);
            
            return result;
        }
};

class Solution
{
    public:
        int memoization(vector<int> & nums, vector<int> & memo, int index)
        {
            if(index < 0)
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            int subproblem=0;
            
            int robCurrentHouse=nums[index] + memoization(nums, memo, index - 2);
            
            int skipCurrentHouse=memoization(nums, memo, index - 1);
            
            subproblem=max(robCurrentHouse, skipCurrentHouse);
            
            memo[index]=subproblem;
            
            return subproblem;
        }
    
        int rob(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            vector<int> memo(n + 1, -1);
            
            int index=n-1;
            
            result=memoization(nums, memo, index);
            
            return result;
        }
};

class Solution
{
    public:
        int dfs(vector<int> & nums, int n, int index)
        {
            if(index > n-1)
            {
                return 0;
            }
            
            int subproblem=0;
            
            int robCurrentHouse=nums[index] + dfs(nums, n, index + 2);
            
            int skipCurrentHouse=dfs(nums, n, index + 1);
            
            subproblem=max(robCurrentHouse, skipCurrentHouse);
            
            return subproblem;
        }
    
        int rob(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            int index=0;
            
            result=dfs(nums, n, index);
            
            return result;
        }
};

class Solution
{
    public:
        int memoization(vector<int> & nums, vector<int> & memo, int n, int index)
        {
            if(index > n-1)
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            int subproblem=0;
            
            int robCurrentHouse=nums[index] + memoization(nums, memo, n, index + 2);
            
            int skipCurrentHouse=memoization(nums, memo, n, index + 1);
            
            subproblem=max(robCurrentHouse, skipCurrentHouse);
            
            memo[index]=subproblem;
            
            return subproblem;
        }
    
        int rob(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            vector<int> memo(n + 1, -1);
            
            int index=0;
            
            result=memoization(nums, memo, n, index);
            
            return result;
        }
};