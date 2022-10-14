#include <array>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: brute-force recursive depth-first search.

Time complexity: O(4^maxMoves)
Space complexity: O(4^maxMoves)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};
        
        int MOD=1000000007;
    
    public:
        int dfs(int startRow, int startColumn, int m, int n, int maxMove)
        {
            if(startRow > m - 1 or startColumn > n - 1 or startRow < 0 or startColumn < 0)
            {
                return 1;
            }
            
            if(maxMove==0)
            {
                return 0;
            }
            
            int subproblemSolution=0;
            
            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=startRow + rowOffset;
                
                int nextColumn=startColumn + columnOffset;
                
                subproblemSolution+=dfs(nextRow, nextColumn, m, n, maxMove - 1);
                
                subproblemSolution=subproblemSolution % MOD;
            }
            
            return subproblemSolution;
            
        }
    
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
        {
            int result=0;
            
            result=dfs(startRow, startColumn, m, n, maxMove);
            
            return result;
        }
};

/*
Solution 2: recursive depth-first search but with the addition of memoization to cache already solved states to prevent re-solving of the same subprooblems again.

Time complexity: O(startRow * startColumn * maxMoves)
Space complexity: O(startRow * startColumn * maxMoves)
*/

class Solution
{
    private:
        vector<vector<vector<int>>> memo;
    
        array<pair<int, int>, 4> directions={{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};
        
        int MOD=1000000007;
    
    public:
        int dfs(int startRow, int startColumn, int m, int n, int maxMove)
        {
            if(startRow > m - 1 or startColumn > n - 1 or startRow < 0 or startColumn < 0)
            {
                return 1;
            }
            
            if(maxMove==0)
            {
                return 0;
            }
            
            if(memo[startRow][startColumn][maxMove]!=-1)
            {
                return memo[startRow][startColumn][maxMove];
            }
            
            int subproblemSolution=0;
            
            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=startRow + rowOffset;
                
                int nextColumn=startColumn + columnOffset;
                
                subproblemSolution+=dfs(nextRow, nextColumn, m, n, maxMove - 1);
                
                subproblemSolution=subproblemSolution % MOD;
            }
            
            memo[startRow][startColumn][maxMove]=subproblemSolution;
            
            return subproblemSolution;
            
        }
    
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
        {
            int result=0;
            
            memo.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
            
            result=dfs(startRow, startColumn, m, n, maxMove);
            
            return result;
        }
};