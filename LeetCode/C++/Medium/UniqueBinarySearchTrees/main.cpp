#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * The number of structurally unique binary search trees containing the numbers [1, n] is equal to the nth catalan number.
 *
 * See the following links
 *
 * https://en.wikipedia.org/wiki/Catalan_number
 * https://www.youtube.com/watch?v=CMaZ69P1bAc
 *
 * 1. Using recursion to calculate the nth catalan number.
 *
 * Time complexity: O(n * 2^n)
 * Space complexity: O(n)
 *
 * 2. Using recursion + memoization to store already solved subproblems.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 *
 * 3. Bottom-up dynamic programming.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

int helper(int n)
{
    if(n <= 1)
    {
        return 1;
    }

    int result=0;

    for(int i=0;i<n;++i)
    {
        result+=helper(i) * helper(n-i-1);
    }

    return result;
}

int numTrees(int n)
{
    return helper(n);
}

int memoization(int n, std::vector<int> & memo)
{
    if(n <= 1)
    {
        return 1;
    }

    if(memo[n]!=-1)
    {
        return memo[n];
    }

    int subproblem=0;

    for(int i=0;i<n;++i)
    {
        subproblem+=memoization(i, memo) * memoization(n-i-1, memo);
    }

    memo[n]=subproblem;

    return subproblem;
}

int numTrees(int n)
{
    std::vector<int> memo(n+1, -1);

    return memoization(n, memo);
}

int numTrees(int n)
{
    std::vector<int> dp(n+1, 0);

    dp[0]=1;

    dp[1]=1;

    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<i;++j)
        {
            dp[i]+=dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}