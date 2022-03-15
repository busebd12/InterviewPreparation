#include <iostream>
#include <iterator>
#include <map>
#include <set>

class StockPrice
{
    public:
        
        //Hashtable used to map timestamps to prices
        map<int, int> hashtable;
    
        //Keep track of all prices (use multiset since prices are not unique)
        multiset<int> prices;
    
        void update(int timestamp, int price)
        {   
            //If we've seen the timestamp before, then we are updating the price (correcting it)
            if(hashtable.count(timestamp))
            {
                int priorPrice=hashtable[timestamp];
                
                auto itr=prices.find(priorPrice);
                
                prices.erase(itr);
            }
            
            prices.insert(price);
            
            hashtable[timestamp]=price;
        }
    
        int current()
        {
            return rbegin(hashtable)->second;
        }
    
        int maximum()
        {
            return *rbegin(prices);
        }
    
        int minimum()
        {
            return *begin(prices);
        }
};