#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/maximum-width-ramp/discuss/265765/Detailed-Explaination-of-all-the-three-approaches

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxWidthRamp(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            deque<int> stack;
            
            for(int i=0;i<n;i++)
            {
                if(stack.empty() or nums[stack.back()] > nums[i])
                {
                    stack.push_back(i);
                }
            }
            
            for(int i=n-1;i>=0;i--)
            {
                while(!stack.empty() and nums[i] >= nums[stack.back()])
                {
                    result=max(result, i - stack.back());
                    
                    stack.pop_back();
                }
            }
            
            return result;
        }
};