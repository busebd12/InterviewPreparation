#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/2583868/Naive-Recursion-greater-Better-Rec-greater-Memo-greater-Tabulation-greater-Space-Optimization
2) https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1075496/C%2B%2BPython-Classic-DP

Time complexity: O(m^2) [where m is the length of multipliers]
Space complexity: O(m^2)
*/


class Solution
{
    public:
        int maximumScore(vector<int> & nums, vector<int> & multipliers)
        {
            int result=0;
            
            int n=nums.size();
            
            int m=multipliers.size();
            
            vector<vector<int>> memo(1001, vector<int>(1001, numeric_limits<int>::min()));
            
            int front=0;
            
            int back=n - 1;
            
            int index=0;
            
            result=helper(nums, multipliers, memo, n, m, front, back, index);
            
            return result;
        }
    
        int helper(vector<int> & nums, vector<int> & multipliers, vector<vector<int>> & memo, int n, int m, int front, int back, int index)
        {
            if(index > m - 1)
            {
                return 0;
            }
            
            if(front > n - 1)
            {
                return 0;
            }
            
            if(back < 0)
            {
                return 0;
            }
            
            if(front > back)
            {
                return 0;
            }
            
            if(memo[front][index]!=numeric_limits<int>::min())
            {
                return memo[front][index];
            }
            
            int subproblemSolution=0;
            
            int frontOperation=nums[front] * multipliers[index];
            
            int takeFrontNumber=frontOperation + helper(nums, multipliers, memo, n, m, front + 1, back, index + 1);
            
            int backOperation=nums[back] * multipliers[index];
            
            int takeBackNumber=backOperation + helper(nums, multipliers, memo, n, m, front, back - 1, index + 1);
            
            subproblemSolution=max(takeFrontNumber, takeBackNumber);
            
            memo[front][index]=subproblemSolution;
            
            return subproblemSolution;
        }
};