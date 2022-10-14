#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        int largestPerimeter(vector<int> & nums)
        {
            int n=nums.size();

            sort(nums.begin(), nums.end());

            for(int i=n-1;i>=0;i--)
            {
                if(i - 2 >= 0)
                {
                    if(nums[i] < nums[i - 1] + nums[i - 2])
                    {
                        return nums[i] + nums[i - 1] + nums[i - 2];
                    }
                }
            }

            return 0;
        }
};