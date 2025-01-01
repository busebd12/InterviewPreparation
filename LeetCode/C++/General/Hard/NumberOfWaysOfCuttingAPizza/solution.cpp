#include <vector>
using namespace std;

/*
Solutions inspired by these resources:

1) https://www.youtube.com/watch?v=NU4hYLVprGg
2) https://www.youtube.com/watch?v=RFyJMlpA-pY
3) https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/solutions/623732/java-c-python-dp-prefixsum-in-matrix-clean-code/
*/

/*
Solution 1: prefix sums + recursion. Note, this soution receives Time Limit Exceeded when executed.
*/

class Solution
{
    private:
        int rows;
        
        int columns;

        const int MOD=1e9 + 7;

        vector<vector<int>> prefixSums;
    
    public:
        int ways(vector<string> & pizza, int k)
        {
            int result=0;
            
            rows=pizza.size();

            columns=pizza[0].size();

            prefixSums.resize(rows + 1, vector<int>(columns + 1, 0));

            calculatePrefixSums(pizza);

            int cuts=k - 1;

            int startRow=0;

            int startColumn=0;

            result=helper(startRow, startColumn, cuts);

            return result;
        }

        void calculatePrefixSums(vector<string> & pizza)
        {
            for(int row=rows-1;row>=0;row--)
            {
                for(int column=columns-1;column>=0;column--)
                {
                    prefixSums[row][column]=prefixSums[row + 1][column] + prefixSums[row][column + 1] - prefixSums[row + 1][column + 1] + (pizza[row][column]=='A' ? 1 : 0);
                }
            }
        }

        int helper(int row, int column, int cuts)
        {
            if(prefixSums[row][column]==0)
            {
                return 0;
            }

            if(cuts==0)
            {
                return 1;
            }

            int subproblemSolution=0;

            for(int nextRow=row+1;nextRow<rows;nextRow++)
            {
                int applesAboveCut=prefixSums[row][column] - prefixSums[nextRow][column];

                if(applesAboveCut > 0)
                {
                    subproblemSolution+=helper(nextRow, column, cuts - 1);

                    subproblemSolution=subproblemSolution % MOD;
                }
            }

            for(int nextColumn=column+1;nextColumn<columns;nextColumn++)
            {
                int applesAboveCut=prefixSums[row][column] - prefixSums[row][nextColumn];

                if(applesAboveCut > 0)
                {
                    subproblemSolution+=helper(row, nextColumn, cuts - 1);

                    subproblemSolution=subproblemSolution % MOD;
                }
            }

            subproblemSolution=subproblemSolution % MOD;

            return subproblemSolution;
        }
};

/*
Solution 2: prefix sums + recursion + memoization.

Time complexity: O(rows * columns * k * (rows + columns))
Space complexity: O(rows * columns * k)
*/

class Solution
{
    private:
        int rows;
        
        int columns;

        const int MOD=1e9 + 7;

        vector<vector<int>> prefixSums;

        vector<vector<vector<int>>> memo;
    
    public:
        int ways(vector<string> & pizza, int k)
        {
            int result=0;
            
            rows=pizza.size();

            columns=pizza[0].size();

            prefixSums.resize(rows + 1, vector<int>(columns + 1, 0));

            calculatePrefixSums(pizza);

            memo.resize(rows + 1, vector<vector<int>>(columns + 1, vector<int>(k, -1)));

            int cuts=k - 1;

            int startRow=0;

            int startColumn=0;

            result=helper(startRow, startColumn, cuts);

            return result;
        }

        void calculatePrefixSums(vector<string> & pizza)
        {
            for(int row=rows-1;row>=0;row--)
            {
                for(int column=columns-1;column>=0;column--)
                {
                    prefixSums[row][column]=prefixSums[row + 1][column] + prefixSums[row][column + 1] - prefixSums[row + 1][column + 1] + (pizza[row][column]=='A' ? 1 : 0);
                }
            }
        }

        int helper(int row, int column, int cuts)
        {
            if(prefixSums[row][column]==0)
            {
                return 0;
            }

            if(cuts==0)
            {
                return 1;
            }

            if(memo[row][column][cuts]!=-1)
            {
                return memo[row][column][cuts];
            }

            int subproblemSolution=0;

            for(int nextRow=row+1;nextRow<rows;nextRow++)
            {
                int applesAboveCut=prefixSums[row][column] - prefixSums[nextRow][column];

                if(applesAboveCut > 0)
                {
                    subproblemSolution+=helper(nextRow, column, cuts - 1);

                    subproblemSolution=subproblemSolution % MOD;
                }
            }

            for(int nextColumn=column+1;nextColumn<columns;nextColumn++)
            {
                int applesAboveCut=prefixSums[row][column] - prefixSums[row][nextColumn];

                if(applesAboveCut > 0)
                {
                    subproblemSolution+=helper(row, nextColumn, cuts - 1);

                    subproblemSolution=subproblemSolution % MOD;
                }
            }

            subproblemSolution=subproblemSolution % MOD;

            memo[row][column][cuts]=subproblemSolution;

            return subproblemSolution;
        }
};