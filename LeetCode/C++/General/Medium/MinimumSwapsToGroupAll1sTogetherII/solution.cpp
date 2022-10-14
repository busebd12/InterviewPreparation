#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minSwaps(vector<int> & nums)
        {
            int result=numeric_limits<int>::max();
            
            int n=nums.size();
            
            int ones=count(begin(nums), end(nums), 1);
            
            if(ones==n or ones==1 or ones==0)
            {
                return 0;
            }
            
            for(int i=0;i<n;i++)
            {
                nums.emplace_back(nums[i]);
            }
            
            int twoN=2 * n;
            
            int windowSize=ones;
            
            int zeros=0;
            
            int back=0;
            
            for(int front=0;front<twoN;front++)
            {
                if(nums[front]==0)
                {
                    zeros+=1;
                }
                
                int length=(front - back) + 1;
                
                if(length==windowSize)
                {
                    int flips=windowSize - zeros;
                    
                    result=min(result, zeros);
                    
                    if(nums[back]==0)
                    {
                        zeros-=1;
                    }
                    
                    back+=1;
                }
            }
            
            return result;
        }
};