#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Brute force. For each stock, check if there is a selling price greater than its current buying price.
 * If there is, determine the profit. If the profit is greater than maxProfit, update maxProfit.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 *
 * 2) Loop over the prices. If the current price is less than the previous priced we paid for the stock,
 * set the buying price to the current price. Else, if the current price minus the current buying price
 * is greater than our current profit, update our current profit.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

int maxProfit(vector<int>& prices)
{
    int maxProfit=0;

    if(prices.empty())
    {
        return maxProfit;
    }

    int n=int(prices.size());

    for(int i=0;i<n;++i)
    {
        int profit=0;

        int buy=prices[i];

        for(int j=i+1;j<n;++j)
        {
            int sell=prices[j];

            if(sell > buy)
            {
                profit=sell-buy;

                maxProfit=max(maxProfit, profit);
            }
        }
    }

    return maxProfit;
}

int maxProfit(vector<int> & prices)
{
    int profit=0;

    if(prices.empty())
    {
        return profit;
    }

    int n=int(prices.size());

    int buy=prices[0];

    for(int index=0;index<n;++index)
    {
        int current=prices[index];

        if(current < buy)
        {
            buy=current;
        }
        else
        {
            if(current-buy > profit)
            {
                profit=current-buy;
            }
        }
    }

    return profit;
}