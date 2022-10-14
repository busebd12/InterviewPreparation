#include <array>
#include <deque>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: breadth-first search.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}};
    
        int rows=0;
    
        int columns=0;
    
    public:
        int shortestDistance(vector<vector<int>> & maze, vector<int> & start, vector<int> & destination)
        {
            int result=-1;
            
            this->rows=maze.size();
            
            this->columns=maze[0].size();
            
            const int INF=numeric_limits<int>::max();
            
            vector<vector<int>> distances(rows, vector<int>(columns, INF));
            
            distances[start[0]][start[1]]=0;
            
            bfs(maze, distances, start);
            
            if(distances[destination[0]][destination[1]]!=INF)
            {
                result=distances[destination[0]][destination[1]];
            }
            
            return result;
        }
    
        void bfs(vector<vector<int>> & maze, vector<vector<int>> & distances, vector<int> & start)
        {
            deque<tuple<int, int, int>> queue;
            
            queue.emplace_back(start[0], start[1], 0);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn, currentEmptySpacesTravelled]=queue.front();
                    
                    queue.pop_front();
                    
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow;
                        
                        int nextColumn=currentColumn;
                        
                        int emptySpacesTravelled=getEmptySpacesTravelled(maze, nextRow, nextColumn, rowOffset, columnOffset);
                        
                        int newDistance=currentEmptySpacesTravelled + emptySpacesTravelled;
                        
                        if(newDistance < distances[nextRow][nextColumn])
                        {
                            distances[nextRow][nextColumn]=newDistance;
                            
                            queue.emplace_back(nextRow, nextColumn, newDistance);
                        }
                    }
                }
            }
        }
    
        int getEmptySpacesTravelled(vector<vector<int>> & maze, int & row, int & column, int rowOffset, int columnOffset)
        {
            int emptySpacesTravelled=0;
            
            while(isValid(maze, row + rowOffset, column + columnOffset)==true)
            {
                emptySpacesTravelled+=1;
                
                row+=rowOffset;
                
                column+=columnOffset;
            }
            
            return emptySpacesTravelled;
        }
    
        bool isValid(vector<vector<int>> & maze, int row, int column)
        {
            bool invalidRow=(row < 0 or row >= rows);
            
            bool invalidColumn=(column < 0 or column >= columns);
            
            if(invalidRow==true or invalidColumn==true)
            {
                return false;
            }
            
            if(maze[row][column]==1)
            {
                return false;
            }
            
            return true;
        }
};