#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. The idea is to perform breadth-first search from all of the land points instead of the water points.
 * To accomplish this, we place all of the land points in a queue and perform breadth-first search from each of
 * them. The final "level" that breadth-first search is able to explore is our answer. We make use of a
 * std::vector<std::vector<bool>> visited to make sure we don't visit places on the grid more than once.
 *
 * Time complexity: O(n * n) [where n is the number of rows and columns in the grid]
 * Space complexity: O(n * n)
 *
 *
 * 2. Also, a breadth-first approach. Here, as we peform breadth-first search, we update the 0 cells in the grid
 * with their distance from the respective 1 cell. Then, after breadth-first search has completed, we iterate through
 * the grid and find the max distance.
 *
 * Time complexity: O(n * n) [where n is the number of rows and columns in the grid]
 * Space complexity: O(1)
 */

class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        int maxDistance(std::vector<std::vector<int>> & grid)
        {
            int rows=int(grid.size());

            int columns=rows;

            std::queue<std::pair<int, int>> Q;

            std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        Q.emplace(std::make_pair(row, column));

                        visited[row][column]=true;
                    }
                }
            }

            int level=-1;

            while(!Q.empty())
            {
                int qSize=int(Q.size());

                for(int count=0;count<qSize;count++)
                {
                    auto current=Q.front();

                    int currentRow=current.first;

                    int currentColumn=current.second;

                    Q.pop();

                    std::array<std::pair<int, int>, 4> directions={{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};

                    for(const auto & direction : directions)
                    {
                        int nextRow=currentRow + direction.first;

                        int nextColumn=currentColumn + direction.second;

                        if(onGrid(rows, columns, nextRow, nextColumn))
                        {
                            if(grid[nextRow][nextColumn]==0 && !visited[nextRow][nextColumn])
                            {
                                visited[nextRow][nextColumn]=true;

                                Q.emplace(std::make_pair(nextRow, nextColumn));
                            }
                        }
                    }
                }

                level++;
            }

            return level <= 0 ? -1 : level;
        }
};

class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        int maxDistance(std::vector<std::vector<int>> & grid)
        {
            int rows=int(grid.size());

            int columns=rows;

            std::queue<std::pair<int, int>> Q;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        Q.emplace(std::make_pair(row, column));

                        grid[row][column]=-1;
                    }
                }
            }

            int level=1;

            while(!Q.empty())
            {
                int qSize=int(Q.size());

                for(int count=0;count<qSize;count++)
                {
                    auto current=Q.front();

                    int currentRow=current.first;

                    int currentColumn=current.second;

                    Q.pop();

                    std::array<std::pair<int, int>, 4> directions={{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};

                    for(const auto & direction : directions)
                    {
                        int nextRow=currentRow + direction.first;

                        int nextColumn=currentColumn + direction.second;

                        if(onGrid(rows, columns, nextRow, nextColumn))
                        {
                            if(grid[nextRow][nextColumn]==0)
                            {
                                Q.emplace(std::make_pair(nextRow, nextColumn));

                                grid[nextRow][nextColumn]=level;
                            }
                        }
                    }
                }

                level++;
            }

            int maxDistance=0;

            for(const auto & row : grid)
            {
                for(auto & element : row)
                {
                    if(element!=-1)
                    {
                        maxDistance=std::max(maxDistance, element);
                    }
                }
            }

            return maxDistance==0 ? -1 : maxDistance;
        }
};
