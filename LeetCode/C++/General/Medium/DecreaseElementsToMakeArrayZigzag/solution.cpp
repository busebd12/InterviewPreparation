#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int getMoves(vector<int> & nums, int n, int start)
        {
            int moves=0;
            
            for(int index=start;index<n;index+=2)
            {
                if(index==0)
                {
                    if(nums[index] >= nums[index + 1])
                    {
                        int difference=nums[index] - nums[index + 1];
                        
                        moves+=(difference + 1);
                    }
                }
                else if(index==n-1)
                {
                    if(nums[index] >= nums[index - 1])
                    {
                        int difference=nums[index] - nums[index - 1];
                        
                        moves+=(difference + 1);
                    }
                }
                else
                {
                    int minValue=min(nums[index - 1], nums[index + 1]);
                    
                    if(nums[index] >= minValue)
                    {
                        int difference=nums[index] - minValue;
                        
                        moves+=(difference + 1);
                    }
                }
            }
            
            return moves;
        }
    
        int movesToMakeZigzag(vector<int>& nums)
        {
            int result=0;
            
            int n=nums.size();
            
            if(n==1)
            {
                return result;
            }
            
            int evenStart=0;
            
            int evenIndicesMoves=getMoves(nums, n, evenStart);
            
            int oddStart=1;
            
            int oddIndicesMoves=getMoves(nums, n, oddStart);
            
            result=min(evenIndicesMoves, oddIndicesMoves);
            
            return result;
        }
};