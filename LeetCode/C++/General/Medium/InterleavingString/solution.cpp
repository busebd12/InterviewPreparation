#include <string>
#include <vector>
using namespace std;

/*
Solution 1: Recursive depth-first search. Note: this solution receives Time Limit Exceeded when executed.

Time complexity: O(2^n * (length of s1 + length of s2 + length of s3))
Space complexity: O(length of s1 + length of s2 + length of s3)
*/

class Solution
{
    public:
        bool dfs(string & s1, string & s2, string & s3, int s1Size, int s2Size, int s3Size, int i, int j, int k)
        {
            if(i==s1Size and j==s2Size and k==s3Size)
            {
                return true;
            }
            
            if(i > s1Size or j > s2Size or (s1[i]!=s3[k] and s2[j]!=s3[k]))
            {
                return false;
            }
            
            bool subproblemSolution=false;
            
            if(s1[i]==s3[k])
            {
                subproblemSolution=subproblemSolution or dfs(s1, s2, s3, s1Size, s2Size, s3Size, i + 1, j, k + 1);
            }
            
            if(s2[j]==s3[k])
            {
                subproblemSolution=subproblemSolution or dfs(s1, s2, s3, s1Size, s2Size, s3Size, i, j + 1, k + 1);
            }
            
            return subproblemSolution;
        }
    
        bool isInterleave(string s1, string s2, string s3)
        {
            int s1Size=s1.size();
            
            int s2Size=s2.size();
            
            int s3Size=s3.size();
            
            if(s3Size != (s1Size + s2Size))
            {
                return false;
            }
            
            int i=0;
            
            int j=0;
            
            int k=0;
            
            return dfs(s1, s2, s3, s1Size, s2Size, s3Size, i, j, k);
        }
};

/*
Solution 2: Recursive depth-first search + memoization

Time complexity: O(length of s1 + length of s2 + length of s3)
Space complexity: O(length of s1 + length of s2 + length of s3)
*/

class Solution
{   
    public:
        bool dfs(string & s1, string & s2, string & s3, vector<vector<vector<int>>> & memo, int s1Size, int s2Size, int s3Size, int i, int j, int k)
        {
            if(i==s1Size and j==s2Size and k==s3Size)
            {
                return true;
            }
            
            if(i > s1Size or j > s2Size or (s1[i]!=s3[k] and s2[j]!=s3[k]))
            {
                return false;
            }
            
            if(memo[i][j][k]!=-1)
            {
                return memo[i][j][k];
            }
            
            bool subproblemSolution=false;
            
            if(s1[i]==s3[k])
            {
                subproblemSolution=subproblemSolution or dfs(s1, s2, s3, memo, s1Size, s2Size, s3Size, i + 1, j, k + 1);
            }
            
            if(s2[j]==s3[k])
            {
                subproblemSolution=subproblemSolution or dfs(s1, s2, s3, memo, s1Size, s2Size, s3Size, i, j + 1, k + 1);
            }
            
            memo[i][j][k]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        bool isInterleave(string s1, string s2, string s3)
        {
            int s1Size=s1.size();
            
            int s2Size=s2.size();
            
            int s3Size=s3.size();
            
            if(s3Size != (s1Size + s2Size))
            {
                return false;
            }
            
            vector<vector<vector<int>>> memo(s1Size + 1, vector<vector<int>>(s2Size + 1, vector<int>(s3Size + 1, -1)));
            
            int i=0;
            
            int j=0;
            
            int k=0;
            
            return dfs(s1, s2, s3, memo, s1Size, s2Size, s3Size, i, j, k);
        }
};