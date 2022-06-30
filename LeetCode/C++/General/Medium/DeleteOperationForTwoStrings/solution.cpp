#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
Solution 1: recursion. See comments.

Time complexity: O(2^(n + m)) [where n is the length of word1 and m is the length of word2]
Space complexity: O(n + m)
*/
class Solution
{
    public:
        int dfs(string word1, string word2, int n, int m, int i, int j)
        {
            //If we have reached the end of both strings, no more changes needed
            if(i==n && j==m)
            {
                return 0;
            }
            
            //Reached the end of word1, so we just need to remove the rest of the letters from word2
            if(i==n)
            {
                return word2.size() - j;
            }
            
            //Reached the end of word2, so we just need to remove the rest of the letters from word1
            if(j==m)
            {
                return word1.size() - i;
            }
            
            int subproblemSolution=0;
            
            //Characters match, no deletion needed
            if(word1[i]==word2[j])
            {
                subproblemSolution=dfs(word1, word2, n, m, i + 1, j + 1);
            }
            //Characters don't match
            else
            {
                subproblemSolution=1 + min(dfs(word1, word2, n, m, i + 1, j), dfs(word1, word2, n, m, i, j + 1));
            }
            
            return subproblemSolution;
        }
    
        int minDistance(string word1, string word2)
        {
            int result=0;
            
            int n=word1.size();
            
            int m=word2.size();
            
            int i=0;
            
            int j=0;
            
            result=dfs(word1, word2, n, m, i, j);
            
            return result;
        }
};

/*
Solution 2: recursion + memoization.

Time complexity: O(n + m)
Space complexity: O(n + m)
*/

class Solution
{
    public:
        int dfs(string word1, string word2, vector<vector<int>> & memo, int n, int m, int i, int j)
        {
            //If we have reached the end of both strings, no more changes needed
            if(i==n && j==m)
            {
                return 0;
            }
            
            //Reached the end of word1, so we just need to remove the rest of the letters from word2
            if(i==n)
            {
                return word2.size() - j;
            }
            
            //Reached the end of word2, so we just need to remove the rest of the letters from word1
            if(j==m)
            {
                return word1.size() - i;
            }
            
            if(memo[i][j]!=-1)
            {
                return memo[i][j];
            }
            
            int subproblemSolution=0;
            
            //Characters match, no deletion needed
            if(word1[i]==word2[j])
            {
                subproblemSolution=dfs(word1, word2, memo, n, m, i + 1, j + 1);
            }
            //Characters don't match
            else
            {
                subproblemSolution=1 + min(dfs(word1, word2, memo, n, m, i + 1, j), dfs(word1, word2, memo, n, m, i, j + 1));
            }
            
            memo[i][j]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int minDistance(string word1, string word2)
        {
            int result=0;
            
            int n=word1.size();
            
            int m=word2.size();
            
            vector<vector<int>> memo(n, vector<int>(m, -1));
            
            int i=0;
            
            int j=0;
            
            result=dfs(word1, word2, memo, n, m, i, j);
            
            return result;
        }
};