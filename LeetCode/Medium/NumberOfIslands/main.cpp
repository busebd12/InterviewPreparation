#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> & grid, size_t row, size_t column)
{
    if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column]=='0')
    {
        return;
    }

    grid[row][column]='0';

    dfs(grid, row-1, column);

    dfs(grid, row+1, column);

    dfs(grid, row, column-1);

    dfs(grid, row, column+1);
}

int numIslands(vector<vector<char>>& grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    size_t gridSize=grid.size();

    size_t rowSize=grid[0].size();

    for(size_t row=0;row<gridSize;++row)
    {
        for(size_t column=0;column<rowSize;++column)
        {
            if(grid[row][column]=='1')
            {
                ++islands;

                dfs(grid, row, column);
            }
        }
    }

    return islands;
}