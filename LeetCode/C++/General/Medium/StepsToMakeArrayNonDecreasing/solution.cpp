#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/steps-to-make-array-non-decreasing/solutions/2087720/super-clean-explanation-of-pro-coders-approaches-examples-include/

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int totalSteps(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            deque<pair<int, int>> stack;

            stack.emplace_back(nums[n - 1], 0);

            for(int i=n-2;i>=0;i--)
            {
                int numbersThatCanBeEatenToTheRight=0;
                
                while(!stack.empty() and stack.back().first < nums[i])
                {
                    numbersThatCanBeEatenToTheRight=max(numbersThatCanBeEatenToTheRight + 1, stack.back().second);

                    stack.pop_back();
                }

                stack.emplace_back(nums[i], numbersThatCanBeEatenToTheRight);

                result=max(result, numbersThatCanBeEatenToTheRight);
            }

            return result;
        }
};