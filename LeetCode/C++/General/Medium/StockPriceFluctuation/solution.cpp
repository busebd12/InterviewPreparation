#include <map>
#include <set>
using namespace std;

class StockPrice
{
    private:
        map<int, int> timestampToPrice;
    
        multiset<int> prices;
    
    public:
        StockPrice()
        {
        }

        void update(int timestamp, int price) //O(log(u)) [where u is the number of times the update function is called]
        {
            //If the timestamp already exists in the map
            if(timestampToPrice.find(timestamp)!=end(timestampToPrice))
            {   
                int previousPrice=timestampToPrice[timestamp];
                
                auto previousPriceIterator=prices.find(previousPrice);
                
                //erase the previous price from the list of prices
                prices.erase(previousPriceIterator);
            }
            
            //Update the timestamp with the new price
            timestampToPrice[timestamp]=price;
            
            //Insert the new price into the list of prices
            prices.insert(price);
        }

        int current()
        {
            return rbegin(timestampToPrice)->second;
        }

        int maximum()
        {
            return *(rbegin(prices));
        }

        int minimum()
        {
            return *(begin(prices));
        }
};
