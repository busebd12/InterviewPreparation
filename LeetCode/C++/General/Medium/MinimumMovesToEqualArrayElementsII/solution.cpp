#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
    public:
        int minMoves2(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            sort(begin(nums), end(nums));
            
            int middleIndex=n / 2;
            
            int median=nums[middleIndex];
            
            for(int number : nums)
            {
                result+=abs(median - number);
            }
            
            return result;
        }
};