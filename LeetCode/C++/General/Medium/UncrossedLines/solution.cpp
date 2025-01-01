#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/uncrossed-lines/solutions/310367/java-dp-explained/
*/


class Solution
{
    public:
        int maxUncrossedLines(vector<int> & nums1, vector<int> & nums2)
        {
            int result=0;

            int n=nums1.size();

            int m=nums2.size();

            int i=0;

            int j=0;

            result=helper(nums1, nums2, n, m, i, j);

            return result;
        }

        int helper(vector<int> & nums1, vector<int> & nums2, int n, int m, int i, int j)
        {
            if(i==n or j==m)
            {
                return 0;
            }

            int subproblemSolution=0;

            if(nums1[i]==nums2[j])
            {
                int equal=1 + helper(nums1, nums2, n, m, i + 1, j + 1);

                subproblemSolution+=equal;
            }
            else
            {
                int notEqual=max(helper(nums1, nums2, n, m, i + 1, j), helper(nums1, nums2, n, m, i, j + 1));

                subproblemSolution+=notEqual;
            }

            return subproblemSolution;
        }
};

class Solution
{
    public:
        int maxUncrossedLines(vector<int> & nums1, vector<int> & nums2)
        {
            int result=0;

            int n=nums1.size();

            int m=nums2.size();

            vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

            int i=0;

            int j=0;

            result=helper(nums1, nums2, memo, n, m, i, j);

            return result;
        }

        int helper(vector<int> & nums1, vector<int> & nums2, vector<vector<int>> & memo, int n, int m, int i, int j)
        {
            if(i==n or j==m)
            {
                return 0;
            }

            if(memo[i][j]!=-1)
            {
                return memo[i][j];
            }

            int subproblemSolution=0;

            if(nums1[i]==nums2[j])
            {
                int equal=1 + helper(nums1, nums2, memo, n, m, i + 1, j + 1);

                subproblemSolution+=equal;
            }
            else
            {
                int notEqual=max(helper(nums1, nums2, memo, n, m, i + 1, j), helper(nums1, nums2, memo, n, m, i, j + 1));

                subproblemSolution+=notEqual;
            }

            memo[i][j]=subproblemSolution;

            return subproblemSolution;
        }
};