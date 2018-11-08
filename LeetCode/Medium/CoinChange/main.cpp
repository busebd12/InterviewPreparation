#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int coinChangeBruteForce(vector<int> & coins, int amount)
{
    if(amount==0)
    {
        return 0;
    }

    if(amount < 0)
    {
        return -1;
    }

    int minimumCoins=-1;

    for(auto & coin : coins)
    {
        int subproblemSolution=coinChangeBruteForce(coins, amount-coin);

        if(subproblemSolution >= 0)
        {
            minimumCoins=(minimumCoins < 0) ? subproblemSolution : min(minimumCoins, subproblemSolution);
        }
    }

    return minimumCoins < 0 ? -1 : minimumCoins + 1;
}

int memoizedHelper(vector<int> & coins, unordered_map<int, int> & memoization, int & amount)
{
    if(amount < 0)
    {
        return -1;
    }

    if(amount==0)
    {
        return 0;
    }

    auto itr=memoization.find(amount);

    if(itr!=memoization.end())
    {
        return memoization[amount];
    }

    int minimumCoins=amount + 1;

    for(auto & coin : coins)
    {
        int subproblem=amount-coin;

        int subproblemSolution=memoizedHelper(coins, memoization, subproblem);

        if(subproblemSolution >= 0)
        {
            minimumCoins=min(subproblemSolution, minimumCoins);
        }
    }

    if(minimumCoins > amount)
    {
        memoization[amount]=-1;
    }
    else
    {
        memoization[amount]=minimumCoins + 1;
    }

    return memoization[amount];
}

int coinChange(vector<int> & coins, int amount)
{
    unordered_map<int, int> memoization;

    return memoizedHelper(coins, memoization, amount);
}