#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/ways-to-make-a-fair-array/solutions/944391/simple-idea-of-storing-the-sum-o-n/

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int waysToMakeFair(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            vector<int> evenPrefixSumsBefore=getEvenPrefixSumsBefore(nums, n);

            vector<int> oddPrefixSumsBefore=getOddPrefixSumsBefore(nums, n);

            vector<int> evenPrefixSumsAfter=getEvenPrefixSumsAfter(nums, n);

            vector<int> oddPrefixSumsAfter=getOddPrefixSumsAfter(nums, n);

            for(int i=0;i<n;i++)
            {
                int evenSum=evenPrefixSumsBefore[i] + oddPrefixSumsAfter[i];

                int oddSum=oddPrefixSumsBefore[i] + evenPrefixSumsAfter[i];

                if(evenSum==oddSum)
                {
                    result+=1;
                }
            }

            return result;
        }

        vector<int> getEvenPrefixSumsBefore(vector<int> & nums, int n)
        {
            vector<int> prefixSums(n, 0);

            int sum=0;

            for(int i=0;i<n;i++)
            {
                if((i % 2)==0)
                {
                    sum+=nums[i];
                }

                prefixSums[i]=sum;
            }

            return prefixSums;
        }

        vector<int> getOddPrefixSumsBefore(vector<int> & nums, int n)
        {
            vector<int> prefixSums(n, 0);
            
            int sum=0;

            for(int i=0;i<n;i++)
            {
                if((i % 2)==1)
                {
                    sum+=nums[i];
                }

                prefixSums[i]=sum;
            }

            return prefixSums;
        }

        vector<int> getEvenPrefixSumsAfter(vector<int> & nums, int n)
        {
            vector<int> prefixSums(n, 0);

            int sum=0;

            for(int i=n-1;i>=0;i--)
            {
                if((i % 2)==0)
                {
                    sum+=nums[i];
                }

                prefixSums[i]=sum;
            }

            return prefixSums;
        }

        vector<int> getOddPrefixSumsAfter(vector<int> & nums, int n)
        {
            vector<int> prefixSums(n, 0);

            int sum=0;

            for(int i=n-1;i>=0;i--)
            {
                if((i % 2)==1)
                {
                    sum+=nums[i];
                }

                prefixSums[i]=sum;
            }

            return prefixSums;
        }
};