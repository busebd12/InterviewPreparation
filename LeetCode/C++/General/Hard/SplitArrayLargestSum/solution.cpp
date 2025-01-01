#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + (n * log(s))) [where n=length of nums and s=sum of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int splitArray(vector<int> & nums, int k)
        {
            int result=numeric_limits<int>::max();

            int n=nums.size();

            int maxValue=-1;

            int sum=0;

            for(int number : nums) //O(n)
            {
                maxValue=max(maxValue, number);

                sum+=number;
            }

            //Bounds for our binary search
            int low=maxValue;

            int high=sum;

            //Do binary search in the range [max value in nums, sum of values in nums]
            while(low <= high) //O(n * log(sum of nums))
            {
                //The maximum possible sum for any of the k non-empty subarrays
                int maxSubarraySum=(low + (high - low)/2);

                //If we can split nums into at most k non-empty subarrays such that each subarray has a sum <= maxSubarraySum
                if(canSplitIntoKSubarrays(nums, n, k, maxSubarraySum)==true)
                {
                    //Minimize the max subarray sum
                    result=min(result, maxSubarraySum);

                    //Try a smaller max subarray sum
                    high=maxSubarraySum - 1;
                }
                //Else, we were able to split nums into more than k non-empty subarrays since maxSubarraySum was too small
                //So, try a larger max subarray sum next time
                else
                {
                    low=maxSubarraySum + 1;
                }
            }

            return result;
        }

        bool canSplitIntoKSubarrays(vector<int> & nums, int n, int k, int maxSubarraySum)
        {
            int splits=1;
            
            int subarraySum=0;

            for(int number : nums)
            {
                subarraySum+=number;

                //If the sum of the current subarray becomes too large
                if(subarraySum > maxSubarraySum)
                {
                    //Reset the sum
                    subarraySum=number;

                    //Increment the number of splits
                    splits+=1;

                    //If we are able to make more than k splits, then the largest subarray sum maxSubarraySum is too small
                    if(splits > k)
                    {
                        return false;
                    }
                }
            }

            return true;
        }
};