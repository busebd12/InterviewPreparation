#include <algorithm>
#include <array>
#include <vector>

/*
Solution: Depth-first search + backtracking

Time complexity: O(4^(rows * columns))
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    public:
        int dfs(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            int amount=grid[row][column];

            //Set this cell's gold amount to zero to say we have viisted this cell already and to ensure that we don't visit it again in the future
            grid[row][column]=0;
            
            int subproblemSolution=0;

            //For each up, down, left, and right adjacent cell, recursively explore the grid
            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=row + rowOffset;
                
                int nextColumn=column + columnOffset;
                
                bool isValid=((nextRow < rows && nextRow >= 0) && (nextColumn < columns && nextColumn >= 0));
                
                if(isValid==true && grid[nextRow][nextColumn]!=0)
                {
                    int next=dfs(grid, rows, columns, nextRow, nextColumn);
                    
                    subproblemSolution=max(subproblemSolution, next);
                }
            }
            
            //Reset the current cell's gold amount
            grid[row][column]=amount;
            
            //Add the current cell's gold amount to the current path
            subproblemSolution+=amount;
            
            return subproblemSolution;
        }

        int getMaximumGold(vector<vector<int>> & grid)
        {
            int result=0;
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //Only perform DFS from cells that have a positive gold amount
                    if(grid[row][column]!=0)
                    {
                        int gold=dfs(grid, rows, columns, row, column);
                        
                        result=max(result, gold);
                    }
                }
            }
            
            return result;
        }
};