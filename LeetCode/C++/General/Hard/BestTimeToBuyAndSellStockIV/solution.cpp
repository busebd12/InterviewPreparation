#include <algorithm>
#include <vector>
using namespace std;


class Solution
{
    public:
        int maxProfit(int k, vector<int> & prices)
        {
            int result=0;
            
            int n=prices.size();
            
            int flag=1;
            
            int index=0;
            
            result=dfs(prices, n, k, flag, index);
            
            return result;
        }
    
        int dfs(vector<int> & prices, int n, int transactions, int flag, int index)
        {
            if(index >= n or transactions==0)
            {
                return 0;
            }
            
            int subproblemSolution=0;
            
            if(flag==1)
            {
                int buyStock=-prices[index] + dfs(prices, n, transactions, 0, index + 1);
                
                int dontBuyStock=dfs(prices, n, transactions, flag, index + 1);
                
                subproblemSolution=max(buyStock, dontBuyStock);
            }
            else
            {
                int sellStock=prices[index] + dfs(prices, n, transactions - 1, 1, index + 1);
                
                int dontSellStock=dfs(prices, n, transactions, flag, index + 1);
                
                subproblemSolution=max(sellStock, dontSellStock);
            }
            
            return subproblemSolution;
        }
};

class Solution
{
    public:
        int maxProfit(int k, vector<int> & prices)
        {
            int result=0;
            
            int n=prices.size();
            
            vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
            
            int flag=1;
            
            int index=0;
            
            result=dfs(prices, memo, n, k, flag, index);
            
            return result;
        }
    
        int dfs(vector<int> & prices, vector<vector<vector<int>>> & memo, int n, int transactions, int flag, int index)
        {
            if(index >= n or transactions==0)
            {
                return 0;
            }
            
            if(memo[index][transactions][flag]!=-1)
            {
                return memo[index][transactions][flag];
            }
            
            int subproblemSolution=0;
            
            if(flag==1)
            {
                int buyStock=-prices[index] + dfs(prices, memo, n, transactions, 0, index + 1);
                
                int dontBuyStock=dfs(prices, memo, n, transactions, flag, index + 1);
                
                subproblemSolution=max(buyStock, dontBuyStock);
            }
            else
            {
                int sellStock=prices[index] + dfs(prices, memo, n, transactions - 1, 1, index + 1);
                
                int dontSellStock=dfs(prices, memo, n, transactions, flag, index + 1);
                
                subproblemSolution=max(sellStock, dontSellStock);
            }
            
            memo[index][transactions][flag]=subproblemSolution;
            
            return subproblemSolution;
        }
};