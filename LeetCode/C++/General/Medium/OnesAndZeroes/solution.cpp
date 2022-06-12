#include <string>
#include <vector>
using namespace std;

/*
Solutions inspired by this post --> https://leetcode.com/problems/ones-and-zeroes/discuss/95845/Easy-to-understand-Recursive-Solutions-in-Java-with-Explanation
*/

/*
Time complexity: O(2^n)
Space complexity: O(k) [where k is the length of the array]
*/
class Solution
{
    public:
        int dfs(vector<string> & strs, int m, int n, int index)
        {   
            if(index > strs.size() - 1 || (m==0 && n==0))
            {
                return 0;
            }
            
            int includeCurrentString=0;
            
            int zeros=count_if(begin(strs[index]), end(strs[index]), [] (char c) {return c=='0';});
            
            int ones=strs[index].size() - zeros;
            
            if(m >= zeros && n >= ones)
            {
                includeCurrentString= 1 + dfs(strs, m - zeros, n - ones, index + 1);
            }
            
            int excludeCurrentString=dfs(strs, m, n, index + 1);
            
            return max(includeCurrentString, excludeCurrentString);
        }
    
        int findMaxForm(vector<string> & strs, int m, int n)
        {
            int result=0;
            
            int index=0;
            
            result=dfs(strs, m, n, index);
            
            return result;
        }
};

/*
Time complexity: O(n * m * k) [where k is the length of strs]
Space complexity: O(m * n * k) [where k is the length of strs]
*/
class Solution
{
    public:
        int dfs(vector<string> & strs, vector<vector<vector<int>>> & memo, int m, int n, int index)
        {   
            if(index > strs.size() - 1 || (m==0 && n==0))
            {
                return 0;
            }
            
            if(memo[m][n][index] > 0)
            {
                return memo[m][n][index];
            }
            
            int includeCurrentString=0;
            
            int zeros=count_if(begin(strs[index]), end(strs[index]), [] (char c) {return c=='0';});
            
            int ones=strs[index].size() - zeros;
            
            if(m >= zeros && n >= ones)
            {
                includeCurrentString= 1 + dfs(strs, memo, m - zeros, n - ones, index + 1);
            }
            
            int excludeCurrentString=dfs(strs, memo, m, n, index + 1);
            
            int subproblemSolution=max(includeCurrentString, excludeCurrentString);
            
            memo[m][n][index]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int findMaxForm(vector<string> & strs, int m, int n)
        {
            int result=0;
            
            vector<vector<vector<int>>> memo(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size(), 0)));
            
            int index=0;
            
            result=dfs(strs, memo, m, n, index);
            
            return result;
        }
};