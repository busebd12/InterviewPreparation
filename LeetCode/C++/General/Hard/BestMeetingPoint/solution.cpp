#include <algorithm>
#include <array>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: breadth-first search from each "house" and calculate the spot with the least total distance travelled from each "house".

Time complexity: O((rows)^2 * (columns)^2)
Space complexity: O(rows + columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    public:
        int minTotalDistance(vector<vector<int>> & grid)
        {
            int result=numeric_limits<int>::max();

            int rows=grid.size();

            int columns=grid[0].size();

            vector<pair<int, int>> homeCoordinates;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        homeCoordinates.emplace_back(row, column);
                    }
                }
            }

            vector<vector<int>> distances(rows, vector<int>(columns, 0));

            for(auto & [row, column] : homeCoordinates)
            {
                bfs(distances, rows, columns, row, column);
            }

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    result=min(result, distances[row][column]);
                }
            }

            return result;
        }

        void bfs(vector<vector<int>> & distances, int rows, int columns, int row, int column)
        {
            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            visited[row][column]=true;

            deque<pair<int, int>> queue;

            queue.emplace_back(row, column);

            int level=1;

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

                        bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                        if(isValid==true and visited[nextRow][nextColumn]==false)
                        {
                            visited[nextRow][nextColumn]=true;

                            distances[nextRow][nextColumn]+=level;

                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }

                level+=1;
            }
        }
};

/*
Solution 2: find the midpoint and calculate the distance from all houses to that midpoint.

Time complexity: O((rows * columns) + (c log c) + r) [where c is the number of '1' columns and r is the number of '1' rows]
Space complexity: O(r + c)
*/

class Solution
{
    public:
        int minTotalDistance(vector<vector<int>>& grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<int> homeRows;

            vector<int> homeColumns;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        homeRows.push_back(row);

                        homeColumns.push_back(column);
                    }
                }
            }
            
            sort(homeColumns.begin(), homeColumns.end());

            int middleRow=homeRows[homeRows.size() / 2];

            int middleColumn=homeColumns[homeColumns.size() / 2];

            for(int i=0;i<homeRows.size();i++)
            {
                result+=abs(homeRows[i] - middleRow);

                result+=abs(homeColumns[i] - middleColumn);
            }
            
            return result;
        }
};