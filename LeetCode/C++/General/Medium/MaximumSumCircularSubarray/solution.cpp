#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this blog post

https://www.techiedelight.com/maximum-sum-circular-subarray#:~:text=We%20can%20find%20a%20maximum-sum%20circular%20sequence%20by,%7B5%2C%20-4%2C%203%2C%20-1%2C%203%7D%20having%20sum%206.

Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
    public:
        int maxSubarraySumCircular(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();
            
            int maxValue=*(max_element(begin(nums), end(nums)));
            
            if(maxValue < 0)
            {
                result=maxValue;
                
                return result;
            }

            int nonCircularSum=kadane(nums, n);

            int sum=0;

            for(int i=0;i<n;i++)
            {
                sum+=nums[i];

                nums[i]=-nums[i];
            }

            int circularSum=sum;

            int maxNegativeSubarraySum=kadane(nums, n);

            circularSum+=maxNegativeSubarraySum;

            result=max(circularSum, nonCircularSum);

            return result;
        }

        int kadane(vector<int> & nums, int n)
        {
            int maxSum=nums[0];

            int maxSumEndingHere=nums[0];

            for(int i=1;i<n;i++)
            {
                int startOverHere=nums[i];

                maxSumEndingHere=max(maxSumEndingHere + nums[i], startOverHere);

                maxSum=max(maxSum, maxSumEndingHere);
            }

            return maxSum;
        }
};