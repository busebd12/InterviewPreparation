#include <vector>
using namespace std;

/*
Solution: just calculate the prefix sums for the input vector

Time complexity: O(n)
Space complexity: O(1) [if we don't count the output vector] O(n) [if we do count the output vector]
*/

class Solution
{
    public:
        vector<int> runningSum(vector<int> & nums)
        {
            vector<int> result;
            
            int n=nums.size();
            
            result.resize(n);
            
            result[0]=nums[0];
            
            for(int i=1;i<n;i++)
            {
                result[i]=result[i - 1] + nums[i];
            }
            
            return result;
        }
};