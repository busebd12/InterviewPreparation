#include <array>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <queue>

/*
 * Solutions:
 *
 * 1. Recursion + depth-first search. We iterate through the grid and any time we find a '1', we use depth-first search
 * to try to find as many other '1's as we can by moving up, down, left, and right. Since each '1' can be the start of
 * another island, we increment islands each time we find a one. We also use a std::vector<std::vector<bool>> used to
 * keep track of which '1's from the grid we have already visited so that we don't visit them more than once.
 *
 * Time complexity: O(rows * columns) [where rows is the number of rows in the grid and columns is the number of columns in the grid]
 * Space complexity: O(rows * columns)
 *
 * 2. Similar to the first solution except that we modify the grid by changing all necessary '1's to zeroes.
 * By doing this, we don't have to use a std::vector<std::vector<bool>> to keep track of which squares of the grid we
 * have previously visited.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 3. Iterative version of the first solution. Here, we use a stack to simulate the recursive stack.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 4. Iterative version of the second solution. Here, we use a stack to simulate the recursive stack.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 5. Breadth-first search using a queue. We also use a std::vector<std::vector<bool>> used to keep track of which '1's
 * from the grid we have already visited so that we don't visit them more than once.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 *
 * 6. Breadth-first search using a queue. We modify the grid in-place to make sure that we don't visited '1's repeatedly.
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(rows * columns)
 */

bool isValid(std::vector<std::vector<char>> & grid, std::vector<std::vector<bool>> & used, int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns) && grid[row][column]=='1' && !used[row][column]);
}

void dfs(std::vector<std::vector<char>> & grid, std::vector<std::vector<bool>> & used, int rows, int columns, int row, int column)
{
    used[row][column]=true;

    std::array<std::pair<int, int>, 4> directions={{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

    for(auto & direction : directions)
    {
        if(isValid(grid, used, rows, columns, row + direction.first, column + direction.second))
        {
            dfs(grid, used, rows, columns, row + direction.first, column + direction.second);
        }
    }
}

int numIslands(std::vector<std::vector<char>> & grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    std::vector<std::vector<bool>> used(rows, std::vector<bool>(columns, false));

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]=='1' && !used[row][column])
            {
                dfs(grid, used, rows, columns, row, column);

                islands++;
            }
        }
    }

    return islands;
}

bool isValid(std::vector<std::vector<char>> & grid, int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns) && grid[row][column]=='1');
}

void dfs(std::vector<std::vector<char>> & grid, int rows, int columns, int row, int column)
{
    grid[row][column]='0';

    std::array<std::pair<int, int>, 4> directions={{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

    for(auto & direction : directions)
    {
        if(isValid(grid, rows, columns, row + direction.first, column + direction.second))
        {
            dfs(grid, rows, columns, row + direction.first, column + direction.second);
        }
    }
}

int numIslands(std::vector<std::vector<char>> & grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]=='1')
            {
                dfs(grid, rows, columns, row, column);

                islands++;
            }
        }
    }

    return islands;
}

bool isValid(std::vector<std::vector<char>> & grid, std::vector<std::vector<bool>> & used, int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns) && grid[row][column]=='1' && !used[row][column]);
}

int numIslands(std::vector<std::vector<char>> & grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    std::vector<std::vector<bool>> used(rows, std::vector<bool>(columns, false));

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]=='1' && !used[row][column])
            {
                std::stack<std::pair<int, int>> stk;

                stk.push(std::make_pair(row, column));

                used[row][column]=true;

                while(!stk.empty())
                {
                    auto element=stk.top();

                    stk.pop();

                    std::array<std::pair<int, int>, 4> directions={{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

                    for(auto & direction : directions)
                    {
                        if(isValid(grid, used, rows, columns, element.first + direction.first, element.second + direction.second))
                        {
                            used[element.first + direction.first][element.second + direction.second]=true;

                            stk.push(std::make_pair(element.first + direction.first, element.second + direction.second));
                        }
                    }
                }

                islands++;
            }
        }
    }

    return islands;
}

bool isValid(std::vector<std::vector<char>> & grid, int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns) && grid[row][column]=='1');
}

int numIslands(std::vector<std::vector<char>> & grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]=='1')
            {
                std::stack<std::pair<int, int>> stk;

                stk.push(std::make_pair(row, column));

                grid[row][column]='0';

                while(!stk.empty())
                {
                    auto element=stk.top();

                    stk.pop();

                    std::array<std::pair<int, int>, 4> directions={{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

                    for(auto & direction : directions)
                    {
                        if(isValid(grid, rows, columns, element.first + direction.first, element.second + direction.second))
                        {
                            grid[element.first + direction.first][element.second + direction.second]='0';

                            stk.push(std::make_pair(element.first + direction.first, element.second + direction.second));
                        }
                    }
                }

                islands++;
            }
        }
    }

    return islands;
}

bool isValid(std::vector<std::vector<char>> & grid, std::vector<std::vector<bool>> & used, int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns) && grid[row][column]=='1' && !used[row][column]);
}

int numIslands(std::vector<std::vector<char>> & grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    std::vector<std::vector<bool>> used(rows, std::vector<bool>(columns, false));

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]=='1' && !used[row][column])
            {
                std::queue<std::pair<int, int>> Q;

                Q.push(std::make_pair(row, column));

                used[row][column]=true;

                while(!Q.empty())
                {
                    auto element=Q.front();

                    Q.pop();

                    std::array<std::pair<int, int>, 4> directions={{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

                    for(auto & direction : directions)
                    {
                        if(isValid(grid, used, rows, columns, element.first + direction.first, element.second + direction.second))
                        {
                            used[element.first + direction.first][element.second + direction.second]=true;

                            Q.push(std::make_pair(element.first + direction.first, element.second + direction.second));
                        }
                    }
                }

                islands++;
            }
        }
    }

    return islands;
}

bool isValid(std::vector<std::vector<char>> & grid, int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns) && grid[row][column]=='1');
}

int numIslands(std::vector<std::vector<char>> & grid)
{
    int islands=0;

    if(grid.empty())
    {
        return islands;
    }

    int rows=int(grid.size());

    int columns=int(grid[0].size());

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(grid[row][column]=='1')
            {
                std::queue<std::pair<int, int>> Q;

                Q.push(std::make_pair(row, column));

                grid[row][column]='0';

                while(!Q.empty())
                {
                    auto element=Q.front();

                    Q.pop();

                    std::array<std::pair<int, int>, 4> directions={{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

                    for(auto & direction : directions)
                    {
                        if(isValid(grid, rows, columns, element.first + direction.first, element.second + direction.second))
                        {
                            grid[element.first + direction.first][element.second + direction.second]='0';

                            Q.push(std::make_pair(element.first + direction.first, element.second + direction.second));
                        }
                    }
                }

                islands++;
            }
        }
    }

    return islands;
}