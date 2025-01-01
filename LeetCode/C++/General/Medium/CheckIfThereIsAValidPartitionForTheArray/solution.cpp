#include <vector>
using namespace std;

/*
Solution 1: recursively check the three conditions.

Time complexity: O(2^n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool validPartition(vector<int> & nums)
        {
            bool result=false;
            
            int n=nums.size();

            int index=0;

            result=helper(nums, n, index);

            return result;
        }

        bool helper(vector<int> & nums, int n, int index)
        {
            if(index==n)
            {
                return true;
            }

            bool subproblemSolution=false;

            if(index + 1 < n and nums[index]==nums[index + 1])
            {
                subproblemSolution=subproblemSolution or helper(nums, n, index + 2);
            }
            
            if(index + 2 < n)
            {
                int first=nums[index];

                int second=nums[index + 1];

                int third=nums[index + 2];

                bool allEqual=(first==second and second==third);

                bool consecutive=(first==(second - 1) and second==(third - 1));

                if(allEqual==true or consecutive==true)
                {
                    subproblemSolution=subproblemSolution or helper(nums, n, index + 3);
                }
            }

            return subproblemSolution;
        }
};

/*
Solution 2: recursively check the three conditions + memoization

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool validPartition(vector<int> & nums)
        {
            bool result=false;
            
            int n=nums.size();

            vector<int> memo(n, -1);

            int index=0;

            result=helper(nums, memo, n, index);

            return result;
        }

        bool helper(vector<int> & nums, vector<int> & memo, int n, int index)
        {
            if(index==n)
            {
                return true;
            }

            if(memo[index]!=-1)
            {
                return memo[index];
            }

            bool subproblemSolution=false;

            if(index + 1 < n and nums[index]==nums[index + 1])
            {
                subproblemSolution=subproblemSolution or helper(nums, memo, n, index + 2);
            }
            
            if(index + 2 < n)
            {
                int first=nums[index];

                int second=nums[index + 1];

                int third=nums[index + 2];

                bool allEqual=(first==second and second==third);

                bool consecutive=(first==(second - 1) and second==(third - 1));

                if(allEqual==true or consecutive==true)
                {
                    subproblemSolution=subproblemSolution or helper(nums, memo, n, index + 3);
                }
            }

            memo[index]=subproblemSolution;

            return subproblemSolution;
        }
};