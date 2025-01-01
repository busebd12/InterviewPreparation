#include <algorithm>
#include <array>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: Dijkstra's algorithm + breadth-first search + maximum heap

Time complexity: O((rows * columns) * (log(rows * columns)))
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int maximumMinimumPath(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            result=grid[0][0];

            visited[0][0]=true;

            auto comparator=[] (tuple<int, int, int> & lhs, tuple<int, int, int> & rhs)
            {
                return get<2>(lhs) < get<2>(rhs);
            };

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comparator)> maxHeap(comparator);

            maxHeap.emplace(0, 0, grid[0][0]);

            while(!maxHeap.empty())
            {
                auto [row, column, score]=maxHeap.top();

                maxHeap.pop();

                result=min(result, score);

                if(row==rows - 1 and column==columns - 1)
                {
                    break;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=row + rowOffset;

                    int nextColumn=column + columnOffset;

                    bool valid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                    if(valid==true and visited[nextRow][nextColumn]==false)
                    {
                        visited[nextRow][nextColumn]=true;

                        maxHeap.emplace(nextRow, nextColumn, grid[nextRow][nextColumn]);
                    }
                }
            }

            return result;
        }
};

/*
Solution 2: Dijkstra's algorithm + breadth-first search + maximum heap

Time complexity: O((rows * columns) * (log(rows * columns)))
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int maximumMinimumPath(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            result=grid[0][0];

            auto comparator=[] (tuple<int, int, int> & lhs, tuple<int, int, int> & rhs)
            {
                return get<2>(lhs) < get<2>(rhs);
            };

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comparator)> maxHeap(comparator);

            maxHeap.emplace(0, 0, grid[0][0]);

            grid[0][0]=-1;

            while(!maxHeap.empty())
            {
                auto [row, column, score]=maxHeap.top();

                maxHeap.pop();

                result=min(result, score);

                if(row==rows - 1 and column==columns - 1)
                {
                    break;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=row + rowOffset;

                    int nextColumn=column + columnOffset;

                    bool valid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                    if(valid==true and grid[nextRow][nextColumn] >= 0)
                    {
                        maxHeap.emplace(nextRow, nextColumn, grid[nextRow][nextColumn]);
                        
                        grid[nextRow][nextColumn]=-1;
                    }
                }
            }

            return result;
        }
};