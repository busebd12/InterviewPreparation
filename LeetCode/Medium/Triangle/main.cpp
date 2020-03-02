#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Depth-first search + recursion. We build paths starting from the top of the triangle and each number in an
 * adjancent position from the previously chosen number gives us another path to explore.
 *
 * Time complexity: O(2^n) [where n is the number of elements in the input vectors]
 * Space complexity: O(m) [where m is the number of rows]
 *
 * 2. Similar solution but since adjancent, in this context, means the same index in the next row or the one to the left,
 * we don't need a for loop, we just need to calls to the recursive function.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(m)
 *
 * 3. Depth-first search + memoization. We use a memoization table (std::vector<std::vector<int>> memo) to store answers
 * to previously solved sub-problems so that we don't do repeated work.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

int dfs(std::vector<std::vector<int>> & triangle, int rows, int row, int column)
{
    if(row > rows-1)
    {
        return 0;
    }

    int levelSum=0;

    bool flag=false;

    for(auto i=0;i<triangle[row].size();++i)
    {
        if(i==column || i==column+1)
        {
            int currentSum=triangle[row][i] + dfs(triangle, rows, row+1, i);

            if(!flag)
            {
                levelSum=currentSum;

                flag=true;
            }
            else
            {
                levelSum=std::min(levelSum, currentSum);
            }
        }
    }

    return levelSum;
}

int dfs(std::vector<std::vector<int>> & triangle, int rows, int row, int column)
{
    if(row > rows-1)
    {
        return 0;
    }

    int levelSum=triangle[row][column] + std::min(dfs(triangle, rows, row+1, column), dfs(triangle, rows, row+1, column+1));

    return levelSum;
}

int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    int result=0;

    if(triangle.empty())
    {
        return result;
    }

    int rows=int(triangle.size());

    int row=0;

    int column=0;

    result=dfs(triangle, rows, row, column);

    return result;
}

int memoization(std::vector<std::vector<int>> & triangle, std::vector<std::vector<int>> & memo, int rows, int row, int column)
{
    if(row > rows-1)
    {
        return 0;
    }

    if(memo[row][column]!=-1)
    {
        return memo[row][column];
    }

    memo[row][column]=triangle[row][column] + std::min(memoization(triangle, memo, rows, row+1, column), memoization(triangle, memo, rows, row+1, column+1));

    return memo[row][column];
}

int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    int result=0;

    if(triangle.empty())
    {
        return result;
    }

    int rows=int(triangle.size());

    std::vector<std::vector<int>> memo(rows, std::vector<int>(rows, -1));

    int row=0;

    int column=0;

    result=memoization(triangle, memo, rows, row, column);

    return result;
}