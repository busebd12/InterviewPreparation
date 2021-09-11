#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion. We recursively check if we can reach the bottom-right corner from the top-left corner.
 * Each time, we choose to explore in the down direction and the right direction from the current spot
 * in the grid, so the time complexity will be expoential.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 *
 * 2. Memoization. We recursively solve sub-problems in a top-down manner and store the answers as we go along
 * so we don't have to keep re-calculating them.
 *
 * Time complexity: O(m * n) [where m is the number of rows in our grid and n is the number of columns]
 * Space complexity: O(m * n)
 *
 * 3. Bottom-up dynamic programming. Instead of the robot moving down or right, we have the robot move up or left.
 *
 * Time complexity: O(m * n) [where m is the number of rows in our grid and n is the number of columns in the grid]
 * Space complexity: O(m * n)
 *
 * 4. Bottom-up dynamic programming but using the grid as our dp table.
 *
 * Time complexity: O(m * n) [where m is the number of rows in the grid and n is the number of columns]
 * Space complexity: O(1)
 */

bool onBoard(int & rows, int & columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int dfs(std::vector<std::vector<int>> & grid, int rows, int columns, int row, int column)
{
    if(!onBoard(rows, columns, row, column))
    {
        return std::numeric_limits<int>::max();
    }

    if(row==rows-1 && column==columns-1)
    {
        return grid[row][column];
    }

    return grid[row][column] + std::min(dfs(grid, rows, columns, row+1, column), dfs(grid, rows, columns, row, column+1));
}

int minPathSum(std::vector<std::vector<int>> & grid)
{
    if(grid.empty())
    {
        return 0;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    int row=0;

    int column=0;

    int result=dfs(grid, rows, columns, row, column);

    return result;
}

int memoization(std::vector<std::vector<int>> & grid, std::vector<std::vector<int>> & memo, int rows, int columns, int row, int column)
{
    if(!onBoard(rows, columns, row, column))
    {
        return std::numeric_limits<int>::max();
    }

    if(row==rows-1 && column==columns-1)
    {
        return grid[row][column];
    }

    if(memo[row][column]!=-1)
    {
        return memo[row][column];
    }

    memo[row][column]=grid[row][column] + std::min(memoization(grid, memo, rows, columns, row+1, column), memoization(grid, memo, rows, columns, row, column+1));

    return memo[row][column];
}

int minPathSum(std::vector<std::vector<int>> & grid)
{
    if(grid.empty())
    {
        return 0;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    std::vector<std::vector<int>> memo(rows, std::vector<int>(columns, -1));

    int row=0;

    int column=0;

    int result=memoization(grid, memo, rows, columns, row, column);

    return result;
}

int minPathSum(std::vector<std::vector<int>> & grid)
{
    if(grid.empty())
    {
        return 0;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, 0));

    dp[0][0]=grid[0][0];

    for(auto i=1;i<rows;++i)
    {
        dp[i][0]=dp[i-1][0] + grid[i][0];
    }

    for(auto i=1;i<columns;++i)
    {
        dp[0][i]=dp[0][i-1] + grid[0][i];
    }

    for(auto row=1;row<rows;++row)
    {
        for(auto column=1;column<columns;++column)
        {
            dp[row][column]=grid[row][column] + std::min(dp[row-1][column], dp[row][column-1]);
        }
    }

    return dp[rows-1][columns-1];
}

int minPathSum(std::vector<std::vector<int>> & grid)
{
    if(grid.empty())
    {
        return 0;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    for(auto i=1;i<rows;++i)
    {
        grid[i][0]=grid[i-1][0] + grid[i][0];
    }

    for(auto i=1;i<columns;++i)
    {
        grid[0][i]=grid[0][i-1] + grid[0][i];
    }

    for(auto row=1;row<rows;++row)
    {
        for(auto column=1;column<columns;++column)
        {
            grid[row][column]=grid[row][column] + std::min(grid[row-1][column], grid[row][column-1]);
        }
    }

    return grid[rows-1][columns-1];
}