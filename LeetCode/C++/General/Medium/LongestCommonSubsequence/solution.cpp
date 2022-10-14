#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        int dfs(string & text1, string & text2, int i, int j)
        {
            if(i < 0 or j < 0)
            {
                return 0;
            }
            
            int subproblemSolution=0;
            
            if(text1[i]==text2[j])
            {
                subproblemSolution=1 + dfs(text1, text2, i - 1, j - 1);
            }
            else
            {
                subproblemSolution=max(dfs(text1, text2, i - 1, j), dfs(text1, text2, i, j - 1));
            }
            
            return subproblemSolution;
        }
    
        int longestCommonSubsequence(string text1, string text2)
        {
            int result=0;
            
            int n=text1.size();
            
            int m=text2.size();
            
            int i=n-1;
            
            int j=m-1;
            
            result=dfs(text1, text2, i, j);
            
            return result;
        }
};

class Solution
{
    private:
        vector<vector<int>> memo;
    
    public:
        int dfs(string & text1, string & text2, int i, int j)
        {
            if(i < 0 or j < 0)
            {
                return 0;
            }
            
            if(memo[i][j]!=-1)
            {
                return memo[i][j];
            }
            
            int subproblemSolution=0;
            
            if(text1[i]==text2[j])
            {
                subproblemSolution=1 + dfs(text1, text2, i - 1, j - 1);
            }
            else
            {
                subproblemSolution=max(dfs(text1, text2, i - 1, j), dfs(text1, text2, i, j - 1));
            }
            
            memo[i][j]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int longestCommonSubsequence(string text1, string text2)
        {
            int result=0;
            
            int n=text1.size();
            
            int m=text2.size();
            
            memo.resize(n, vector<int>(m, -1));
            
            int i=n-1;
            
            int j=m-1;
            
            result=dfs(text1, text2, i, j);
            
            return result;
        }
};