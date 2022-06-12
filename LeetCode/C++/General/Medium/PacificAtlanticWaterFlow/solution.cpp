#include <array>
#include <deque>
#include <utility>
#include <vector>

/*
Solution: see comments.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns);
*/

class Solution
{
    public:
        void bfs(vector<vector<int>> & heights, deque<pair<int, int>> & queue, vector<vector<bool>> & visited, int rows, int columns)
        {
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
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
                        
                        bool isValid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));
                        
                        if(isValid==true && heights[nextRow][nextColumn] >= heights[currentRow][currentColumn] && visited[nextRow][nextColumn]==false)
                        {
                            visited[nextRow][nextColumn]=true;
                            
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }
            }
        }
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>> & heights)
        {
            vector<vector<int>> result;
            
            int rows=heights.size();
            
            int columns=heights[0].size();
            
            //Mark all the places in heights that the pacific ocean can reach
            vector<vector<bool>> pacificVisited(rows, vector<bool>(columns, false));
            
            //Mark all the places in heights that the atlantic ocean can reach
            vector<vector<bool>> atlanticVisited(rows, vector<bool>(columns, false));
            
            //Queues used for breadth-first search
            deque<pair<int, int>> pacificQueue;
            
            deque<pair<int, int>> atlanticQueue;
            
            //Add the top and bottom borders to their respecitve queues and mark them as visited
            for(int column=0;column<columns;column++)
            {
                pacificQueue.emplace_back(0, column);
                
                pacificVisited[0][column]=true;
                
                atlanticQueue.emplace_back(rows-1, column);
                
                atlanticVisited[rows - 1][column]=true;
            }
            
            //Add the left and right borders to the queue and mark them as visited
            for(int row=0;row<rows;row++)
            {
                pacificQueue.emplace_back(row, 0);
                
                pacificVisited[row][0]=true;
                
                atlanticQueue.emplace_back(row, columns - 1);
                
                atlanticVisited[row][columns - 1]=true;
            }
            
            //Do breadth-first flood fill from the ocean
            bfs(heights, pacificQueue, pacificVisited, rows, columns);
            
            bfs(heights, atlanticQueue, atlanticVisited, rows, columns);
            
            //Iterate through atlanticVisited and pacificVisited
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //If both oceans are able to reach this (row, column), then this spot can send rain water to both oceans
                    if(atlanticVisited[row][column]==true && pacificVisited[row][column]==true)
                    {
                        //Add (row, column) to the result
                        result.emplace_back(vector<int>{row, column});
                    }
                }
            }
            
            return result;
        }
};