#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/arithmetic-slices/solutions/90058/simple-java-solution-9-lines-2ms/?orderBy=most_votes
Submission result: accepted.
Time complexity: O(n) [where n=length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int numberOfArithmeticSlices(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int arithmeticSlices=0;

            for(int index=2;index<n;index++)
            {
                //If three numbers form an arithmetic sequence
                if((nums[index] - nums[index - 1])==(nums[index - 1] - nums[index - 2]))
                {
                    arithmeticSlices+=1;

                    result+=arithmeticSlices;
                }
                else
                {
                    arithmeticSlices=0;
                }
            }

            return result;
        }
};