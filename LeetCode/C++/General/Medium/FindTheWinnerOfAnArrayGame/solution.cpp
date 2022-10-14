#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n + k)
Space complexity: O(n)
*/

class Solution
{
    public:
        int getWinner(vector<int> & arr, int k)
        {
            int result=0;
            
            int n=arr.size();
            
            if(k >= n)
            {
                result=*(max_element(begin(arr), end(arr)));
                
                return result;
            }
            
            deque<int> dq(begin(arr), end(arr));
            
            int count=-1;
            
            while(count < k)
            {
                int larger=max(dq[0], dq[1]);
                
                if(count==-1)
                {
                    result=larger;
                    
                    count=1;
                }
                else
                {
                    if(larger==result)
                    {
                        count+=1;
                    }
                    else
                    {
                        result=larger;
                        
                        count=1;
                    }
                }
                
                if(larger==dq[0])
                {
                    swap(dq[0], dq[1]);
                }
                
                dq.push_back(dq.front());
                    
                dq.pop_front();
            }
            
            return result;
        }
};