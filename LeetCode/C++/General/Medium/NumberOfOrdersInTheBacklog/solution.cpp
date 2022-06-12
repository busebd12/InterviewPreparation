#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: two heaps, one for buy orders (max heap) and one for sell orders (min heap).

Time complexity: O(n log n) [where n is the total number of orders]
Space complexity: O(n)
*/

class Solution
{
    public:
        int getNumberOfBacklogOrders(vector<vector<int>> & orders)
        {   
            int result=0;
            
            //Min heap since we want the sell order with the smallest price to appear at the top
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;
            
            //Max heap since we want the buy order with the largest price to appear at the top
            priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buyOrders;
            
            for(vector<int> & order : orders)
            {
                int price=order[0];
                
                int amount=order[1];
                
                int orderType=order[2];
                
                //Buy order
                if(orderType==0)
                {
                    while(!sellOrders.empty() && sellOrders.top().first <= price && amount > 0)
                    {
                        auto [topOfHeapPrice, topOfHeapAmount]=sellOrders.top();
                        
                        sellOrders.pop();
                        
                        int decrement=min(amount, topOfHeapAmount);
                        
                        amount-=decrement;
                        
                        topOfHeapAmount-=decrement;
                        
                        if(topOfHeapAmount > 0)
                        {
                            sellOrders.emplace(topOfHeapPrice, topOfHeapAmount);
                        }
                    }

                    if(amount > 0)
                    {
                        buyOrders.emplace(price, amount);
                    }
                }
                //Sell order
                else
                {
                    while(!buyOrders.empty() && buyOrders.top().first >= price && amount > 0)
                    {
                        auto [topOfHeapPrice, topOfHeapAmount]=buyOrders.top();
                        
                        buyOrders.pop();
                        
                        int decrement=min(amount, topOfHeapAmount);
                        
                        amount-=decrement;
                        
                        topOfHeapAmount-=decrement;
                        
                        if(topOfHeapAmount > 0)
                        {
                            buyOrders.emplace(topOfHeapPrice, topOfHeapAmount);
                        }
                    }
                    
                    if(amount > 0)
                    {
                        sellOrders.emplace(price, amount);
                    }
                }
            }
            
            const int MOD=1000000007;
            
            while(!buyOrders.empty())
            {
                result+=buyOrders.top().second;
                
                result=result % MOD;
                
                buyOrders.pop();
            }
            
            while(!sellOrders.empty())
            {
                result+=sellOrders.top().second;
                
                result=result % MOD;
                
                sellOrders.pop();
            }
            
            return result;
        }
};