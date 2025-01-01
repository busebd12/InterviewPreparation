#include <vector>
using namespace std;

/*
Solution 1: recursive depth-first traversal.
Submission result: Time Limit Exceeded.
*/

class Solution
{
    public:
        int numberOfPaths(vector<vector<int>> & grid, int k)
        {
            int result=0;

            const int MOD=1e9 + 7;

            int rows=grid.size();

            int columns=grid[0].size();

            int row=0;

            int column=0;

            int sum=0;

            result=helper(grid, rows, columns, MOD, k, row, column, sum) % MOD;

            return result;
        }

        int helper(vector<vector<int>> & grid, int rows, int columns, const int MOD, int k, int row, int column, int sum)
        {
            sum+=grid[row][column];
            
            if((row==rows-1 and column==columns-1))
            {   
                return (sum % k)==0;
            }

            int subproblemSolution=0;

            int down=0;

            if(row + 1 < rows)
            {
                down=(helper(grid, rows, columns, MOD, k, row + 1, column, sum) % MOD);
            }

            int right=0;

            if(column + 1 < columns)
            {
                right=(helper(grid, rows, columns, MOD, k, row, column + 1, sum) % MOD);
            }

            subproblemSolution+=down;

            subproblemSolution%=MOD;

            subproblemSolution+=right;

            subproblemSolution%=MOD;

            return subproblemSolution;
        }
};

/*
Solution 2: recursive depth-first traversal + memoization.
Submission result: accepted.
Time complexity: O(rows * columns * k)
Space complexity: O(rows * columns * k)
*/

class Solution
{
    public:
        int numberOfPaths(vector<vector<int>> & grid, int k)
        {
            int result=0;

            const int MOD=1e9 + 7;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<vector<vector<int>>> memo(rows, vector<vector<int>>(columns, vector<int>(k, -1)));

            int row=0;

            int column=0;

            int sum=0;

            result=helper(grid, memo, rows, columns, MOD, k, row, column, sum) % MOD;

            return result;
        }

        int helper(vector<vector<int>> & grid, vector<vector<vector<int>>> & memo, int rows, int columns, const int MOD, int k, int row, int column, int sum)
        {
            sum+=grid[row][column];
            
            if((row==rows-1 and column==columns-1))
            {   
                return (sum % k)==0;
            }

            if(memo[row][column][sum % k]!=-1)
            {
                return memo[row][column][sum % k];
            }

            int subproblemSolution=0;

            int down=0;

            if(row + 1 < rows)
            {
                down=(helper(grid, memo, rows, columns, MOD, k, row + 1, column, sum) % MOD);
            }

            int right=0;

            if(column + 1 < columns)
            {
                right=(helper(grid, memo, rows, columns, MOD, k, row, column + 1, sum) % MOD);
            }

            subproblemSolution+=down;

            subproblemSolution%=MOD;

            subproblemSolution+=right;

            subproblemSolution%=MOD;

            memo[row][column][sum % k]=subproblemSolution;

            return subproblemSolution;
        }
};