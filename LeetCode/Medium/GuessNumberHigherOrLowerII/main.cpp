#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>> & dp, int left, int right)
{
    if(left >= right)
    {
        return 0;
    }

    if(dp[left][right]!=numeric_limits<int>::max())
    {
        return dp[left][right];
    }

    for(int i=left;i<=right;++i)
    {
        dp[left][right]=min(dp[left][right], max(i + solve(dp, left, i-1), i + solve(dp, i+1, right)));
    }

    return dp[left][right];
}

int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(auto & row : dp)
    {
        fill(row.begin(), row.end(), numeric_limits<int>::max());
    }

    return solve(dp, 1, n);
}