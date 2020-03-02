#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Brute force + dfs. We recursively try to make change with each coin demonination if the coin value is smaller than
 * the amount left.
 *
 * Time complexity: O(n^amount) [where n is the number of coins]
 * Space complexity: O(amount)
 *
 * 2. Recursive dfs + memoization. We use an std::unordered_map<int, int> to store answers to subproblems so that we
 * don't have to keep solving the same subproblems over and over and over.
 *
 * Time complexity: O(n * amount) [where n is the number of coins]
 * Space complexity: O(amount)
 *
 * 3. Bottom-up, dynamic programming.
 *
 * Time complexity: O(amount * n)
 * Space complexity: O(amount)
 */

int dfs(std::vector<int> & coins, int amount)
{
    if(amount==0)
    {
        return 0;
    }

    int subproblem=-1;

    for(auto & coin : coins)
    {
        if(amount - coin >= 0)
        {
            int numberOfCoins=dfs(coins, amount - coin);

            if(numberOfCoins!=-1)
            {
                numberOfCoins+=1;

                if(subproblem==-1)
                {
                    subproblem=numberOfCoins;
                }
                else
                {
                    subproblem=std::min(subproblem, numberOfCoins);
                }
            }
        }
    }

    return subproblem;
}

int coinChange(std::vector<int> & coins, int amount)
{
    if(coins.empty())
    {
        return -1;
    }

    if(amount==0)
    {
        return 0;
    }

    std::unordered_map<int, int> memo;

    int result=dfs(coins, amount);

    return result;
}


int memoization(std::vector<int> & coins, std::unordered_map<int, int> & memo, int amount)
{
    if(amount==0)
    {
        return 0;
    }

    if(memo.count(amount))
    {
        return memo[amount];
    }

    int subproblem=-1;

    for(auto & coin : coins)
    {
        if(amount - coin >= 0)
        {
            int numberOfCoins=memoization(coins, memo, amount - coin);

            if(numberOfCoins!=-1)
            {
                numberOfCoins+=1;

                if(subproblem==-1)
                {
                    subproblem=numberOfCoins;
                }
                else
                {
                    subproblem=std::min(subproblem, numberOfCoins);
                }
            }
        }
    }

    memo[amount]=subproblem;

    return memo[amount];
}

int coinChange(std::vector<int> & coins, int amount)
{
    if(coins.empty())
    {
        return -1;
    }

    if(amount==0)
    {
        return 0;
    }

    std::unordered_map<int, int> memo;

    int result=memoization(coins, memo, amount);

    return result;
}

int coinChange(std::vector<int> & coins, int amount)
{
    if(coins.empty())
    {
        return -1;
    }

    if(amount==0)
    {
        return 0;
    }

    std::vector<int> dp(amount+1, amount+1);

    dp[0]=0;

    for(int currentAmount=0;currentAmount<=amount;++currentAmount)
    {
        for(auto & coin : coins)
        {
            if(currentAmount - coin >= 0)
            {
                dp[currentAmount]=std::min(dp[currentAmount], dp[currentAmount - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}