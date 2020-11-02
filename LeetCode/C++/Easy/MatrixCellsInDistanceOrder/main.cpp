#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Approach: we traverse the grid in a breadth-first manner, starting with the given row, r0, and column, c0.
 * For each point, we mark it as visited, add it to our vector<vector<int>> result and then enqueue surrounding
 * points, if they are on the board.
 *
 * Time complexity: O(number of rows * number of columns)
 * Space complexity: O(number of rows * number of columns)
 */

bool isOnBoard(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >=0 && column < columns));
}

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
{
    queue<pair<int, int>> Q;

    vector<vector<int>> points;

    vector<vector<bool>> used(R, vector<bool>(C, false));

    Q.emplace(make_pair(r0, c0));

    used[r0][c0]=true;

    while(!Q.empty())
    {
        pair<int, int> current=Q.front();

        Q.pop();

        points.emplace_back(vector<int>{current.first, current.second});

        if(isOnBoard(R, C, current.first-1, current.second))
        {
            if(!used[current.first-1][current.second])
            {
                Q.emplace(make_pair(current.first-1, current.second));

                used[current.first-1][current.second]=true;
            }
        }

        if(isOnBoard(R, C, current.first+1, current.second))
        {
            if(!used[current.first+1][current.second])
            {
                Q.emplace(make_pair(current.first+1, current.second));

                used[current.first+1][current.second]=true;
            }
        }

        if(isOnBoard(R, C, current.first, current.second-1))
        {
            if(!used[current.first][current.second-1])
            {
                Q.emplace(make_pair(current.first, current.second-1));

                used[current.first][current.second-1]=true;
            }
        }

        if(isOnBoard(R, C, current.first, current.second+1))
        {
            if(!used[current.first][current.second+1])
            {
                Q.emplace(make_pair(current.first, current.second+1));

                used[current.first][current.second+1]=true;
            }
        }
    }

    return points;
}