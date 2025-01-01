#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/profitable-schemes/solutions/3440392/c-3d-dp-with-recursion-memoization/
*/

class Solution
{
    private:
        vector<vector<vector<int>>> memo;

        const int MOD=1e9 + 7;
    
    public:
        int profitableSchemes(int n, int minProfit, vector<int> & group, vector<int> & profit)
        {
            int result=0;

            int g=group.size();

            int p=profit.size();

            int index=0;

            int members=0;

            int currentProfit=0;

            memo.resize(g + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

            result=helper(group, profit, g, n, minProfit, members, currentProfit, index);

            return result;
        }

        int helper(vector<int> & group, vector<int> & profit, int g, int n, int minProfit, int members, int currentProfit, int index)
        {
            if(index >= g)
            {
                return currentProfit >= minProfit;
            }

            if(memo[index][members][currentProfit]!=-1)
            {
                return memo[index][members][currentProfit];
            }

            int subproblemSolution=0;

            int skipCrime=helper(group, profit, g, n, minProfit, members, currentProfit, index + 1);

            skipCrime%=MOD;

            int commitCrime=0;

            if(members + group[index] <= n)
            {
                commitCrime=helper(group, profit, g, n, minProfit, members + group[index], min(minProfit, currentProfit + profit[index]), index + 1);
            }

            commitCrime%=MOD;

            subproblemSolution=(skipCrime + commitCrime) % MOD;

            memo[index][members][currentProfit]=subproblemSolution;

            return subproblemSolution;
        }
};