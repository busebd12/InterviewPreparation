#include <cmath>
#include <deque>
#include <unordered_set>
using namespace std;

class Solution
{
    public:
        vector<int> numsSameConsecDiff(int n, int k)
        {
            vector<int> result;
            
            const int limit=pow(10, n-1);
            
            for(int number=1;number<10;number++)
            {
                deque<int> queue;
                
                queue.push_back(number);
                
                while(!queue.empty() and queue.front() < limit)
                {
                    int qSize=queue.size();
                    
                    for(int count=0;count<qSize;count++)
                    {
                        int current=queue.front();
                    
                        queue.pop_front();
                        
                        int lastDigit=current % 10;
                        
                        int increment=lastDigit + k;
                        
                        if(increment < 10)
                        {
                            current=current * 10 + increment;
                            
                            queue.push_back(current);
                            
                            current=current / 10;
                        }
                        
                        int decrement=lastDigit - k;
                        
                        if(decrement >= 0 and decrement < 10)
                        {
                            current=current * 10 + decrement;
                            
                            queue.push_back(current);
                            
                            current=current / 10;
                        }
                    }
                }
                
                unordered_set<int> seen;
                
                while(!queue.empty())
                {
                    int current=queue.front();
                    
                    queue.pop_front();
                    
                    if(seen.find(current)==end(seen))
                    {
                        seen.insert(current);
                        
                        result.push_back(current);
                    }
                }
            }
            
            return result;
        }
};