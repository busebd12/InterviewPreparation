#include <iostream>
#include <vector>
using namespace std;

/*
Approach: As we loop over the grid, if we find a 1 (land), the only sides of the square that will
contribute to the perimeter calculation are those that are either touching water or edges of the grid.

Time complexity: O(row * columns) [where rows is the number of rows in the grid and
columns is the number of columns in the grid]
Space complexity: O(1)
*/

bool isOnBoard(int rows, int columns, int row, int column)
{
    return (((row >= 0) && (row < rows)) && ((column >= 0) && (column < columns)));
}

int islandPerimeter(vector<vector<int>> & grid)
{
    int perimeter=0;

    if(grid.empty())
    {
        return perimeter;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            if(grid[row][column]==1)
            {
                if(isOnBoard(rows, columns, row-1, column))
                {
                    if(grid[row-1][column]==0)
                    {
                        perimeter++;
                    }
                }
                else
                {
                    perimeter++;
                }

                if(isOnBoard(rows, columns, row+1, column))
                {
                    if(grid[row+1][column]==0)
                    {
                        perimeter++;
                    }
                }
                else
                {
                    perimeter++;
                }

                if(isOnBoard(rows, columns, row, column-1))
                {
                    if(grid[row][column-1]==0)
                    {
                        perimeter++;
                    }
                }
                else
                {
                    perimeter++;
                }

                if(isOnBoard(rows, columns, row, column+1))
                {
                    if(grid[row][column+1]==0)
                    {
                        perimeter++;
                    }
                }
                else
                {
                    perimeter++;
                }
            }
        }
    }

    return perimeter;
}