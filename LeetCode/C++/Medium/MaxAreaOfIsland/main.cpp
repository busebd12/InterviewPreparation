#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. As we iterate through the grid, when we come across a 1, we use depth-first search to explore the surrounding
 * area to find the max area. We use a std::vector<std::vector<bool>> visited to make sure we don't re-visit spots
 * we have previously visited. This solution recieved Time Limit Exceeded when submitted.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 2. Similar to the first solution, except we prune the number of spots in the grid that we recursively explore by only
 * exploring surrounding grid points that are 1's. This solution recieved Time Limit Exceeded when submitted.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 3. Similar to the second solution except that mark each spot that we have visited on the grid with a 2. This way,
 * we can use the grid itself as a substitute for the visited vector of vectors that we used in the previous two solutions.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 4. Iterative version of the third solution.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 5. Iterative, breadth-first traversal.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 */

bool onGrid(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int dfs(std::vector<std::vector<int>> & grid, std::vector<std::vector<bool>> & visited, int rows, int columns, int row, int column)
{
    if(!onGrid(rows, columns, row, column))
    {
        return 0;
    }

    if(visited[row][column])
    {
        return 0;
    }

    if(!grid[row][column])
    {
        return 0;
    }

    visited[row][column]=true;

    int up=dfs(grid, visited, rows, columns, row-1, column);

    int down=dfs(grid, visited, rows, columns, row+1, column);

    int left=dfs(grid, visited, rows, columns, row, column-1);

    int right=dfs(grid, visited, rows, columns, row, column+1);

    int subproblem=1 + up + down + left + right;

    return subproblem;
}

int maxAreaOfIsland(std::vector<std::vector<int>> & grid)
{
    int result=0;

    if(grid.empty())
    {
        return result;
    }

    auto rows=grid.size();

    auto columns=grid[0].size();

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column])
            {
                std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

                result=std::max(result, dfs(grid, visited, rows, columns, row, column));
            }
        }
    }

    return result;
}

bool onGrid(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int dfs(std::vector<std::vector<int>> & grid, std::vector<std::vector<bool>> & visited, int rows, int columns, int row, int column)
{
    if(visited[row][column])
    {
        return 0;
    }

    if(!grid[row][column])
    {
        return 0;
    }

    visited[row][column]=true;

    std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    int subproblem=1;

    for(const auto & direction : directions)
    {
        int nextRow=row + direction.first;

        int nextColumn=column + direction.second;

        if(onGrid(rows, columns, nextRow, nextColumn) && grid[nextRow][nextColumn])
        {
            subproblem+=dfs(grid, visited, rows, columns, nextRow, nextColumn);
        }
    }

    return subproblem;
}

int maxAreaOfIsland(std::vector<std::vector<int>> & grid)
{
    int result=0;

    if(grid.empty())
    {
        return result;
    }

    auto rows=grid.size();

    auto columns=grid[0].size();

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column])
            {
                std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

                result=std::max(result, dfs(grid, visited, rows, columns, row, column));
            }
        }
    }

    return result;
}

bool onGrid(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int dfs(std::vector<std::vector<int>> & grid, int rows, int columns, int row, int column)
{
    grid[row][column]=2;

    std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    int subproblem=1;

    for(const auto & direction : directions)
    {
        int nextRow=row + direction.first;

        int nextColumn=column + direction.second;

        if(onGrid(rows, columns, nextRow, nextColumn) && grid[nextRow][nextColumn]==1)
        {
            subproblem+=dfs(grid, rows, columns, nextRow, nextColumn);
        }
    }

    return subproblem;
}

int maxAreaOfIsland(std::vector<std::vector<int>> & grid)
{
    int result=0;

    if(grid.empty())
    {
        return result;
    }

    auto rows=grid.size();

    auto columns=grid[0].size();

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column])
            {
                result=std::max(result, dfs(grid, rows, columns, row, column));
            }
        }
    }

    return result;
}

bool onGrid(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int dfs(std::vector<std::vector<int>> & grid, int rows, int columns, int row, int column)
{
    std::stack<std::pair<int, int>> stk;

    stk.emplace(std::make_pair(row, column));

    grid[row][column]=2;

    int subproblem=1;

    while(!stk.empty())
    {
        auto current=stk.top();

        stk.pop();

        std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        for(const auto & direction : directions)
        {
            int nextRow=current.first + direction.first;

            int nextColumn=current.second + direction.second;

            if(onGrid(rows, columns, nextRow, nextColumn) && grid[nextRow][nextColumn]==1)
            {
                subproblem+=1;

                grid[nextRow][nextColumn]=2;

                stk.push(std::make_pair(nextRow, nextColumn));
            }
        }
    }

    return subproblem;
}

int maxAreaOfIsland(std::vector<std::vector<int>> & grid)
{
    int result=0;

    if(grid.empty())
    {
        return result;
    }

    auto rows=grid.size();

    auto columns=grid[0].size();

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column])
            {
                result=std::max(result, dfs(grid, rows, columns, row, column));
            }
        }
    }

    return result;
}

bool onGrid(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

int bfs(std::vector<std::vector<int>> & grid, int rows, int columns, int row, int column)
{
    int subproblem=1;

    std::queue<std::pair<int, int>> Q;

    Q.emplace(std::make_pair(row, column));

    grid[row][column]=2;

    while(!Q.empty())
    {
        auto current=Q.front();

        Q.pop();

        std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        for(const auto & direction : directions)
        {
            auto nextRow=current.first + direction.first;

            auto nextColumn=current.second + direction.second;

            if(onGrid(rows, columns, nextRow, nextColumn) && grid[nextRow][nextColumn]==1)
            {
                subproblem+=1;

                grid[nextRow][nextColumn]=2;

                Q.emplace(std::make_pair(nextRow, nextColumn));
            }
        }
    }

    return subproblem;
}

int maxAreaOfIsland(std::vector<std::vector<int>> & grid)
{
    int result=0;

    if(grid.empty())
    {
        return result;
    }

    auto rows=grid.size();

    auto columns=grid[0].size();

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]==1)
            {
                result=std::max(result, bfs(grid, rows, columns, row, column));
            }
        }
    }

    return result;
}