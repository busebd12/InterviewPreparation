#include <array>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int longestIncreasingPath(vector<vector<int>> & matrix)
        {
            int result=0;

            int rows=matrix.size();

            int columns=matrix[0].size();
            
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
            vector<vector<int>> outdegree(rows, vector<int>(columns, 0));

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;
                        
                        int nextColumn=column + columnOffset;
                        
                        bool isValid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));
                        
                        //If an adjacent cell's value is greater than the current cells, then the outdegree of the current cell is increased
                        //The outdegree for a cell is saying how many edges are there connecting this cell to adjancent cells that have greater value
                        if(isValid==true && matrix[nextRow][nextColumn] > matrix[row][column])
                        {
                            outdegree[row][column]+=1;
                        }
                    }
                }
            }
            
            deque<pair<int, int>> queue;
            
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(outdegree[row][column]==0)
                    {
                        queue.emplace_back(row, column);
                    }
                }
            }
            
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

                        //If an adjacent cell's value is less than the current cells value
                        if(isValid==true && matrix[nextRow][nextColumn] < matrix[currentRow][currentColumn])
                        {
                            //Decrement the outdegree for the adjacent cell
                            //This represents moving from a higher number in the path to a previous lower value in the path
                            //AKA walking the path in reverse
                            outdegree[nextRow][nextColumn]-=1;

                            //If the outdegree of the adjacent cell reaches zero, add it to the queue to continue the topological sort
                            if(outdegree[nextRow][nextColumn]==0)
                            {
                                queue.emplace_back(nextRow, nextColumn);
                            }
                        }
                    }
                }
                
                result+=1;
            }

            return result;
        }
};