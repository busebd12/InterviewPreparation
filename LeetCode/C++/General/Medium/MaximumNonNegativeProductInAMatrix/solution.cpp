#include <algorithm>
#include <array>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 2> directions={{{1, 0}, {0, 1}}};

        const long INF=numeric_limits<long>::min();

    public:
        int maxProductPath(vector<vector<int>> & grid)
        {
            long result=-1;

            int rows=grid.size();

            int columns=grid[0].size();

            const int MOD=1e9 + 7;

            int row=0;

            int column=0;

            vector<vector<pair<long, long>>> memo(rows + 1, vector<pair<long, long>>(columns + 1, make_pair(INF, INF)));

            pair<long, long> p=dfs(grid, memo, rows, columns, row, column);

            result=max(p.first, p.second);

            if(result < 0)
            {
                return -1;
            }

            result=result % MOD;

            return static_cast<int>(result);
        }

        pair<long, long> dfs(vector<vector<int>> & grid, vector<vector<pair<long, long>>> & memo, int rows, int columns, int row, int column)
        {
            if(row==rows - 1 and column==columns - 1)
            {
                return make_pair((long)grid[row][column], (long)grid[row][column]);
            }

            if(memo[row][column].first!=INF and memo[row][column].second!=INF)
            {
                return memo[row][column];
            }

            pair<long, long> subproblemSolution;

            long subproblemMax=numeric_limits<long>::min();

            long subproblemMin=numeric_limits<long>::max();

            long current=grid[row][column];

            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=row + rowOffset;

                int nextColumn=column + columnOffset;
                
                bool onGrid=((nextRow < rows) and (nextColumn < columns));

                if(onGrid==true)
                {
                    pair<long, long> temp=dfs(grid, memo, rows, columns, nextRow, nextColumn);

                    subproblemMax=max(subproblemMax, max(temp.first * current, temp.second * current));

                    subproblemMin=min(subproblemMin, min(temp.first * current, temp.second * current));
                }
            }

            subproblemSolution=make_pair(subproblemMax, subproblemMin);

            memo[row][column]=subproblemSolution;

            return subproblemSolution;
        }
};