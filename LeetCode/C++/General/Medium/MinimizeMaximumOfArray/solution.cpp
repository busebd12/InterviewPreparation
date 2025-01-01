#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n * log(max value in nums))
Space complexity: O(1)
*/

class Solution
{
    public:
        int minimizeArrayValue(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int low=0;
            
            int high=*(max_element(nums.begin(), nums.end()));

            while(low <= high)
            {
                int minimum=(low + (high - low)/2);

                if(isValidMinimum(nums, n, minimum)==true)
                {
                    result=minimum;

                    high=minimum - 1;
                }
                else
                {
                    low=minimum + 1;
                }
            }

            return result;
        }

        bool isValidMinimum(vector<int> & nums, int n, int minimum)
        {
            long sum=0;
            
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];

                long sumWithAllValuesEqualToMinimum=(long)minimum * (i + 1);

                if(sum > sumWithAllValuesEqualToMinimum)
                {
                    return false;
                }
            }

            return true;
        }
};