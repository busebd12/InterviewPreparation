#include <array>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: Breadth-first search.

Time complexity: O(rows * columns) [where rows is the number of rows in the maze and columns is the number of columns in the matrix]
Space complexity: O(row * columns)
*/

class Solution
{
    public:
        bool isValid(vector<vector<int>> & maze, int rows, int columns, int row, int column)
        {
            if(row < 0 || row > rows - 1)
            {
                return false;
            }
            
            if(column < 0 || column > columns - 1)
            {
                return false;
            }
            
            if(maze[row][column]==1)
            {
                return false;
            }
            
            return true;
        }
    
        bool hasPath(vector<vector<int>> & maze, vector<int> & start, vector<int> & destination)
        {
            int rows=maze.size();
            
            int columns=maze[0].size();
            
            vector<vector<bool>> visited(rows, vector<bool>(columns, false));
            
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
            deque<pair<int, int>> queue;
            
            queue.emplace_back(start[0], start[1]);
            
            visited[start[0]][start[1]]=true;
            
            while(!queue.empty())
            {
                auto qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();
                    
                    queue.pop_front();
                    
                    if(currentRow==destination[0] && currentColumn==destination[1])
                    {
                        return true;
                    }
                    
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow;
                        
                        int nextColumn=currentColumn;
                        
                        while(isValid(maze, rows, columns, nextRow + rowOffset, nextColumn + columnOffset))
                        {
                            nextRow+=rowOffset;
                            
                            nextColumn+=columnOffset;
                        }
                        
                        if(visited[nextRow][nextColumn]==false)
                        {
                            visited[nextRow][nextColumn]=true;
                            
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }
            }
            
            return false;
        }
};

/*
Solution 1: Depth-first search.

Time complexity: O(rows * columns) [where rows is the number of rows in the maze and columns is the number of columns in the matrix]
Space complexity: O(row * columns)
*/

class Solution
{
    public:
        bool isValid(vector<vector<int>> & maze, int rows, int columns, int row, int column)
        {
            if(row < 0 || row > rows - 1)
            {
                return false;
            }
            
            if(column < 0 || column > columns - 1)
            {
                return false;
            }
            
            if(maze[row][column]==1)
            {
                return false;
            }
            
            return true;
        }
    
        bool hasPath(vector<vector<int>> & maze, vector<int> & start, vector<int> & destination)
        {
            int rows=maze.size();
            
            int columns=maze[0].size();
            
            vector<vector<bool>> visited(rows, vector<bool>(columns, false));
            
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
            deque<pair<int, int>> stack;
            
            stack.emplace_back(start[0], start[1]);
            
            visited[start[0]][start[1]]=true;
            
            while(!stack.empty())
            {
                auto [currentRow, currentColumn]=stack.back();
                    
                stack.pop_back();

                if(currentRow==destination[0] && currentColumn==destination[1])
                {
                    return true;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow;

                    int nextColumn=currentColumn;

                    while(isValid(maze, rows, columns, nextRow + rowOffset, nextColumn + columnOffset))
                    {
                        nextRow+=rowOffset;

                        nextColumn+=columnOffset;
                    }

                    if(visited[nextRow][nextColumn]==false)
                    {
                        visited[nextRow][nextColumn]=true;

                        stack.emplace_back(nextRow, nextColumn);
                    }
                }
            }
            
            return false;
        }
};