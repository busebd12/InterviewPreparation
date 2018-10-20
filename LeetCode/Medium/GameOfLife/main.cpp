#include <iostream>
#include <vector>
using namespace std;

bool isOnGrid(int row, int column, const int rows, const int columns)
{
    if((row < 0 || row >= rows) || (column < 0 || column >= columns))
    {
        return false;
    }

    return true;
}

int checkNeighbors(vector<vector<int>> & grid, int row, int column, const int rows, const int columns)
{
    int liveNeighbors=0;

    if(isOnGrid(row+1, column, rows, columns))
    {
        if(grid[row+1][column]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row-1, column, rows, columns))
    {
        if(grid[row-1][column]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row, column+1, rows, columns))
    {
        if(grid[row][column+1]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row, column-1, rows, columns))
    {
        if(grid[row][column-1]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row+1, column+1, rows, columns))
    {
        if(grid[row+1][column+1]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row+1, column-1, rows, columns))
    {
        if(grid[row+1][column-1]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row-1, column+1, rows, columns))
    {
        if(grid[row-1][column+1]==1)
        {
            ++liveNeighbors;
        }
    }

    if(isOnGrid(row-1, column-1, rows, columns))
    {
        if(grid[row-1][column-1]==1)
        {
            ++liveNeighbors;
        }
    }

    if(grid[row][column]==1 && liveNeighbors < 2)
    {
        return 0;
    }
    else if((liveNeighbors==2 || liveNeighbors==3) && grid[row][column]==1)
    {
        return 1;
    }
    else if(grid[row][column]==1 && liveNeighbors > 3)
    {
        return 0;
    }
    else if(grid[row][column]==0 && liveNeighbors==3)
    {
        return 1;
    }
    else if(grid[row][column]==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void gameOfLife(vector<vector<int>> & grid)
{
    if(grid.empty())
    {
        return;
    }

    const int rows=static_cast<int>(grid.size());

    const int columns=static_cast<int>(grid[0].size());

    vector<vector<int>> state(rows, vector<int>(columns));

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            int result=checkNeighbors(grid, row, column, rows, columns);

            state[row][column]=result;
        }
    }

    grid=state;
}