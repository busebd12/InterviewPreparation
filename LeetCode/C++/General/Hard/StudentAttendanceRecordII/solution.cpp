#include <vector>
using namespace std;

/*
Solution 1: recursion.

Time complexity: O(2^n)
Space complexity: O(n)
*/

class Solution
{
    private:
        const int MOD=1e9 + 7;
    
    public:
        int checkRecord(int n)
        {
            int result=0;

            int absent=0;

            int late=0;

            int present=0;

            int day=0;

            result=helper(n, absent, late, present, day);

            return result;
        }

        int helper(int n, int absent, int late, int present, int day)
        {
            if(day==n)
            {
                return 1;
            }

            int subproblemSolution=0;

            int ontime=helper(n, absent, 0, present + 1, day + 1);

            subproblemSolution+=ontime;

            subproblemSolution=subproblemSolution % MOD;

            if(absent==0)
            {
                int isAbsent=helper(n, 1, 0, 0, day + 1);

                subproblemSolution+=isAbsent;

                subproblemSolution=subproblemSolution % MOD;
            }

            if(late < 2)
            {
                int isLate=helper(n, absent, late + 1, present + 1, day + 1);

                subproblemSolution+=isLate;

                subproblemSolution=subproblemSolution % MOD;
            }

            return subproblemSolution;
        }
};

/*
Solution 1: recursion + memoization.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    private:
        const int MOD=1e9 + 7;
    
    public:
        int checkRecord(int n)
        {
            int result=0;

            int absent=0;

            int late=0;

            int present=0;

            int day=0;

            vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

            result=helper(memo, n, absent, late, present, day);

            return result;
        }

        int helper(vector<vector<vector<int>>> & memo, int n, int absent, int late, int present, int day)
        {
            if(day==n)
            {
                return 1;
            }

            if(memo[day][absent][late]!=-1)
            {
                return memo[day][absent][late];
            }

            int subproblemSolution=0;

            int ontime=helper(memo, n, absent, 0, present + 1, day + 1);

            subproblemSolution+=ontime;

            subproblemSolution=subproblemSolution % MOD;

            if(absent < 1)
            {
                int isAbsent=helper(memo, n, 1, 0, 0, day + 1);

                subproblemSolution+=isAbsent;

                subproblemSolution=subproblemSolution % MOD;
            }

            if(late < 2)
            {
                int isLate=helper(memo, n, absent, late + 1, present + 1, day + 1);

                subproblemSolution+=isLate;

                subproblemSolution=subproblemSolution % MOD;
            }

            memo[day][absent][late]=subproblemSolution;

            return subproblemSolution;
        }
};