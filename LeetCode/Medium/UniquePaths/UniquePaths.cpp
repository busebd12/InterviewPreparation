#include <iostream>
#include <vector>
using namespace std;

//Recursive solution, too slow. Exponential complexity
int getPaths(int row, int column, int m, int n)
{
    if(row==m-1 || column==n-1)
    {
        return 1;
    }

    return getPaths(row+1, column, m, n) + getPaths(row, column+1, m, n);
}

//Dynamic programming approach: time complexity O(m*n); space complexity O(m*n)
long getPathsDynamic(int m, int n)
{
    vector<vector<long>> dp(m, vector<long>(n, 1));

    for(int i=1;i<m;++i)
    {
        for(int j=1;j<n;++j)
        {
            dp[i][j]=dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

long uniquePaths(int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }

    if(m==1 || n==1)
    {
        return 1;
    }

    long paths=getPathsDynamic(m, n);

    return paths;
}