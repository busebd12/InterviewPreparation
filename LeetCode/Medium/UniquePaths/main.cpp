#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion. Starting at (0, 0), we recursively check if we can reach the bottom left-corner of
 * the m-by-n grid. However, our base case checks whether or not we've reached either the last row
 * or the last column. Why? Once we've reached either the last row or the last column, then we know
 * there is only one way to reach the bottom-right corner. Either, traverse the last row or the last column.
 * Since we explore by moving down and by moving to the right, the time complexity will be exponential.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 *
 *
 * 2. Memoization. The idea is to store solutions to repeated sub-problems so we don't have to recalculate them each time.
 * This time, we have an additional base case: if we already have an answer for the current sub-problem, just return it.
 *
 * Time complexity: O(m * n) [where m is the number of rows and n is the number of columns in our grid]
 * Space complexity: O(m * n)
 *
 *
 * 3. Bottom-up dynamic programming. The key here is to change our perspective on the problem and work backwards.
 * Instead of looking for paths from (0, 0) to the bottom-right corner of the grid, we look for paths starting from
 * the bottom-right corner of the grid and ending at (0, 0). Thus, instead of either moving down or to the right, the
 * robot will move either up or to the left. We fill the first row and first column of our dp table with all ones
 * because once we reach the first row or the first column, then we have only one way to reach the top-right corner.
 *
 * Time complexity: O(m * n) [where m is the number of rows and n is the number of columns in our grid]
 * Space complexity: O(m * n)
 *
 */

int dfs(int rows, int columns, int row, int column)
{
    if(row==rows-1 || column==columns-1)
    {
        return 1;
    }

    return dfs(rows, columns, row+1, column) + dfs(rows, columns, row, column+1);
}

int uniquePaths(int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }

    if(m==1 || n==1)
    {
        return 1;
    }

    int row=0;

    int column=0;

    int ways=dfs(m, n, row, column);

    return ways;
}

int memoization(std::vector<std::vector<int>> & memo, int rows, int columns, int row, int column)
{
    if(row==rows-1 || column==columns-1)
    {
        return 1;
    }

    if(memo[row][column]!=-1)
    {
        return memo[row][column];
    }

    memo[row][column]=memoization(memo, rows, columns, row+1, column) + memoization(memo, rows, columns, row, column+1);

    return memo[row][column];
}

int uniquePaths(int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }

    if(m==1 || n==1)
    {
        return 1;
    }

    std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));

    int row=0;

    int column=0;

    int ways=memoization(memo, m, n, row, column);

    return ways;
}

int uniquePaths(int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }

    if(m==1 || n==1)
    {
        return 1;
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    std::fill(dp[0].begin(), dp[0].end(), 1);

    for(int i=0;i<m;++i)
    {
        dp[i][0]=1;
    }

    for(int row=1;row<m;++row)
    {
        for(int column=1;column<n;++column)
        {
            dp[row][column]=dp[row-1][column] + dp[row][column-1];
        }
    }

    return dp[m-1][n-1];
}