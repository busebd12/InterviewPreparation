#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force, top-down recursion. The cost for getting to the top floor
 * is the cost of the current step plus the minimum cost between the next step
 * and the step two steps ahead of the current one.
 *
 * Time complexity: O(2^n) [where n is the size of the input vector]
 * Space complexity: O(2^n) recursive stack space
 *
 *
 * 2) Top-down memoized recursion. Same logic. Use a vector<int> memo to store answers to sub-problems.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 *
 * 3) Bottom-up dynamic programming. The top floor can either be reached from either two steps below or one-step below.
 * Build solutions to sub-problemms in a bottom-up manner.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n)
 */

int dfs(vector<int> & cost, size_t n, size_t index)
{
    if(index >= n)
    {
        return 0;
    }

    if(index==n-1)
    {
        return cost[index];
    }

    int currentStepCost=cost[index] + min(dfs(cost, n, index+1), dfs(cost, n, index+2));

    return currentStepCost;
}

int minCostClimbingStairs(vector<int> & cost)
{
    if(cost.empty())
    {
        return 0;
    }

    size_t n=cost.size();

    size_t index=0;

    int startAtZero=dfs(cost, n, index);

    index=1;

    int startAtOne=dfs(cost, n, index);

    return min(startAtZero, startAtOne);
}

int memoization(vector<int> & cost, vector<int> & memo, size_t n, size_t index)
{
    if(index >= n)
    {
        return 0;
    }

    if(index==n-1)
    {
        return cost[index];
    }

    if(memo[index]!=-1)
    {
        return memo[index];
    }

    memo[index]=cost[index] + min(memoization(cost, memo, n, index+1), memoization(cost, memo, n, index+2));

    return memo[index];
}

int minCostClimbingStairs(vector<int> & cost)
{
    if(cost.empty())
    {
        return 0;
    }

    size_t n=cost.size();

    vector<int> memo(n, -1);

    size_t index=0;

    int startAtZero=memoization(cost, memo, n, index);

    index=1;

    fill(memo.begin(), memo.end(), -1);

    int startAtOne=memoization(cost, memo, n, index);

    return min(startAtZero, startAtOne);
}

int minCostClimbingStairs(vector<int> & cost)
{
    if(cost.empty())
    {
        return 0;
    }

    size_t n=cost.size();

    vector<int> dp(n, 0);

    dp[0]=cost[0];

    dp[1]=cost[1];

    for(size_t index=2;index<n;++index)
    {
        dp[index]=cost[index] + min(dp[index-1], dp[index-2]);
    }

    return min(dp[n-1], dp[n-2]);
}