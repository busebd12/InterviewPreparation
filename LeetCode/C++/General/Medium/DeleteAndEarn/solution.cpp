#include <algorithm>
#include <unordered_map>
#include <vector>

/*
Solution: based on this post --> https://leetcode.com/problems/delete-and-earn/discuss/1923979/C%2B%2B-Easy-and-Understandable-Explanation

Time complexity: O(n + u) [where n is the length of nums and u is the number of unique values in nums]

Space complexity: O(u + (max value in nums) + 1)
*/

class Solution
{
    public:
        int deleteAndEarn(vector<int> & nums)
        {
            int result=0;

            unordered_map<int, int> frequencies;

            for(auto number : nums)
            {
                frequencies[number]+=1;
            }

            int maxNumber=*(max_element(begin(nums), end(nums)));

            vector<int> sums(maxNumber + 1, 0);

            for(auto & [number, frequency] : frequencies)
            {
                sums[number]=number * frequency;
            }

            vector<int> dp(maxNumber + 1);

            dp[0]=0;

            dp[1]=sums[1];

            for(int i=2;i<=maxNumber;i++)
            {
                dp[i]=max(sums[i] + dp[i - 2], dp[i - 1]);
            }

            result=dp[maxNumber];

            return result;
        }
};