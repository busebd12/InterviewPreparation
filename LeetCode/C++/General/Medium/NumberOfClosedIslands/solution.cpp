#include <array>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: flood fill + iterative depth-first search.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    
    public:
        int closedIsland(vector<vector<int>> & grid)
        {
            int result=0;
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            //Iterate through top and bottom rows
            for(int column=0;column<columns;column++)
            {
                //if we find a 0 in the top row, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to convert all the zeros into ones
                if(grid[0][column]==0)
                {
                    floodFill(grid, rows, columns, 0, column);
                }
                
                //if we find a 0 in the bottom row, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to conver all the zeros into ones
                if(grid[rows - 1][column]==0)
                {
                    floodFill(grid, rows, columns, rows - 1, column);
                }
            }
            
            //Iterate through the first and last columns
            for(int row=0;row<rows;row++)
            {
                
                //if we find a 0 in the first column, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to convert all the zeros into ones
                if(grid[row][0]==0)
                {
                    floodFill(grid, rows, columns, row, 0);
                }
                
                //if we find a 0 in the last column, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to convert all the zeros into ones
                if(grid[row][columns - 1]==0)
                {
                    floodFill(grid, rows, columns, row, columns - 1);
                }
            }
            
            //Now that we have used flood fill to remove all islands that aren't closed, any islands left will be closed.
            //So, for each remaining zero in the grid, we simply use dfs to visit all the zeros 4-directionally connected
            //to it and increment our result after we are done.
            //If we view the grid as a graph, this is the same thing as counting all the connected components in said graph
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==0 and row > 0 and row < rows - 1 and column > 0 and column < columns - 1)
                    {
                        dfs(grid, rows, columns, row, column);
                        
                        result+=1;
                    }
                }
            }
            
            return result;
        }
    
        void floodFill(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            grid[row][column]=1;
            
            deque<pair<int, int>> stack;
            
            stack.emplace_back(row, column);
            
            while(!stack.empty())
            {
                auto [currentRow, currentColumn]=stack.back();
                
                stack.pop_back();
                
                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;
                    
                    int nextColumn=currentColumn + columnOffset;
                    
                    if(isValid(rows, columns, nextRow, nextColumn)==true and grid[nextRow][nextColumn]==0)
                    {
                        grid[nextRow][nextColumn]=1;
                        
                        stack.emplace_back(nextRow, nextColumn);
                    }
                }
            }
        }
    
        void dfs(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {   
            deque<pair<int, int>> stack;
            
            grid[row][column]=2;
            
            stack.emplace_back(row, column);
            
            while(!stack.empty())
            {
                auto [currentRow, currentColumn]=stack.back();
                
                stack.pop_back();
                
                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;
                    
                    int nextColumn=currentColumn + columnOffset;
                    
                    if(isValid(rows, columns, nextRow, nextColumn)==true and grid[nextRow][nextColumn]==0)
                    {
                        grid[nextRow][nextColumn]=2;
                        
                        stack.emplace_back(nextRow, nextColumn);
                    }
                }
            }
        }
    
        bool isValid(int rows, int columns, int row, int column)
        {
            bool validRow=(row >= 0 and row < rows);
            
            bool validColumn=(column >= 0 and column < columns);
            
            return (validRow==true and validColumn==true);
        }
};

/*
Solution 2: flood fill + iterative breadth-first search.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    
    public:
        int closedIsland(vector<vector<int>> & grid)
        {
            int result=0;
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            //Iterate through top and bottom rows
            for(int column=0;column<columns;column++)
            {
                //if we find a 0 in the top row, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to convert all the zeros into ones
                if(grid[0][column]==0)
                {
                    floodFill(grid, rows, columns, 0, column);
                }
                
                //if we find a 0 in the bottom row, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to conver all the zeros into ones
                if(grid[rows - 1][column]==0)
                {
                    floodFill(grid, rows, columns, rows - 1, column);
                }
            }
            
            //Iterate through the first and last columns
            for(int row=0;row<rows;row++)
            {
                
                //if we find a 0 in the first column, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to convert all the zeros into ones
                if(grid[row][0]==0)
                {
                    floodFill(grid, rows, columns, row, 0);
                }
                
                //if we find a 0 in the last column, then all zeros 4-directionally connected to this zero form an island that is not closed,
                //so we will use the flood fill algorithm to convert all the zeros into ones
                if(grid[row][columns - 1]==0)
                {
                    floodFill(grid, rows, columns, row, columns - 1);
                }
            }
            
            //Now that we have used flood fill to remove all islands that aren't closed, any islands left will be closed.
            //So, for each remaining zero in the grid, we simply use dfs to visit all the zeros 4-directionally connected to it
            //and increment our result after we are done.
            //If we view the grid as a graph, this is the same thing as counting all the connected components in said graph
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==0 and row > 0 and row < rows - 1 and column > 0 and column < columns - 1)
                    {
                        dfs(grid, rows, columns, row, column);
                        
                        result+=1;
                    }
                }
            }
            
            return result;
        }
    
        void floodFill(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            grid[row][column]=1;
            
            deque<pair<int, int>> queue;
            
            queue.emplace_back(row, column);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();
                
                    queue.pop_front();

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;

                        int nextColumn=currentColumn + columnOffset;

                        if(isValid(rows, columns, nextRow, nextColumn)==true and grid[nextRow][nextColumn]==0)
                        {
                            grid[nextRow][nextColumn]=1;

                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }
            }
        }
    
        void dfs(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {   
            deque<pair<int, int>> queue;
            
            grid[row][column]=2;
            
            queue.emplace_back(row, column);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();
                
                    queue.pop_front();

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;

                        int nextColumn=currentColumn + columnOffset;

                        if(isValid(rows, columns, nextRow, nextColumn)==true and grid[nextRow][nextColumn]==0)
                        {
                            grid[nextRow][nextColumn]=2;

                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }
            }
        }
    
        bool isValid(int rows, int columns, int row, int column)
        {
            bool validRow=(row >= 0 and row < rows);
            
            bool validColumn=(column >= 0 and column < columns);
            
            return (validRow==true and validColumn==true);
        }
};