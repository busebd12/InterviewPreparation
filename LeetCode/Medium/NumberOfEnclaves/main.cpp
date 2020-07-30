#include <array>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

/*
 * Solutions:
 *
 * 1. If we view the grid as an undirected graph, then this problem amounts to counting the connected components which
 * do not touch the border. We use recursion + depth-first search to explore the grid from each 1 and utilize
 * a std::vector<std::vector<bool>> visited to make sure we don't visit repeated spots. Note: this solution receives
 * a TLE (time limit exceeded) when submitted.
 *
 * Time complexity: O(rows^2 * columns^2)
 * Space complexity: O(rows * columns)
 *
 * 2. We use the Flood Fill algorithm to replace all 1's connected to 1's on the borders with zeros. Then, we simply
 * count the remaining 1's. These are the 1's that cannot reach the border. We do this recursively.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 3. Iterative version of the second solution.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 4. Flood Fill via breadth-first search.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 */

class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >=0 && row < rows) && (column >=0 && column < columns));
        }

        void dfs(std::vector<std::vector<int>> & A, std::vector<std::vector<bool>> & visited, int rows, int columns, int row, int column, bool & reachedBoundary)
        {
            if(row==0 || row==rows-1 || column==0 || column==columns-1)
            {
                reachedBoundary=true;
            }

            visited[row][column]=true;

            std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

            for(const auto & direction : directions)
            {
                int nextRow=row + direction.first;

                int nextColumn=column + direction.second;

                if(onGrid(rows, columns, nextRow, nextColumn))
                {
                    if(A[nextRow][nextColumn]==1 && !visited[nextRow][nextColumn])
                    {
                        dfs(A, visited, rows, columns, nextRow, nextColumn, reachedBoundary);
                    }
                }
            }
        }

        int numEnclaves(std::vector<std::vector<int>> & A)
        {
            if(A.empty())
            {
                return 0;
            }

            int result=0;

            int rows=int(A.size());

            int columns=int(A[0].size());

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if((row > 0 && row < rows-1) || (column > 0 && column < columns-1))
                    {
                        if(A[row][column]==1)
                        {
                            bool reachedBoundary=false;

                            std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

                            dfs(A, visited, rows, columns, row, column, reachedBoundary);

                            if(!reachedBoundary)
                            {
                                result++;
                            }
                        }
                    }
                }
            }

            return result;
        }
};

class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >=0 && row < rows) && (column >=0 && column < columns));
        }

        void floodFill(std::vector<std::vector<int>> & A, int rows, int columns, int row, int column)
        {
            A[row][column]=0;

            std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

            for(const auto & direction : directions)
            {
                int nextRow=row + direction.first;

                int nextColumn=column + direction.second;

                if(onGrid(rows, columns, nextRow, nextColumn))
                {
                    if(A[nextRow][nextColumn] > 0)
                    {
                        floodFill(A, rows, columns, nextRow, nextColumn);
                    }
                }
            }
        }

        int numEnclaves(std::vector<std::vector<int>> & A)
        {
            if(A.empty())
            {
                return 0;
            }

            int result=0;

            int rows=int(A.size());

            int columns=int(A[0].size());

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(((row * column)==0) || (row==rows-1) || column==columns-1)
                    {
                        if(A[row][column]==1)
                        {
                            floodFill(A, rows, columns, row, column);
                        }
                    }
                }
            }

            for(const auto & row : A)
            {
                for(const auto & element : row)
                {
                    if(element==1)
                    {
                        result++;
                    }
                }
            }

            return result;
        }
};

class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >=0 && row < rows) && (column >=0 && column < columns));
        }

        void floodFill(std::vector<std::vector<int>> & A, int rows, int columns, int row, int column)
        {
            std::stack<std::pair<int, int>> stk;

            stk.push(std::make_pair(row, column));

            while(!stk.empty())
            {
                auto current=stk.top();

                stk.pop();

                int currentRow=current.first;

                int currentColumn=current.second;

                A[currentRow][currentColumn]=0;

                std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

                for(const auto & direction : directions)
                {
                    int nextRow=currentRow + direction.first;

                    int nextColumn=currentColumn + direction.second;

                    if(onGrid(rows, columns, nextRow, nextColumn))
                    {
                        if(A[nextRow][nextColumn] > 0)
                        {
                            stk.push(std::make_pair(nextRow, nextColumn));
                        }
                    }
                }
            }
        }

        int numEnclaves(std::vector<std::vector<int>> & A)
        {
            if(A.empty())
            {
                return 0;
            }

            int result=0;

            int rows=int(A.size());

            int columns=int(A[0].size());

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(((row * column)==0) || (row==rows-1) || column==columns-1)
                    {
                        if(A[row][column]==1)
                        {
                            floodFill(A, rows, columns, row, column);
                        }
                    }
                }
            }

            for(const auto & row : A)
            {
                for(const auto & element : row)
                {
                    if(element==1)
                    {
                        result++;
                    }
                }
            }

            return result;
        }
};


class Solution
{
    public:
        bool onGrid(int rows, int columns, int row, int column)
        {
            return ((row >=0 && row < rows) && (column >=0 && column < columns));
        }

        void floodFill(std::vector<std::vector<int>> & A, int rows, int columns, int row, int column)
        {
            std::queue<std::pair<int, int>> Q;

            Q.emplace(std::make_pair(row, column));

            while(!Q.empty())
            {
                auto current=Q.front();

                Q.pop();

                int currentRow=current.first;

                int currentColumn=current.second;

                A[currentRow][currentColumn]=0;

                std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

                for(const auto & direction : directions)
                {
                    int nextRow=currentRow + direction.first;

                    int nextColumn=currentColumn + direction.second;

                    if(onGrid(rows, columns, nextRow, nextColumn))
                    {
                        if(A[nextRow][nextColumn] > 0)
                        {
                            Q.emplace(std::make_pair(nextRow, nextColumn));
                        }
                    }
                }
            }
        }

        int numEnclaves(std::vector<std::vector<int>> & A)
        {
            if(A.empty())
            {
                return 0;
            }

            int result=0;

            int rows=int(A.size());

            int columns=int(A[0].size());

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(((row * column)==0) || (row==rows-1) || column==columns-1)
                    {
                        if(A[row][column]==1)
                        {
                            floodFill(A, rows, columns, row, column);
                        }
                    }
                }
            }

            for(const auto & row : A)
            {
                for(const auto & element : row)
                {
                    if(element==1)
                    {
                        result++;
                    }
                }
            }

            return result;
        }
};