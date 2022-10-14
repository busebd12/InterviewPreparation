#include <deque>
#include <utility>
using namespace std;

class StockSpanner
{
    private:
        deque<pair<int, int>> stack;
    
    public:
        StockSpanner()
        {
            
        }

        int next(int price)
        {
            int count=1;
            
            while(!stack.empty() and stack.back().first <= price)
            {
                count+=stack.back().second;
                
                stack.pop_back();
            }
            
            stack.emplace_back(price, count);
            
            return count;
        }
};