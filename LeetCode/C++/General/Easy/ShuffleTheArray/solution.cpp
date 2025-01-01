#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n=length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> shuffle(vector<int> & nums, int n)
        {
            vector<int> result;

            int middle=n;

            int low=0;

            int high=middle;

            while(low < middle)
            {
                result.push_back(nums[low]);

                result.push_back(nums[high]);

                low+=1;

                high+=1;
            }

            return result;
        }
};