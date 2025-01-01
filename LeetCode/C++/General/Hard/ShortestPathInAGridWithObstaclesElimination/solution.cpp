#include <array>
#include <deque>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns * k)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int shortestPath(vector<vector<int>> & grid, int k)
        {
            int rows=grid.size();

            int columns=grid[0].size();

            unordered_set<string> seen;

            seen.emplace(to_string(0) + '$' + to_string(0) + '$' + to_string(k));

            deque<tuple<int, int, int>> queue;

            queue.emplace_back(0, 0, k);

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            int steps=0;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [row, column, obstaclesWeCanClear]=queue.front();

                    queue.pop_front();

                    if(row==rows - 1 and column==columns - 1)
                    {
                        return steps;
                    }

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;

                        int nextColumn=column + columnOffset;

                        bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                        if(isValid==true)
                        {
                            int remainingObstaclesWeCanClear=obstaclesWeCanClear - grid[nextRow][nextColumn];
                            
                            if(remainingObstaclesWeCanClear >= 0)
                            {
                                //IMPORTANT: need to store the value remaining for k since our state depends on three things: row, column, and k
                                string nextState=to_string(nextRow) + '$' + to_string(nextColumn) + '$' + to_string(remainingObstaclesWeCanClear);

                                if(seen.find(nextState)==seen.end())
                                {
                                    seen.insert(nextState);

                                    queue.emplace_back(nextRow, nextColumn, remainingObstaclesWeCanClear);
                                }
                            }
                        }
                    }
                }

                steps+=1;
            }

            return -1;
        }
};