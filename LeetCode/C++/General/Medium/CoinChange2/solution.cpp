#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/coin-change-2/discuss/141076/Unbounded-Knapsack
*/

class Solution
{
    public:
        int dfs(vector<int> & coins, int n, int amount, int index)
        {
            if(amount==0)
            {
                return 1;
            }
            
            if(amount < 0 || index > n - 1)
            {
                return 0;
            }
            
            int subproblemSolution=0;
            
            int takeCurrentCoin=dfs(coins, n, amount - coins[index], index);
            
            int skipCurrentCoin=dfs(coins, n, amount, index + 1);
            
            subproblemSolution=takeCurrentCoin + skipCurrentCoin;
            
            return subproblemSolution;
        }
    
        int change(int amount, vector<int> & coins)
        {
            int result=0;
            
            int n=coins.size();
            
            int index=0;
            
            result=dfs(coins, n, amount, index);
            
            return result;
        }
};

class Solution
{
    public:
        int dfs(vector<int> & coins, vector<vector<int>> & memo, int n, int amount, int index)
        {
            if(amount==0)
            {
                return 1;
            }
            
            if(amount < 0 || index > n - 1)
            {
                return 0;
            }
            
            if(memo[amount][index]!=-1)
            {
                return memo[amount][index];
            }
            
            int subproblemSolution=0;
            
            int takeCurrentCoin=dfs(coins, memo, n, amount - coins[index], index);
            
            int skipCurrentCoin=dfs(coins, memo, n, amount, index + 1);
            
            subproblemSolution=takeCurrentCoin + skipCurrentCoin;
            
            memo[amount][index]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int change(int amount, vector<int> & coins)
        {
            int result=0;
            
            int n=coins.size();
            
            vector<vector<int>> memo(amount + 1, vector<int>(n, -1));
            
            int index=0;
            
            result=dfs(coins, memo, n, amount, index);
            
            return result;
        }
};