import java.util.Arrays;

class Solution
{
    /*
		First solution: brute force. For each stock, check if there is a selling price greater than its current buying price.
		If there is, determine the profit. If the profit is greater than maxProfit, update maxProfit.

		Time complexity: O(n^2) [where n is the length of the input prices array]
		Space complexity: O(1)
    */

    public int maxProfit(int[] prices)
    {
        int maxProfit=0;
        
        if(prices==null || prices.length==0)
        {
            return maxProfit;
        }
        
        int n=prices.length;
        
        for(int i=0;i<n;i++)
        {
            int currentPrice=prices[i];
            
            for(int j=i+1;j<n;j++)
            {
                if(prices[j] > currentPrice)
                {
                    int profit=prices[j] - currentPrice;
                    
                    if(profit > maxProfit)
                    {
                        maxProfit=profit;
                    }
                }
            }
        }
        
        return maxProfit;
    }

    /*
		Second solution: Loop over the prices. If the current price is less than the previous priced we paid for the stock,set the buying price to the current price. 
		Else, if the current price minus the current buying price is greater than our current profit, update our current profit.

		Time complexity: O(n)
		Space complexity: O(1)
    */

    public int maxProfit(int[] prices)
    {
        int maxProfit=0;
        
        if(prices==null || prices.length==0)
        {
            return maxProfit;
        }
        
        int n=prices.length;
        
        int startingPrice=prices[0];
        
        for(int i=1;i<n;i++)
        {
            int currentPrice=prices[i];
            
            if(currentPrice < startingPrice)
            {
                startingPrice=currentPrice;
            }
            else
            {
                if(currentPrice - startingPrice > maxProfit)
                {
                    maxProfit=currentPrice - startingPrice;
                }
            }
        }
        
        return maxProfit;
    }
}