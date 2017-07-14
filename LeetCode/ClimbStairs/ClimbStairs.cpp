#include <iostream>
using namespace std;

int climbStairsRecursive
{
    if(n==1 || n==0)
    {
        return 1;
    }
    
    return climbStairs(n-1)+climbStairs(n-2);
}

int climbStairsDP(int n)
{
    int dp[n+1];
    
    dp[0]=1;
    
    dp[1]=1;
    
    for(int index=2;index<=n;++index)
    {
        dp[index]=dp[index-1]+dp[index-2];
    }
    
    return dp[n];
}