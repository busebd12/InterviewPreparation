#include <iostream>
#include <queue>
#include <vector>

/*
 * Solutions:
 *
 * 1. Breadth-first search + std::vector<std::vector<bool>> visited to keep track of points in the grid that
 * we have already explored.
 *
 * Time complexity: O(n * n) [where n is the number of rows and columns in the grid]
 * Space complexity: O(n * n)
 *
 *
 * 2. Similar to the first solution except that we change any 0's in the grid to 1's once we have visited them
 * to prevent exploring the same points again.
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

        int shortestPathBinaryMatrix(std::vector<std::vector<int>> & grid)
        {
            int rows=int(grid.size());

            int columns=rows;

            std::queue<std::pair<int, int>> Q;

            std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

            if(grid[0][0]==0)
            {
                Q.emplace(std::make_pair(0, 0));

                visited[0][0]=true;
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

                    if(currentRow==rows-1 && currentColumn==columns-1)
                    {
                        return level;
                    }

                    std::array<std::pair<int, int>, 8> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}};

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

            return -1;
        }
};

class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        int shortestPathBinaryMatrix(std::vector<std::vector<int>> & grid)
        {
            int rows=int(grid.size());

            int columns=rows;

            std::queue<std::pair<int, int>> Q;

            if(grid[0][0]==0)
            {
                Q.emplace(std::make_pair(0, 0));

                grid[0][0]=1;
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

                    if(currentRow==rows-1 && currentColumn==columns-1)
                    {
                        return level;
                    }

                    std::array<std::pair<int, int>, 8> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}};

                    for(const auto & direction : directions)
                    {
                        int nextRow=currentRow + direction.first;

                        int nextColumn=currentColumn + direction.second;

                        if(onGrid(rows, columns, nextRow, nextColumn))
                        {
                            if(grid[nextRow][nextColumn]==0)
                            {
                                grid[nextRow][nextColumn]=1;

                                Q.emplace(std::make_pair(nextRow, nextColumn));
                            }
                        }
                    }
                }

                level++;
            }

            return -1;
        }
};