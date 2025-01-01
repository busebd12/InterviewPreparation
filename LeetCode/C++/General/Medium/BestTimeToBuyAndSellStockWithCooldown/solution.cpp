#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursion. At each index we have three choices to make: skip the current day because of cooldown
from selling the previous day, buy the stock, or sell the stock we previously bought. The solution will be
the maximum value out of these three choices.

Time complexity: O(2^n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxProfit(vector<int> & prices)
        {
            int result=0;

            int n=prices.size();

            int buy=1;

            int index=0;

            result=helper(prices, n, buy, index);

            return result;
        }

        int helper(vector<int> & prices, int n, int buy, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            int subproblemSolution=0;

            int cooldown=helper(prices, n, buy, index + 1);

            int transaction=0;

            if(buy==1)
            {
                transaction=-prices[index] + helper(prices, n, 0, index + 1);
            }
            else
            {
                transaction=prices[index] + helper(prices, n, 1, index + 2);
            }

            subproblemSolution=max(cooldown, transaction);

            return subproblemSolution;
        }
};

/*
Solution 2: Same thought process as the first solution except that we use a vector<int> & memo to store answers to subproblems that were already solved.
This way, when we reach the same subproblem as before, we can simply get the answer from the memo cache instead of re-solving it.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxProfit(vector<int> & prices)
        {
            int result=0;

            int n=prices.size();

            vector<vector<int>> memo(n + 1, vector<int>(2, -1));

            int buy=1;

            int index=0;

            result=helper(prices, memo, n, buy, index);

            return result;
        }

        int helper(vector<int> & prices, vector<vector<int>> & memo, int n, int buy, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo[index][buy]!=-1)
            {
                return memo[index][buy];
            }

            int subproblemSolution=0;

            int cooldown=helper(prices, memo, n, buy, index + 1);

            int transaction=0;

            if(buy==1)
            {
                transaction=-prices[index] + helper(prices, memo, n, 0, index + 1);
            }
            else
            {
                transaction=prices[index] + helper(prices, memo, n, 1, index + 2);
            }

            subproblemSolution=max(cooldown, transaction);

            memo[index][buy]=subproblemSolution;

            return subproblemSolution;
        }
};