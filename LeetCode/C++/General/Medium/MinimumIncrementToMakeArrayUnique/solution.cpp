#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minIncrementForUnique(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            sort(begin(nums), end(nums));
            
            int next=nums[0];
            
            for(int i=0;i<n;i++)
            {
                if(nums[i] < next)
                {
                    int difference=next - nums[i];
                    
                    result+=difference;
                    
                    nums[i]+=difference;
                }
                
                next=nums[i] + 1;
            }
            
            return result;
        }
};