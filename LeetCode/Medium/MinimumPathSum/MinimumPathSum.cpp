#include <iostream>
#include <vector>
using namespace std;

bool canGoDown(int row, int m)
{
    return row < m;
}

bool canGoRight(int column, int n)
{
    return column < n;
}

int getPathSum(vector<vector<int>> & grid, int row, int column, int m, int n, int pathSum)
{
    pathSum+=grid[row][column];

    if(row==m-1 && column==n-1)
    {
        return pathSum;
    }

    int rightPathSum=-1;

    int downPathSum=-1;

    if(canGoDown(row+1, m))
    {
        rightPathSum=getPathSum(grid, row+1, column, m, n, pathSum);
    }

    if(canGoRight(column+1, n))
    {
        downPathSum=getPathSum(grid, row, column+1, m, n, pathSum);
    }

    if(rightPathSum==-1)
    {
        return downPathSum;
    }
    else if(downPathSum==-1)
    {
        return rightPathSum;
    }
    else
    {
        return min(rightPathSum, downPathSum);
    }
}

int minPathSum(vector<vector<int>> & grid)
{
    int m=int(grid.size());

    int n=int(grid[0].size());

    if(m==0 || n==0)
    {
        return 0;
    }

    int row=0;

    int column=0;

    int pathSum=0;

    int minPathSum=0;

    minPathSum=getPathSum(grid, row, column, m, n, pathSum);

    return minPathSum;
}

//Dynamic programming approach
//Time complexity --> O(m*n)
//Space complexity --> O(m*n)
int minPathSum(vector<vector<int>> & grid)
{
    int m=int(grid.size());

    int n=int(grid[0].size());

    if(m==0 || n==0)
    {
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0]=grid[0][0];

    for(int i=1;i<n;++i)
    {
        dp[0][i]=dp[0][i-1] + grid[0][i];
    }

    for(int j=1;j<m;++j)
    {
        dp[j][0]=dp[j-1][0] + grid[j][0];
    }

    for(int i=1;i<m;++i)
    {
        for(int j=1;j<n;++j)
        {
            dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[m-1][n-1];
}