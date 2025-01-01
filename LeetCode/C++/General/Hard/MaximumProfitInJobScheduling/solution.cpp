#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursive depth-first search.

Time complexity: O((n * log(n)) + (2^n)) [where n is the length of startTime, endTime, and profit]
Space complexity: O(n)
*/

class Solution
{
    public:
        int jobScheduling(vector<int> & startTime, vector<int> & endTime, vector<int> & profit)
        {
            int result=0;

            int n=startTime.size();

            vector<vector<int>> jobs;

            for(int i=0;i<n;i++)
            {
                int jobStartTime=startTime[i];

                int jobEndTime=endTime[i];

                int jobProfit=profit[i];

                jobs.emplace_back(vector<int>{jobStartTime, jobEndTime, jobProfit});
            }

            //Sort jobs in increasing order by start time
            sort(jobs.begin(), jobs.end());

            int index=0;

            result=helper(jobs, n, index);

            return result;
        }

        int helper(vector<vector<int>> & jobs, int n, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            vector<int> temp={jobs[index][1], 0, 0};

            //Search for the next job that has start time >= the current job's end time
            //Since the jobs vector is sorted in increasing order, we can use binary search (std::lower_bound) instead of a linear search
            int nextJobIndex=lower_bound(jobs.begin(), jobs.end(), temp) - jobs.begin(); //O(log(n))

            int subproblemSolution=0;

            int takeJob=jobs[index][2] + helper(jobs, n, nextJobIndex);

            int dontTakeJob=helper(jobs, n, index + 1);

            subproblemSolution=max(takeJob, dontTakeJob);

            return subproblemSolution;
        }
};

/*
Solution 2: similar to solution 1 but with the assistance of memoization to make use of previously computed solutions to subproblems.

Time complexity: O((n * log(n)) + (n * log(n))) --> O(n * log(n))
Space complexity: O(n)
*/

class Solution
{
    public:
        int jobScheduling(vector<int> & startTime, vector<int> & endTime, vector<int> & profit)
        {
            int result=0;

            int n=startTime.size();

            vector<vector<int>> jobs;

            for(int i=0;i<n;i++)
            {
                int jobStartTime=startTime[i];

                int jobEndTime=endTime[i];

                int jobProfit=profit[i];

                jobs.emplace_back(vector<int>{jobStartTime, jobEndTime, jobProfit});
            }

            sort(jobs.begin(), jobs.end()); //O(n * log(n))

            vector<int> memo(n + 1, -1);

            int index=0;

            result=helper(jobs, memo, n, index);

            return result;
        }

        int helper(vector<vector<int>> & jobs, vector<int> & memo, int n, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo[index]!=-1)
            {
                return memo[index];
            }

            vector<int> temp={jobs[index][1], 0, 0};

            //Search for the next job that has start time >= the current job's end time
            //Since the jobs vector is sorted in increasing order, we can use binary search (std::lower_bound) instead of a linear search
            int nextJobIndex=lower_bound(jobs.begin(), jobs.end(), temp) - jobs.begin();

            int subproblemSolution=0;

            int takeJob=jobs[index][2] + helper(jobs, memo, n, nextJobIndex);

            int dontTakeJob=helper(jobs, memo, n, index + 1);

            subproblemSolution=max(takeJob, dontTakeJob);

            memo[index]=subproblemSolution;

            return subproblemSolution;
        }
};