#include <deque>
#include <vector>
using namespace std;

/*
Solution: breadth-first search. See comments.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int getFood(vector<vector<char>> & grid)
        {
            int result=0;
            
            int rows=grid.size();
            
            int columns=grid[0].size();
            
            int startRow=-1;
            
            int startColumn=-1;
            
            //Find the starting point
            for(int row=0;row<rows;row++)
            {
                bool foundStart=false;
                
                for(int column=0;column<columns;column++)
                {
                    //If we've found the starting point
                    if(grid[row][column]=='*')
                    {
                        startRow=row;
                        
                        startColumn=column;
                        
                        foundStart=true;
                        
                        break;
                    }
                }
                
                if(foundStart==true)
                {
                    break;
                }
            }
            
            //Up, down, left and right directions
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
            //Keep track of which cells in the grid we have already visited
            vector<vector<bool>> visited(rows, vector<bool>(columns, false));
            
            //Mark the starting poitn as visited
            visited[startRow][startColumn]=true;
            
            //Queue used for breadth-first search
            deque<pair<int, int>> queue;
            
            //Add starting point to the queue
            queue.emplace_back(startRow, startColumn);
            
            //Do breadth-first search
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();
                    
                    queue.pop_front();
                    
                    //Yay, reached food! Now, we won't starve.
                    if(grid[currentRow][currentColumn]=='#')
                    {
                        return result;
                    }
                    
                    //Iterate through each direction: up, down, left right
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;
                        
                        int nextColumn=currentColumn + columnOffset;
                        
                        bool isValid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));
                        
                        //If we can visit the next cell
                        if(isValid==true && grid[nextRow][nextColumn]!='X' && visited[nextRow][nextColumn]==false)
                        {
                            //Mark the cell as visited
                            visited[nextRow][nextColumn]=true;
                            
                            //Add it to the queue
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }
                
                result+=1;
            }
            
            return -1;
        }
};