#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns) [where rows is the number of rows in the grid and columns in the number of columns in the grid]
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        const char WALL='W';
            
        const char ENEMY='E';

        const char EMPTY='0';
    
    public:
        int maxKilledEnemies(vector<vector<char>> & grid)
        {
            int result=0;
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            vector<vector<int>> rowLeft(rows, vector<int>(columns, 0));
            
            for(int row=0;row<rows;row++)
            {
                int enemies=0;
                
                for(int column=0;column<columns;column++)
                {
                    char c=grid[row][column];
                    
                    if(c==WALL)
                    {
                        enemies=0;
                    }
                    else if(c==ENEMY)
                    {
                        enemies+=1;
                    }
                    else
                    {
                        rowLeft[row][column]=enemies;
                    }
                }
            }
            
            vector<vector<int>> rowRight(rows, vector<int>(columns, 0));
            
            for(int row=0;row<rows;row++)
            {
                int enemies=0;
                
                for(int column=columns-1;column>=0;column--)
                {
                    char c=grid[row][column];
                    
                    if(c==WALL)
                    {
                        enemies=0;
                    }
                    else if(c==ENEMY)
                    {
                        enemies+=1;
                    }
                    else
                    {
                        rowRight[row][column]=enemies;
                    }
                }
            }
            
            vector<vector<int>> columnDown(rows, vector<int>(columns, 0));
            
            for(int column=0;column<columns;column++)
            {
                int enemies=0;
                
                for(int row=0;row<rows;row++)
                {
                    char c=grid[row][column];
                    
                    if(c==WALL)
                    {
                        enemies=0;
                    }
                    else if(c==ENEMY)
                    {
                        enemies+=1;
                    }
                    else
                    {
                        columnDown[row][column]=enemies;
                    }
                }
            }
            
            vector<vector<int>> columnUp(rows, vector<int>(columns, 0));
            
            for(int column=0;column<columns;column++)
            {
                int enemies=0;
                
                for(int row=rows-1;row>=0;row--)
                {
                    char c=grid[row][column];
                    
                    if(c==WALL)
                    {
                        enemies=0;
                    }
                    else if(c==ENEMY)
                    {
                        enemies+=1;
                    }
                    else
                    {
                        columnUp[row][column]=enemies;
                    }
                }
            }
            
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==EMPTY)
                    {
                        int killed=rowLeft[row][column] + rowRight[row][column] + columnUp[row][column] + columnDown[row][column];
                        
                        result=max(result, killed);
                    }
                }
            }
            
            return result;
        }
};