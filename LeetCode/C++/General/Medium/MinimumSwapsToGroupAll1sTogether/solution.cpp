#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of data]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minSwaps(vector<int> & data)
        {
            int result=0;
            
            int n=data.size();
            
            int ones=count(begin(data), end(data), 1);
            
            if(ones==0 || ones==1 || ones==n)
            {
                return result;
            }
            
            int windowSize=ones;
            
            int zeros=0;
            
            int back=0;
            
            int front=0;
            
            while(front < n)
            {
                if(data[front]==0)
                {
                    zeros+=1;
                }
                
                int length=(front - back) + 1;
                
                if(length==windowSize)
                {
                    int flips=windowSize - zeros;
                    
                    if(result==0)
                    {
                        result=zeros;
                    }
                    else
                    {
                        result=min(result, zeros);
                    }
                    
                    if(data[back]==0)
                    {
                        zeros-=1;
                    }
                    
                    back+=1;
                }
                
                front+=1;
            }
            
            return result;
        }
};