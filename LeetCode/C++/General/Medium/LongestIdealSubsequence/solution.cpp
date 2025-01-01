#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

/*
Solution 1: recursive knapsack approach. Note, this solution receives Time Limit Exceeded when run.

Time complexity: O(2^n)
Space complexity: O(2^n)
*/

class Solution
{
    public:
        int longestIdealString(string s, int k)
        {
            int result=0;

            int n=s.size();

            int index=0;

            char previous='$';

            result=helper(s, n, k, previous, index);

            return result;
        }

        int helper(string & s, int n, int k, char previous, int index)
        {
            if(index==n)
            {
                return 0;
            }

            int subproblemSolution=0;

            int difference=abs(s[index] - previous);

            int take=0;

            if(previous=='$' or difference <= k)
            {
                take=1 + helper(s, n, k, s[index], index + 1);
            }

            int skip=helper(s, n, k, previous, index + 1);

            subproblemSolution=max(take, skip);

            return subproblemSolution;
        }
};

/*
Solution 1: recursive knapsack + memoization approach.

Time complexity: O(n)
Space complexity: O(n * 128) --> O(n)
*/

class Solution
{
    public:
        int longestIdealString(string s, int k)
        {
            int result=0;

            int n=s.size();

            vector<vector<int>> memo(n + 1, vector<int>(128, -1));

            int index=0;

            char previous='$';

            result=helper(s, memo, n, k, previous, index);

            return result;
        }

        int helper(string & s, vector<vector<int>> & memo, int n, int k, char previous, int index)
        {
            if(index==n)
            {
                return 0;
            }

            int characterIndex=int(previous);

            if(memo[index][characterIndex]!=-1)
            {
                return memo[index][characterIndex];
            }

            int subproblemSolution=0;

            int difference=abs(s[index] - previous);

            int take=0;

            if(previous=='$' or difference <= k)
            {
                take=1 + helper(s, memo, n, k, s[index], index + 1);
            }

            int skip=helper(s, memo, n, k, previous, index + 1);

            subproblemSolution=max(take, skip);

            memo[index][characterIndex]=subproblemSolution;

            return subproblemSolution;
        }
};