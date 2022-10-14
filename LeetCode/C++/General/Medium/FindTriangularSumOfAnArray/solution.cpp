#include <deque>
#include <vector>
using namespace std;

class Solution
{
    public:
        int triangularSum(vector<int> & nums)
        {
            int result=0;
            
            deque<vector<int>> queue;
            
            queue.push_back(nums);
            
            while(!queue.empty() and queue.front().size() > 1)
            {
                vector<int> next;
                
                for(int i=1;i<queue.front().size();i++)
                {
                    int sum=(queue.front()[i] + queue.front()[i - 1]) % 10;
                    
                    next.push_back(sum);
                }
                
                queue.pop_front();
                
                queue.push_back(next);
            }
            
            result=queue.front().front();
            
            return result;
        }
};