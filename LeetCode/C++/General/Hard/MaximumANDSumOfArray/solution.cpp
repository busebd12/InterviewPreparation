#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursion. Note, this solution receives Time Limit Exceeded when executed.
*/

class Solution
{
    public:
        int maximumANDSum(vector<int> & nums, int numSlots)
        {
            int result=0;

            int n=nums.size();

            vector<int> slots(numSlots, 0);

            int index=0;

            result=helper(nums, slots, n, numSlots, index);

            return result;
        }

        int helper(vector<int> & nums, vector<int> & slots, int n, int numSlots, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            int subproblemSolution=0;

            for(int i=0;i<numSlots;i++)
            {
                if(slots[i] < 2)
                {
                    slots[i]+=1;

                    int sum=(nums[index] & (i + 1)) + helper(nums, slots, n, numSlots, index + 1);

                    subproblemSolution=max(subproblemSolution, sum);

                    slots[i]-=1;
                }
            }

            return subproblemSolution;
        }
};

/*
Solution 2: recursion + memoization.
*/

class Solution
{
    private:
        map<vector<int>, int> memo;
    
    public:
        int maximumANDSum(vector<int>& nums, int numSlots)
        {
            int result=0;

            int n=nums.size();

            vector<int> slots(numSlots, 0);

            int index=0;

            result=helper(nums, slots, n, numSlots, index);

            return result;
        }

        int helper(vector<int> & nums, vector<int> & slots, int n, int numSlots, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo.find(slots)!=memo.end())
            {
                return memo[slots];
            }

            int subproblemSolution=0;

            for(int i=0;i<numSlots;i++)
            {
                if(slots[i] < 2)
                {
                    slots[i]+=1;

                    int sum=(nums[index] & (i + 1)) + helper(nums, slots, n, numSlots, index + 1);

                    subproblemSolution=max(subproblemSolution, sum);

                    slots[i]-=1;
                }
            }

            memo[slots]=subproblemSolution;

            return subproblemSolution;
        }
};