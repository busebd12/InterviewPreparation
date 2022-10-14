#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
    
        int maxSubArray(vector<int> & nums)
        {
            int result=numeric_limits<int>::min();
            
            int n=nums.size();
            
            int back=0;
            
            int sum=0;
            
            for(int front=0;front<n;front++)
            {
                sum+=nums[front];
                
                if(sum > result)
                {
                    result=sum;
                }
                
                while(sum < 0)
                {
                    sum-=nums[back];
                    
                    back+=1;
                }
            }
            
            return result;
        }
};