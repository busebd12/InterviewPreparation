#include <algorithm>
#include <priority_queue>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int getKth(int lo, int hi, int k)
        {
            int result=0;
            
            auto compareLikeThis=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                if(lhs.second!=rhs.second)
                {
                    return lhs.second > rhs.second;
                }
                else
                {
                    return lhs.first > rhs.first;
                }
            };
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);
            
            for(int number=lo;number<=hi;number++)
            {
                int powerValue=getPowerValue(number);
                
                minHeap.emplace(number, powerValue);
            }
            
            while(!minHeap.empty() and k > 0)
            {
                result=minHeap.top().first;
                
                minHeap.pop();
                
                k-=1;
            }
            
            return result;
        }
    
        int getPowerValue(int number)
        {
            int powerValue=0;
            
            while(number > 1)
            {
                if((number % 2)==0)
                {
                    number=number / 2;
                }
                else
                {
                    number=3 * number + 1;
                }
                
                powerValue+=1;
            }
            
            return powerValue;
        }
};

class Solution
{
    public:
        int getKth(int lo, int hi, int k)
        {
            int result=0;
            
            auto compareLikeThis=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                if(lhs.second!=rhs.second)
                {
                    return lhs.second < rhs.second;
                }
                else
                {
                    return lhs.first < rhs.first;
                }
            };
            
            vector<pair<int, int>> pairs;
            
            for(int number=lo;number<=hi;number++)
            {
                int powerValue=getPowerValue(number);
                
                pairs.emplace_back(number, powerValue);
            }
            
            sort(begin(pairs), end(pairs), compareLikeThis);
            
            result=pairs[k - 1].first;
            
            return result;
        }
    
        int getPowerValue(int number)
        {
            int powerValue=0;
            
            while(number > 1)
            {
                if((number % 2)==0)
                {
                    number=number / 2;
                }
                else
                {
                    number=3 * number + 1;
                }
                
                powerValue+=1;
            }
            
            return powerValue;
        }
};