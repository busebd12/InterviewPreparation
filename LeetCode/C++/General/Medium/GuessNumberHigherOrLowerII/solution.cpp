#include <algorithm>
#include <limits>
#include <map>
#include <vector>
using namespace std;

/*
All solutions are based on this resource --> https://www.youtube.com/watch?v=7TnjypshYNU
*/

/*
Solution 1: depth-first search + recursion. Note, this solution receives Time Limit Exceeded when executed.
*/

class Solution
{
    public:
        int getMoneyAmount(int n)
        {
            int result=0;

            int start=1;

            int end=n;

            result=helper(start, end);

            return result;
        }

        int helper(int start, int end)
        {
            if(start >= end)
            {
                return 0;
            }

            int subproblemSolution=numeric_limits<int>::max();

            for(int pivot=start;pivot<=end;pivot++)
            {
                int next=pivot + max(helper(start, pivot - 1), helper(pivot + 1, end));

                subproblemSolution=min(subproblemSolution, next);
            }

            return subproblemSolution;
        }
};

/*
Solution 2: depth-first search + recursion + memoization. Note, this solution also receives Time Limit Exceeded when executed.
*/

class Solution
{
    public:
        int getMoneyAmount(int n)
        {
            int result=0;

            int start=1;

            int end=n;

            map<pair<int, int>, int> hashmap;

            result=helper(hashmap, start, end);

            return result;
        }

        int helper(map<pair<int, int>, int> & hashmap, int start, int end)
        {
            if(start >= end)
            {
                return 0;
            }

            if(hashmap.find({start, end})!=hashmap.end())
            {
                return hashmap[{start, end}];
            }

            int subproblemSolution=numeric_limits<int>::max();

            for(int pivot=start;pivot<=end;pivot++)
            {
                int next=pivot + max(helper(hashmap, start, pivot - 1), helper(hashmap, pivot + 1, end));

                subproblemSolution=min(subproblemSolution, next);
            }

            hashmap.emplace(make_pair(make_pair(start, end), subproblemSolution));

            return subproblemSolution;
        }
};

/*
Solution 3: depth-first search + recursion + memoization. Note, this solution is accepted.

Time complexity: O(n^2)
Space complexity: O(n^2)
*/

class Solution
{
    public:
        int getMoneyAmount(int n)
        {
            int result=0;

            int start=1;

            int end=n;

            vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

            result=helper(memo, start, end);

            return result;
        }

        int helper(vector<vector<int>> & memo, int start, int end)
        {
            if(start >= end)
            {
                return 0;
            }

            if(memo[start][end]!=-1)
            {
                return memo[start][end];
            }

            int subproblemSolution=numeric_limits<int>::max();

            for(int pivot=start;pivot<=end;pivot++)
            {
                int next=pivot + max(helper(memo, start, pivot - 1), helper(memo, pivot + 1, end));

                subproblemSolution=min(subproblemSolution, next);
            }

            memo[start][end]=subproblemSolution;

            return subproblemSolution;
        }
};