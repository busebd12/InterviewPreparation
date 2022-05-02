#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
*/

class Solution
{
    public:
        int dfs(string s, int n, int index)
        {
            if(index==n)
            {
                return 1;
            }
            
            if(s[index]=='0')
            {
                return 0;
            }
            
            int subproblemSolution=0;
            
            if(s[index]=='1')
            {
                subproblemSolution+=dfs(s, n, index + 1);
                
                if(index + 1 < n)
                {
                    subproblemSolution+=dfs(s, n, index + 2);
                }
            }
            else if(s[index]=='2')
            {
                subproblemSolution+=dfs(s, n, index + 1);
                
                if(index + 1 < n && (s[index + 1] - '0' >= 0 && s[index + 1] - '0' <= 6))
                {
                    subproblemSolution+=dfs(s, n, index + 2);
                }
            }
            else
            {
                subproblemSolution+=dfs(s, n, index + 1);
            }
            
            return subproblemSolution;
        }
    
        int numDecodings(string s)
        {
            int result=0;
            
            int n=s.size();
            
            int index=0;
            
            result=dfs(s, n, index);
            
            return result;
        }
};

class Solution
{
    public:
        int memoization(string s, vector<int> & memo, int n, int index)
        {
            if(index==n)
            {
                return 1;
            }
            
            if(s[index]=='0')
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            int subproblemSolution=0;
            
            if(s[index]=='1')
            {
                subproblemSolution+=memoization(s, memo, n, index + 1);
                
                if(index + 1 < n)
                {
                    subproblemSolution+=memoization(s, memo, n, index + 2);
                }
            }
            else if(s[index]=='2')
            {
                subproblemSolution+=memoization(s, memo, n, index + 1);
                
                if(index + 1 < n && (s[index + 1] - '0' >= 0 && s[index + 1] - '0' <= 6))
                {
                    subproblemSolution+=memoization(s, memo, n, index + 2);
                }
            }
            else
            {
                subproblemSolution+=memoization(s, memo, n, index + 1);
            }
            
            memo[index]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int numDecodings(string s)
        {
            int result=0;
            
            int n=s.size();
            
            vector<int> memo(n + 1, -1);
            
            int index=0;
            
            result=memoization(s, memo, n, index);
            
            return result;
        }
};

class Solution
{
    public:
        int memoization(string s, vector<int> & memo, int n, int index)
        {
            if(index==n)
            {
                return 1;
            }
            
            if(s[index]=='0')
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            int subproblemSolution=0;
            
            if(s[index]=='1')
            {
                subproblemSolution+=memoization(s, memo, n, index + 1);
                
                if(index + 1 < n)
                {
                    subproblemSolution+=memoization(s, memo, n, index + 2);
                }
            }
            else if(s[index]=='2')
            {
                subproblemSolution+=memoization(s, memo, n, index + 1);
                
                if(index + 1 < n && (s[index + 1] - '0' >= 0 && s[index + 1] - '0' <= 6))
                {
                    subproblemSolution+=memoization(s, memo, n, index + 2);
                }
            }
            else
            {
                subproblemSolution+=memoization(s, memo, n, index + 1);
            }
            
            memo[index]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int numDecodings(string s)
        {
            int result=0;
            
            int n=s.size();
            
            vector<int> memo(n + 1, 0);
            
            memo[n]=1;
            
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='0')
                {
                    memo[i]=0;
                }
                else if(s[i]=='1')
                {
                    memo[i]+=memo[i + 1];
                    
                    if(i + 1 < n)
                    {
                        memo[i]+=memo[i + 2];
                    }
                }
                else if(s[i]=='2')
                {
                    memo[i]+=memo[i + 1];
                    
                    if(i + 1 < n && s[i + 1] < '7')
                    {
                        memo[i]+=memo[i + 2];
                    }
                }
                else
                {
                    memo[i]+=memo[i + 1];
                }
            }
            
            result=memo[0];
            
            return result;
        }
};