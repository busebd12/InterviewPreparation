#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursion
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 *
 * 2) Dynamic programming
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int fib(int N)
{
    if(N <= 0)
    {
        return 0;
    }

    if(N==1)
    {
        return 1;
    }

    return fib(N-1) + fib(N-2);
}

int fib(int N)
{
    if(N <= 0)
    {
        return 0;
    }

    vector<int> dp(N+1);

    dp[0]=0;

    dp[1]=1;

    for(int i=2;i<=N;++i)
    {
        dp[i]=dp[i-1] + dp[i-2];
    }

    return dp[N];
}