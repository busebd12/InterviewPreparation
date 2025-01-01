#include <vector>
using namespace std;

/*
Solution 1: Recursion.

Time complexity: O(4^n)
Space complexity: O(n)
*/

class Solution
{
    private:
        const int MOD=1e9 + 7;
    
    public:
        int numTilings(int n)
        {
            int result=0;

            int spotsInFirstRow=n;

            int spotsInSecondRow=n;

            result=helper(spotsInFirstRow, spotsInSecondRow);

            return result;
        }

        int helper(int spotsInFirstRow, int spotsInSecondRow)
        {
            if(spotsInFirstRow==0 and spotsInSecondRow==0)
            {
                return 1;
            }

            if(spotsInFirstRow < 0 or spotsInSecondRow < 0)
            {
                return 0;
            }

            int subproblemSolution=0;

            if(spotsInFirstRow==spotsInSecondRow)
            {
                int placeVerticalDomino=helper(spotsInFirstRow - 1, spotsInSecondRow - 1) % MOD;

                int placeHorizontalDominoInBothRows=helper(spotsInFirstRow - 2, spotsInSecondRow - 2) % MOD;

                int placeTromino=helper(spotsInFirstRow - 2, spotsInSecondRow - 1) % MOD;

                int placeInvertedTromino=helper(spotsInFirstRow - 1, spotsInSecondRow - 2) % MOD;

                subproblemSolution=(placeVerticalDomino + placeHorizontalDominoInBothRows + placeTromino + placeInvertedTromino) % MOD;
            }
            else if(spotsInFirstRow > spotsInSecondRow)
            {
                int placeVerticalDomino=helper(spotsInFirstRow - 1, spotsInSecondRow - 1) % MOD;

                int placeTromino=helper(spotsInFirstRow - 2, spotsInSecondRow - 1) % MOD;

                subproblemSolution=(placeHorizontalDomino + placeTromino) % MOD;
            }
            else if(spotsInFirstRow < spotsInSecondRow)
            {
                int placeVerticalDomino=helper(spotsInFirstRow - 1, spotsInSecondRow - 1) % MOD;

                int placeInvertedTromino=helper(spotsInFirstRow - 1, spotsInSecondRow - 2) % MOD;

                subproblemSolution=(placeVerticalDomino + placeInvertedTromino) % MOD;
            }

            subproblemSolution=subproblemSolution % MOD;

            return subproblemSolution;
        }
};


/*
Solution 2: Recursion + memoization

Time complexity: O(n^2)
Space complexity: O(n^2)
*/

class Solution
{
    private:
        const int MOD=1e9 + 7;

        vector<vector<long>> memo;
    
    public:
        int numTilings(int n)
        {
            int result=0;

            long spotsInFirstRow=n;

            long spotsInSecondRow=n;

            memo.resize(n + 1, vector<long>(n + 1, -1));

            result=helper(spotsInFirstRow, spotsInSecondRow);

            return result;
        }

        int helper(long spotsInFirstRow, long spotsInSecondRow)
        {
            if(spotsInFirstRow==0 and spotsInSecondRow==0)
            {
                return 1;
            }

            if(spotsInFirstRow < 0 or spotsInSecondRow < 0)
            {
                return 0;
            }

            if(memo[spotsInFirstRow][spotsInSecondRow]!=-1)
            {
                return memo[spotsInFirstRow][spotsInSecondRow];
            }

            long subproblemSolution=0;

            if(spotsInFirstRow==spotsInSecondRow)
            {
                long placeVerticalDomino=helper(spotsInFirstRow - 1, spotsInSecondRow - 1) % MOD;

                long placeHorizontalDominoInBothRows=helper(spotsInFirstRow - 2, spotsInSecondRow - 2) % MOD;

                long placeTromino=helper(spotsInFirstRow - 2, spotsInSecondRow - 1) % MOD;

                long placeInvertedTromino=helper(spotsInFirstRow - 1, spotsInSecondRow - 2) % MOD;

                subproblemSolution=(placeVerticalDomino + placeHorizontalDominoInBothRows + placeTromino + placeInvertedTromino) % MOD;
            }
            else if(spotsInFirstRow > spotsInSecondRow)
            {
                long placeVerticalDomino=helper(spotsInFirstRow - 1, spotsInSecondRow - 1) % MOD;

                long placeTromino=helper(spotsInFirstRow - 2, spotsInSecondRow - 1) % MOD;

                subproblemSolution=(placeVerticalDomino + placeTromino) % MOD;
            }
            else if(spotsInFirstRow < spotsInSecondRow)
            {
                long placeVerticalDomino=helper(spotsInFirstRow - 1, spotsInSecondRow - 1) % MOD;

                long placeInvertedTromino=helper(spotsInFirstRow - 1, spotsInSecondRow - 2) % MOD;

                subproblemSolution=(placeVerticalDomino + placeInvertedTromino) % MOD;
            }

            subproblemSolution=subproblemSolution % MOD;

            memo[spotsInFirstRow][spotsInSecondRow]=subproblemSolution;

            return subproblemSolution;
        }
};