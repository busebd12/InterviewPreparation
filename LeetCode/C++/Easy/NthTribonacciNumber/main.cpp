#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Recursion. Similar to the fibonacci sequence except that we account for a third term/number (n-3).
 *
 * Time complexity: O(n^3)
 * Space complexity: O(n^3)
 *
 *
 * 2. Top-down memoization. Instead of re-calculating each subproblem every time, we store intermediate results
 * in vector<int> memo and retrieve solutions to subproblems for there.
 *
 * Time complexity: O(n) [where n is the input number]
 * Space complexity: O(n)
 *
 *
 * 3. Bottom-up dynamic programming. We build solutions to subproblems from the ground-up.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int tribonacci(int n)
{
    if(n==0)
    {
        return 0;
    }

    if(n==1 || n==2)
    {
        return 1;
    }

    return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
}

int memoization(vector<int> & memo, int n)
{
    if(n==0)
    {
        return 0;
    }

    if(n==1 || n==2)
    {
        return 1;
    }

    if(memo[n]!=-1)
    {
        return memo[n];
    }

    memo[n]=memoization(memo, n-3) + memoization(memo, n-2) + memoization(memo, n-1);

    return memo[n];
}

int tribonacci(int n)
{
    vector<int> memo(n+1, -1);

    return memoization(memo, n);
}

int tribonacci(int n)
{
    vector<int> dp(38, 0);

    dp[1]=1;

    dp[2]=1;

    for(int i=3;i<=n;++i)
    {
        dp[i]=dp[i-3] + dp[i-2] + dp[i-1];
    }

    return dp[n];
}