#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int numSubarrayProductLessThanK(vector<int> & nums, int k)
        {
            int result=0;

            if(k <= 1)
            {
                return 0;
            }

            int n=nums.size();

            int back=0;

            int product=1;

            for(int front=0;front<n;front++)
            {
                product*=nums[front];

                while(product >= k)
                {
                    product/=nums[back];

                    back+=1;
                }

                int length=(front - back) + 1;

                result+=length;
            }

            return result;
        }
};