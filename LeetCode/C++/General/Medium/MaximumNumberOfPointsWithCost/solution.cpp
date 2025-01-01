#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursion + memoization. Note, this solution receives Time Limit Exceeded when executed.

Time complexity: O(rows * (columns)^2)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        long long maxPoints(vector<vector<int>> & points)
        {
            long long result=0;

            int rows=points.size();

            int columns=points[0].size();

            int row=0;

            int previousColumn=-1;

            vector<vector<long long>> memo(rows + 1, vector<long long>(columns + 1, -1));

            result=helper(points, memo, rows, columns, row, previousColumn);

            return result;
        }

        long long helper(vector<vector<int>> & points, vector<vector<long long>> & memo, int rows, int columns, int row, int previousColumn)
        {
            if(row >= rows)
            {
                return 0;
            }

            if(previousColumn!=-1 and memo[row][previousColumn]!=-1)
            {
                return memo[row][previousColumn];
            }

            long long subproblemSolution=0;

            for(int column=0;column<columns;column++)
            {
                long long chooseThisColumn=0;
                
                if(row==0)
                {
                    chooseThisColumn=points[row][column] + helper(points, memo, rows, columns, row + 1, column);

                    subproblemSolution=max(subproblemSolution, chooseThisColumn);
                }
                else
                {
                    chooseThisColumn=(points[row][column] - abs(previousColumn - column) + helper(points, memo, rows, columns, row + 1, column));

                    subproblemSolution=max(subproblemSolution, chooseThisColumn);
                }
            }

            if(previousColumn!=-1)
            {
                memo[row][previousColumn]=subproblemSolution;
            }

            return subproblemSolution;
        }
};

/*
Solution 2: based on these resources

1) https://www.youtube.com/watch?v=STEJHYc9rMw
2) https://leetcode.com/problems/maximum-number-of-points-with-cost/solutions/1345409/c-tle-accepted-tried-my-best-to-explain-with-comments/

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        long long maxPoints(vector<vector<int>> & points)
        {
            using ll=long long;
            
            ll result=0;

            int rows=points.size();

            int columns=points[0].size();

            vector<ll> previousRow(columns, 0);

            for(int column=0;column<columns;column++)
            {
                previousRow[column]=points[0][column];
            }

            for(int row=1;row<rows;row++)
            {
                vector<ll> left(columns, 0);

                left[0]=previousRow[0];

                for(int column=1;column<columns;column++)
                {
                    left[column]=max(left[column - 1] - 1, previousRow[column]);
                }

                vector<ll> right(columns, 0);

                right[columns - 1]=previousRow[columns - 1];

                for(int column=columns-2;column>=0;column--)
                {
                    right[column]=max(right[column + 1] - 1, previousRow[column]);
                }

                vector<ll> currentRow(columns, 0);

                for(int column=0;column<columns;column++)
                {
                    currentRow[column]=points[row][column] + max(left[column], right[column]);
                }

                previousRow=currentRow;
            }

            result=*(max_element(previousRow.begin(), previousRow.end()));

            return result;
        }
};