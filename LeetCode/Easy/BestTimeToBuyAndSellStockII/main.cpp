#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approach: Loop over the prices vector. If, for two consecutive prices, one is less than the other,
 * add the difference to our profit.
 *
 * Time complexity: O(n) [where n is the number of prices]
 * Space complexity: O(1)
 */

int maxProfit(vector<int>& prices)
{
    int profit=0;

    if(prices.empty())
    {
        return profit;
    }

    int n=int(prices.size());

    for(int i=0;i<n;++i)
    {
        if(i+1 < n)
        {
            int buy=prices[i];

            int sell=prices[i+1];

            if(sell > buy)
            {
                profit+=(sell-buy);
            }
        }
    }

    return profit;
}