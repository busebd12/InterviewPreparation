#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
    public:
        int maxProfit(vector<int> & prices, int fee)
        {
            int result=0;

            int n=prices.size();

            bool boughtStocksPreviously=false;

            int index=0;

            result=helper(prices, n, fee, boughtStocksPreviously, index);

            return result;
        }

        int helper(vector<int> & prices, int n, int fee, bool boughtStocksPreviously, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            int subproblemSolution=numeric_limits<int>::min();

            int doNothing=helper(prices, n, fee, boughtStocksPreviously, index + 1);

            subproblemSolution=doNothing;

            if(boughtStocksPreviously==true)
            {
                int sell=(prices[index] + helper(prices, n, fee, false, index + 1)) - fee;

                subproblemSolution=max(subproblemSolution, sell);
            }
            else
            {
                int buy=-prices[index] + helper(prices, n, fee, true, index + 1);

                subproblemSolution=max(subproblemSolution, buy);
            }

            return subproblemSolution;
        }
};


class Solution
{
    private:
        vector<vector<int>> memo;
    
    public:
        int maxProfit(vector<int> & prices, int fee)
        {
            int result=0;

            int n=prices.size();

            memo.resize(n + 1, vector<int>(2, -1));

            bool boughtStocksPreviously=false;

            int index=0;

            result=helper(prices, n, fee, boughtStocksPreviously, index);

            return result;
        }

        int helper(vector<int> & prices, int n, int fee, bool boughtStocksPreviously, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo[index][boughtStocksPreviously]!=-1)
            {
                return memo[index][boughtStocksPreviously];
            }

            int subproblemSolution=numeric_limits<int>::min();

            int doNothing=helper(prices, n, fee, boughtStocksPreviously, index + 1);

            subproblemSolution=doNothing;

            if(boughtStocksPreviously==true)
            {
                int sell=(prices[index] + helper(prices, n, fee, false, index + 1)) - fee;

                subproblemSolution=max(subproblemSolution, sell);
            }
            else
            {
                int buy=-prices[index] + helper(prices, n, fee, true, index + 1);

                subproblemSolution=max(subproblemSolution, buy);
            }

            memo[index][boughtStocksPreviously]=subproblemSolution;

            return subproblemSolution;
        }
};