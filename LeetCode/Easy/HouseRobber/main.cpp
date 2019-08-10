#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Brute-force recursion, top-down: we either rob each house or we don't.
 * This is based off of the inclusion-exclusion principle.
 *
 * Time complexity: O(2^n) [where n is the length of the input vector]
 * Space complexity: O(2^n)
 *
 * 2) Memoized recursion, top-down: We still either rob or don't rob each house.
 * However, we use a vector to cache our results as we go along.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 3) Dynamic programming, bottom-up: we trade-in the recursion for a for-loop.
 * Our base cases are handled by the first two iterations of the loop and the general case
 * is handled by the remaining iterations.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int helper(vector<int> & nums, int index, int n)
{
    if(index==n-1)
    {
        return nums[index];
    }

    if(index==n-2)
    {
        return max(nums[n-2], nums[n-1]);
    }

    return max(helper(nums, index+2, n)+nums[index], helper(nums, index+1, n));
}

int memoization(vector<int> & nums, vector<int> & memo, int index, int n)
{
    if(index==n-1)
    {
        return nums[index];
    }

    if(index==n-2)
    {
        return max(nums[n-2], nums[n-1]);
    }

    if(memo[index]!=-1)
    {
        return memo[index];
    }

    memo[index]=max(memoization(nums, memo, index+2, n)+nums[index], memoization(nums, memo, index+1, n));

    return memo[index];
}

int rob(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    vector<int> memo(n, -1);

    int index=0;

    //return helper(nums, index, n);

    return memoization(nums, memo, index, n);
}

int rob(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    vector<int> dp(n);

    for(int index=0;index<n;++index)
    {
        if(index==0)
        {
            dp[index]=nums[index];
        }
        else if(index==1)
        {
            dp[index]=max(nums[index], nums[index-1]);
        }
        else
        {
            dp[index]=max(dp[index-2] + nums[index], dp[index-1]);
        }
    }

    return dp[n-1];
}