#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + (n log(r)))
[where n is the length of nums and r is the range (smallest number in nums to the largest number in nums)]
Space complexity: O(1)
*/

class Solution
{
    public:
        int getSum(vector<int> & nums, int divisor)
        {
            int sum=0;
            
            for(int number : nums)
            {
                if((number % divisor)==0)
                {
                    sum+=(number / divisor);
                }
                else
                {
                    sum+=(number / divisor) + 1;
                }
            }
            
            return sum;
        }
        
        int smallestDivisor(vector<int>& nums, int threshold)
        {
            int result=0;
            
            int maxValue=*max_element(begin(nums), end(nums));
            
            int low=1;
            
            int high=maxValue;
            
            //Do binary search to find the smallest divisor
            while(low <= high)
            {
                int divisor=(low + (high - low)/2);
                
                int sum=getSum(nums, divisor);
                
                if(sum > threshold)
                {
                    //Need to make the divisor larger to get a smaller sum
                    low=divisor + 1;
                }
                //Else, sum is less than or equal to threshold
                //Can we get another sum less than or equal to the threshold with a smaller divisor?
                else
                {
                    result=divisor;
                    
                    high=divisor - 1;
                }
            }
            
            return result;
        }
};