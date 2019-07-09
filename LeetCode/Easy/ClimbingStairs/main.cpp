#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Brute Force:
 * If we have 0 or 1 steps left, we can only get there one way.
 * Else, we can choose to take one step or two steps.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(1)
 *
 * 2) Recursion plus memoization (top-down):
 * Same logic as the brute force approach.
 * However, before making the recursive call(s), we check to see if
 * we have already computed the solution to our subproblem (stored in the vector).
 * If we have, then we just return that answer.
 * Else, we build the solution to that subproblem with recursion.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 3) Straight dynamic programming (bottom-up):
 * We use a vector (dp) to store solutions to subproblems and we create those subproblems
 * in a bottom-up manner with a for loop (working from the base cases upwards).
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int climbStairsBruteForce(int n)
{
    if(n==0)
    {
        return 1;
    }

    if(n==1)
    {
        return 1;
    }

    return climbStairsBruteForce(n-1) + climbStairsBruteForce(n-2);
}

int helper(vector<int> & memoization, int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    if(memoization[n]!=-1)
    {
        return memoization[n];
    }

    memoization[n]=helper(memoization, n-1) + helper(memoization, n-2);

    return memoization[n];
}

int climbStairsMemoization(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    vector<int> memoization(n+1, -1);

    return helper(memoization, n);
}

int climbStairs(int n)
{
    vector<int> dp(n+1);

    dp[0]=1;

    dp[1]=1;

    for(int i=2;i<=n;++i)
    {
        dp[i]=dp[i-1] + dp[i-2];
    }

    return dp[n];
}