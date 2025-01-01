#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/1379564/c-very-simple-solution/
2) https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/2204082/c-2-pointers-simple-explanation/

Time complexity: O(n + (n * log(n)))
Space complexity: O(n)
*/

class Solution
{
    public:
        int numSubseq(vector<int> & nums, int target)
        {
            int result=0;
            
            int n=nums.size();

            const int MOD=1e9 + 7;

            vector<int> powersOfTwo(n + 1, 1);

            for(int i=1;i<=n;i++)
            {
                powersOfTwo[i]=(2 * powersOfTwo[i - 1]) % MOD;
            }

            sort(nums.begin(), nums.end());

            int low=0;

            int high=n - 1;

            while(low <= high)
            {
                int sum=nums[low] + nums[high];

                if(sum > target)
                {
                    high-=1;
                }
                else
                {
                    int lengthWithoutMinValue=high - low;

                    int subsequences=powersOfTwo[lengthWithoutMinValue];

                    result=(result + subsequences) % MOD;

                    low+=1;
                }
            }

            return result;
        }
};