#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

/*
 * Evolution of solutions:
 *
 * 1) Top-down, Brute force recursion, TLE (time limit exceeded): Try all possible combinations/ways we can paint all the houses.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 *
 * 2) Top-down Recursion with memoization: Cache results to prevent unnecessary re-calculation.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 3) Bottom-up, dynamic programming
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int dfs(vector<vector<int>> & costs, int offLimitColor, int index, int n)
{
    if(index==n-1)
    {
        if(offLimitColor==0)
        {
            return min(costs[index][1], costs[index][2]);
        }
        else if(offLimitColor==1)
        {
            return min(costs[index][0], costs[index][2]);
        }
        else
        {
            return min(costs[index][0], costs[index][1]);
        }
    }

    int overallMinCost=numeric_limits<int>::max();

    for(int i=0;i<costs[index].size();++i)
    {
        if(i!=offLimitColor)
        {
            int currentCost=costs[index][i];

            currentCost+=dfs(costs, i, index+1, n);

            overallMinCost=min(overallMinCost, currentCost);
        }
    }

    return overallMinCost;
}

int minCost(vector<vector<int>> & costs)
{
    if(costs.empty())
    {
        return 0;
    }

    if(costs.size()==1)
    {
        return min(min(costs[0][0], costs[0][1]), min(costs[0][1], costs[0][2]));
    }

    int index=0;

    int n=int(costs.size());

    int offLimitColor=-1;

    return dfs(costs, offLimitColor, index, n);
}


int memoization(vector<vector<int>> & costs, vector<int> & memo, int offLimitColor, int index, int n)
{
    if(index==n-1)
    {
        if(offLimitColor==0)
        {
            return min(costs[index][1], costs[index][2]);
        }
        else if(offLimitColor==1)
        {
            return min(costs[index][0], costs[index][2]);
        }
        else
        {
            return min(costs[index][0], costs[index][1]);
        }
    }

    if(memo[index]!=numeric_limits<int>::max())
    {
        return memo[index];
    }

    int overallMinCost=numeric_limits<int>::max();

    for(int i=0;i<costs[index].size();++i)
    {
        if(i!=offLimitColor)
        {
            int currentCost=costs[index][i] + memoization(costs, memo, i, index+1, n);

            overallMinCost=min(overallMinCost, currentCost);
        }
    }

    memo[index]=overallMinCost;

    return memo[index];
}

int minCost(vector<vector<int>> & costs)
{
    if(costs.empty())
    {
        return 0;
    }

    if(costs.size()==1)
    {
        return min(min(costs[0][0], costs[0][1]), min(costs[0][1], costs[0][2]));
    }

    int n=int(costs.size());

    vector<int> memo(n, numeric_limits<int>::max());

    int index=0;

    int offLimitColor=-1;

    return memoization(costs, memo, offLimitColor, index, n);
}


int minCost(vector<vector<int>> & costs)
{
    if(costs.empty())
    {
        return 0;
    }

    if(costs.size()==1)
    {
        return min(min(costs[0][0], costs[0][1]), min(costs[0][1], costs[0][2]));
    }

    int n=int(costs.size());

    vector<vector<int>> dp(n, vector<int>(3));

    dp[0][0]=costs[0][0];

    dp[0][1]=costs[0][1];

    dp[0][2]=costs[0][2];

    int colors=3;

    for(int i=1;i<n;++i)
    {
        for(int chosenColor=0;chosenColor<colors;++chosenColor)
        {
            int cost=numeric_limits<int>::max();

            for(int j=0;j<costs[i].size();++j)
            {
                if(j!=chosenColor)
                {
                    cost=min(cost, dp[i-1][j]);
                }
            }

            dp[i][chosenColor]=cost + costs[i][chosenColor];
        }
    }

    int result=numeric_limits<int>::max();

    for(int color=0;color<colors;++color)
    {
        result=min(result, dp[n-1][color]);
    }

    return result;
}