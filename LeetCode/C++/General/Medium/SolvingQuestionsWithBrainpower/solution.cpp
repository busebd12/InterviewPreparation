#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: recursive depth-first search. Note: this solution receives Time Limit Exceeded when executed.

Time complexity: O(2^n) [where n is the length of questions]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long dfs(vector<vector<int>> & questions, int n, int index)
        {
            if(index > n-1)
            {
                return 0;
            }
            
            long long subproblemSolution=0;
            
            int points=questions[index][0];
            
            int brainPower=questions[index][1];
            
            long long solveQuestion=points + dfs(questions, n, index + brainPower + 1);
            
            long long skipQuestion=dfs(questions, n, index + 1);
            
            subproblemSolution=max(solveQuestion, skipQuestion);
            
            return subproblemSolution;
        }
    
        long long mostPoints(vector<vector<int>>& questions)
        {
            long long result=0;
            
            int n=questions.size();
            
            int index=0;
            
            result=dfs(questions, n, index);
            
            return result;
        }
};

/*
Solution 1: recursive depth-first search with memoization.

Time complexity: O(n) [where n is the length of questions]
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<int> memo;
    
    public:
        long long dfs(vector<vector<int>> & questions, int n, int index)
        {
            if(index > n-1)
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            long long subproblemSolution=0;
            
            int points=questions[index][0];
            
            int brainPower=questions[index][1];
            
            long long solveQuestion=points + dfs(questions, n, index + brainPower + 1);
            
            long long skipQuestion=dfs(questions, n, index + 1);
            
            subproblemSolution=max(solveQuestion, skipQuestion);
            
            memo[index]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        long long mostPoints(vector<vector<int>>& questions)
        {
            long long result=0;
            
            int n=questions.size();
            
            memo.resize(n, -1);
            
            int index=0;
            
            result=dfs(questions, n, index);
            
            return result;
        }
};