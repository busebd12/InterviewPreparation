#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursion with knapsack concept.

Time complexity: O(2^n) [where n is the length of present and future]
Space complexity: O(2^n)
*/

class Solution
{
    public:
        int maximumProfit(vector<int> & present, vector<int> & future, int budget)
        {
            int result=0;

            int n=present.size();

            int index=0;

            result=helper(present, future, n, budget, index);

            return result;
        }

        int helper(vector<int> & present, vector<int> & future, int n, int budget, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            int subproblemSolution=0;

            int takeStock=0;

            if(budget >= present[index])
            {
                int profit=future[index] - present[index];

                takeStock=profit + helper(present, future, n, budget - present[index], index + 1);
            }

            int skipStock=helper(present, future, n, budget, index + 1);

            subproblemSolution=max(takeStock, skipStock);

            return subproblemSolution;
        }
};

/*
Solution 2: Recursion + knapsack concept + memoization

Time complexity: O(n * budget) [where n is the length of present and future]
Space complexity: O(n * budget)
*/

class Solution
{
    public:
        int maximumProfit(vector<int> & present, vector<int> & future, int budget)
        {
            int result=0;

            int n=present.size();

            vector<vector<int>> memo(n + 1, vector<int>(budget + 1, -1));

            int index=0;

            result=helper(present, future, memo, n, budget, index);

            return result;
        }

        int helper(vector<int> & present, vector<int> & future, vector<vector<int>> & memo, int n, int budget, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo[index][budget]!=-1)
            {
                return memo[index][budget];
            }

            int subproblemSolution=0;

            int takeStock=0;

            if(budget >= present[index])
            {
                int profit=future[index] - present[index];

                takeStock=profit + helper(present, future, memo, n, budget - present[index], index + 1);
            }

            int skipStock=helper(present, future, memo, n, budget, index + 1);

            subproblemSolution=max(takeStock, skipStock);

            memo[index][budget]=subproblemSolution;

            return subproblemSolution;
        }
};