#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <numeric>
using namespace std;

int dfs(vector<int> & coins, int amount, int index, const int n)
{
    if(index >= n)
    {
        return 0;
    }

    if(amount < 0)
    {
        return 0;
    }

    if(amount==0)
    {
        return 1;
    }

    int ways=0;

    int withoutCurrentCoin=dfs(coins, amount, index+1, n);

    ways+=withoutCurrentCoin;

    int withCurrentCoin=dfs(coins, amount-coins[index], index, n);

    ways+=withCurrentCoin;

    return ways;
}

int changeTLE(int amount, vector<int> & coins)
{
    int index=0;

    int n=int(coins.size());

    return dfs(coins, amount, index, n);
}

int memoizedRecursion(vector<int> & coins, vector<vector<int>> & memoization, const int n, int amount, int index)
{
    if(amount < 0)
    {
        return 0;
    }

    if(amount==0)
    {
        return 1;
    }

    if(memoization[index][amount]!=-1)
    {
        return memoization[index][amount];
    }

    int ways=0;

    for(int i=index;i<n;++i)
    {
        ways+=memoizedRecursion(coins, memoization, n, amount-coins[i], i);
    }

    memoization[index][amount]=ways;

    return ways;
}

int change(int amount, vector<int> & coins)
{
    if(amount==0)
    {
        return 1;
    }

    if(coins.empty())
    {
        return 0;
    }

    int n=int(coins.size());

    vector<vector<int>> memoization(n, vector<int>(amount+1));

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<amount+1;++j)
        {
            memoization[i][j]=-1;
        }
    }

    int index=0;

    return memoizedRecursion(coins, memoization, n, amount, index);
}