#include <array>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired by this poost --> https://leetcode.com/problems/escape-the-spreading-fire/solutions/3129761/c-bfs-simple/

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    public:
        int maximumMinutes(vector<vector<int>> & grid)
        {
            int result=-1;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<vector<int>> distanceFireHasToTravel=getDistanceFireHasToTravel(grid, rows, columns);

            int low=0;

            int high=1e9;

            while(low <= high)
            {
                int waitTime=(low + (high - low)/2);

                if(canReachSafeHouse(grid, distanceFireHasToTravel, rows, columns, waitTime)==true)
                {
                    result=waitTime;

                    low=waitTime + 1;
                }
                else
                {
                    high=waitTime - 1;
                }
            }

            return result;
        }

        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >= 0 and row < rows) and (column >= 0 and column < columns));
        }

        vector<vector<int>> getDistanceFireHasToTravel(vector<vector<int>> grid, int rows, int columns)
        {
            vector<vector<int>> distanceFireHasToTravel(rows, vector<int>(columns, -1));

            deque<pair<int, int>> queue;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        queue.emplace_back(row, column);
                    }
                }
            }

            int distance=0;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [row, column]=queue.front();

                    queue.pop_front();

                    distanceFireHasToTravel[row][column]=distance;

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;

                        int nextColumn=column + columnOffset;

                        if(onGrid(rows, columns, nextRow, nextColumn)==true and grid[nextRow][nextColumn]==0 and distanceFireHasToTravel[nextRow][nextColumn]==-1)
                        {
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }

                if(!queue.empty())
                {
                    distance+=1;
                }
            }

            return distanceFireHasToTravel;
        }

        bool canReachSafeHouse(vector<vector<int>> & grid, vector<vector<int>> & distanceFireHasToTravel, int rows, int columns, int waitTime)
        {
            int steps=waitTime;

            int startRow=0;

            int startColumn=0;

            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            deque<pair<int, int>> queue;

            queue.emplace_back(startRow, startColumn);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [row, column]=queue.front();

                    queue.pop_front();

                    if(visited[row][column]==true)
                    {
                        continue;
                    }

                    visited[row][column]=true;

                    if(row==rows-1 and column==columns-1)
                    {
                        return steps <= distanceFireHasToTravel[row][column] or distanceFireHasToTravel[row][column]==-1;
                    }

                    if(distanceFireHasToTravel[row][column]!=-1 and distanceFireHasToTravel[row][column] <= steps)
                    {
                        continue;
                    }

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;

                        int nextColumn=column + columnOffset;

                        if(onGrid(rows, columns, nextRow, nextColumn)==true and grid[nextRow][nextColumn]==0)
                        {
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }

                if(!queue.empty())
                {
                    steps+=1;
                }
            }

            return false;
        }
};