#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of encoding]
Space complexity: O(n)
*/

class RLEIterator
{
    private:
        deque<pair<int, int>> pairs;
    
    public:
        RLEIterator(vector<int> & encoding)
        {
            createPairs(encoding);
        }

        int next(int n)
        {
            int last=0;
            
            while(!pairs.empty() and n > 0)
            {
                auto [times, digit]=pairs.front();
                
                pairs.pop_front();
                
                int minTimes=min(n, times);
                
                if(n >= minTimes)
                {
                    n-=minTimes;
                    
                    times-=minTimes;
                    
                    last=digit;
                }
                
                if(times > 0)
                {
                    pairs.emplace_front(times, digit);
                }
            }
            
            return n==0 ? last : -1;
        }
    
        void createPairs(vector<int> & encoding)
        {
            int size=encoding.size();
            
            int back=0;
            
            int front=1;
            
            while(front < size)
            {
                int times=encoding[back];
                
                int digit=encoding[front];
                
                if(times > 0)
                {
                    pairs.emplace_back(times, digit);
                }
                
                back+=2;
                
                front+=2;
            }
        }
};