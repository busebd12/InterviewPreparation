#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion. Starting at (0, 0) we recursive check if we can reach the bottom right-hand corner
 * by moving down or right in our grid. If we find an obstacle, then the current path is no longer
 * valid and we return 0. Since we explore by going right and down, the time complexity will be exponential.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 *
 * 2. Memoization. We recursively explore the grid in the same manner except that we store solutions to sub-problems
 * so that we don't have to re-compute them repeatedly.
 *
 * Time complexity: O(rows * columns) [where rows is the number of rows in our grid and columsn is the number of columns in our grid]
 * Space complexity: O(rows * columns)
 *
 * 3. Bottom-up dynamic programming. The key here is to change our perspective on the problem. Instead of looking for
 * paths starting from (0, 0), we look for paths starting from the bottom right-hand corner and ending at (0, 0).
 * So, instead of the robot moving either down or to the right, the robot will move either up or to the left.
 * When filling out our dp table, for the first row and first column, if grid[row][column] is 1, then any
 * spots in the grid after and including grid[row][column] cannot be reached, so we set them to zero.
 * Then, we fill out the rest of our dp table.
 *
 * Time complexity: O(m * n)
 * Space complexity: O(m * n)
 */

bool onBoard(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int dfs(std::vector<std::vector<int>> & obstacleGrid, int rows, int columns, int row, int column)
{
    if(!onBoard(rows, columns, row, column))
    {
        return 0;
    }

    if(obstacleGrid[row][column]==1)
    {
        return 0;
    }

    if(row==rows-1 && column==columns-1)
    {
        return 1;
    }

    return dfs(obstacleGrid, rows, columns, row+1, column) + dfs(obstacleGrid, rows, columns, row, column+1);
}

int uniquePathsWithObstacles(std::vector<std::vector<int>> & obstacleGrid)
{
    if(obstacleGrid.empty())
    {
        return 0;
    }

    int rows=int(obstacleGrid.size());

    int columns=int(obstacleGrid[0].size());

    int row=0;

    int column=0;

    int ways=dfs(obstacleGrid, rows, columns, row, column);

    return ways;
}

int memoization(std::vector<std::vector<int>> & obstacleGrid, std::vector<std::vector<int>> & memo, int rows, int columns, int row, int column)
{
    if(!onBoard(rows, columns, row, column))
    {
        return 0;
    }

    if(obstacleGrid[row][column]==1)
    {
        return 0;
    }

    if(row==rows-1 && column==columns-1)
    {
        return 1;
    }

    if(memo[row][column]!=-1)
    {
        return memo[row][column];
    }

    memo[row][column]=memoization(obstacleGrid, memo, rows, columns, row+1, column) + memoization(obstacleGrid, memo, rows, columns, row, column+1);

    return memo[row][column];
}

int uniquePathsWithObstacles(std::vector<std::vector<int>> & obstacleGrid)
{
    if(obstacleGrid.empty())
    {
        return 0;
    }

    int rows=int(obstacleGrid.size());

    int columns=int(obstacleGrid[0].size());

    int row=0;

    int column=0;

    std::vector<std::vector<int>> memo(rows, std::vector<int>(columns, -1));

    int ways=memoization(obstacleGrid, memo, rows, columns, row, column);

    return ways;
}

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    if(obstacleGrid.empty())
    {
        return 0;
    }

    int rows=int(obstacleGrid.size());

    int columns=int(obstacleGrid[0].size());

    std::vector<std::vector<long>> dp(rows, std::vector<long>(columns, 0));

    for(auto i=0;i<columns;++i)
    {
        if(obstacleGrid[0][i]!=1)
        {
            dp[0][i]=1;
        }
        else
        {
            break;
        }
    }

    for(auto i=0;i<rows;++i)
    {
        if(obstacleGrid[i][0]!=1)
        {
            dp[i][0]=1;
        }
        else
        {
            break;
        }
    }

    for(auto row=1;row<rows;++row)
    {
        for(auto column=1;column<columns;++column)
        {
            if(obstacleGrid[row][column]!=1)
            {
                dp[row][column]=dp[row-1][column] + dp[row][column-1];
            }
        }
    }

    return int(dp[rows-1][columns-1]);
}