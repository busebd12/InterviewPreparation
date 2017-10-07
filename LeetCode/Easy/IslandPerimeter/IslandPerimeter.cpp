#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) 
{
    const size_t rows=grid.size();
    
    const size_t rowSize=grid[0].size();
    
    int perimeter=0;
    
    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<rowSize;++column)
        {
            if(grid[row][column]==1)
            {
                perimeter+=4;
                
                if(row > 0 && grid[row-1][column]==1)
                {
                    --perimeter;
                }
                
                if(row+1 < rows && grid[row+1][column]==1)
                {
                    --perimeter;
                }
                
                if(column > 0 && grid[row][column-1]==1)
                {
                    --perimeter;
                }
                
                if(column+1 < rowSize && grid[row][column+1]==1)
                {
                    --perimeter;
                }
            }
        }
    }
    
    return perimeter;
}