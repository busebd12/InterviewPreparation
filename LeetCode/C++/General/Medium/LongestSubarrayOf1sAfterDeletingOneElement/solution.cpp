#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (z * n)) [where z is the number of zeros and n is the length of nums]
Space complexity: O(z)
*/

class Solution
{
    public:
        int longestSubarray(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            int zeros=0;
            
            int ones=0;
            
            //List of indices in the input vector for which nums[index] is zero
            vector<int> zeroIndices;
            
            for(int index=0;index<n;index++)
            {
                if(nums[index]==0)
                {
                    zeroIndices.push_back(index);
                    
                    zeros+=1;
                }
                else
                {
                    ones+=1;
                }
            }
            
            //If nums has only ones
            if(ones==n)
            {
                return n-1;
            }
            
            //If nums is all zeros
            if(zeros==n)
            {
                return result;
            }
            
            //For each zero index
            for(int zeroIndex : zeroIndices)
            {
                int length=0;
                
                //Expand to the left until we reach a zero or the start of nums, counting ones as we go
                for(int left=zeroIndex-1;left>=0 and nums[left]!=0;left--)
                {   
                    length+=1;
                }
                
                //Expand to the right until we reach a zer of the end of nums, counting ones as we go
                for(int right=zeroIndex + 1;right<n and nums[right]!=0;right++)
                {
                    length+=1;
                }
                
                //Update the result
                result=max(result, length);
            }
            
            return result;
        }
};