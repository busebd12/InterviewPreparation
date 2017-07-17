int maxProfit(vector<int>& prices) 
{
    if(prices.empty())
    {
        return 0;
    }
    
    int profit=0;

    const size_t pricesSize=prices.size()-1;

    for(int index=0;index<pricesSize;++index)
    {   
        if(prices[index+1] > prices[index])
        {
            profit+=prices[index+1]-prices[index];
        }
    }

    return profit;
}