#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void dfs(vector<vector<int>> & matrix, vector<vector<bool>> & visited, int level, int row, int column)
{
    if(row < 0 || row >= matrix.size() || column < 0 || column >= matrix[0].size() || matrix[row][column] < level || visited[row][column])
    {
        return;
    }

    visited[row][column]=true;

    level=matrix[row][column];

    dfs(matrix, visited, level, row-1, column);

    dfs(matrix, visited, level, row+1, column);

    dfs(matrix, visited, level, row, column-1);

    dfs(matrix, visited, level, row, column+1);
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>> & matrix)
{
    vector<pair<int, int>> coordinates;

    if(matrix.empty() || matrix[0].empty())
    {
        return coordinates;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    vector<vector<bool>> pacific(rows, vector<bool>(columns));

    vector<vector<bool>> atlantic(rows, vector<bool>(columns));

    for(int i=0;i<rows;++i)
    {
        dfs(matrix, pacific, numeric_limits<int>::min(), i, 0);

        dfs(matrix, atlantic, numeric_limits<int>::min(), i, columns-1);
    }

    for(int j=0;j<columns;++j)
    {
        dfs(matrix, pacific, numeric_limits<int>::min(), 0, j);

        dfs(matrix, atlantic, numeric_limits<int>::min(), rows-1, j);
    }

    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<columns;++j)
        {
            if(pacific[i][j] && atlantic[i][j])
            {
                coordinates.emplace_back(make_pair(i, j));
            }
        }
    }

    return coordinates;
}