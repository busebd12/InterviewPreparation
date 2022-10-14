#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O((n * log n) + n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int partitionArray(vector<int> & nums, int k)
        {
            int result=0;

            int n=nums.size();

            sort(begin(nums), end(nums));

            int i=0;

            while(i < n)
            {
                int j=i + 1;
                
                while(j < n and nums[j] <= nums[i] + k)
                {
                    j+=1;
                }

                result+=1;

                i=j;
            }

            return result;
        }
};