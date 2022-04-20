#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/max-consecutive-ones-iii/discuss/248287/java-sliding-windows-with-comments-in-line

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int longestOnes(vector<int> & nums, int k)
        {
            int result=0;
    
            int n=nums.size();

            int back=0;

            int front=0;

            int zeros=0;

            while(front < n)
            {
                if(nums[front]==0)
                {
                    zeros+=1;
                }
                
                while(zeros > k)
                {
                    if(nums[back]==0)
                    {
                        zeros-=1;
                    }

                    back+=1;
                }
                
                result=max(result, (front - back) + 1);
                
                front+=1;
            }

            return result;
        }
};