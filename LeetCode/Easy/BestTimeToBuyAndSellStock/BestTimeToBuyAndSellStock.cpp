int maxProfit(vector<int> & prices)
{
    if(prices.size() <= 1)
    {
        return 0;
    }
    
    const size_t pricesSize=prices.size();
    
    int sum=0;
    
    int past=0;
    
    for(int index=1;index<pricesSize;++index)
    {
        sum+=prices[index]-prices[index-1];
        
        if(sum < 0)
        {
            sum=0;
        }
        
        if(sum > past)
        {
            past=sum;
        }
    }
    
    return past;
}