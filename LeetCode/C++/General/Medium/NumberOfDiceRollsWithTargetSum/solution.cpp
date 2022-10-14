#include <vector>
using namespace std;

class Solution
{
    private:
        vector<vector<int>> memo;
    
        const int MOD=1e9 + 7;
    
    public:
        int numRollsToTarget(int n, int k, int target)
        {
            int result=0;
            
            memo.resize(n + 1, vector<int>(target + 1, -1));
            
            result=dfs(n, k, target);
            
            return result;
        }
    
        int dfs(int n, int k, int target)
        {   
            //If target becomes negative, no way to roll dice with positive values to get a negative value
            if(target < 0)
            {
                return 0;
            }
            
            //If we have only one die remaining, the largest value of the die is less than target, and target is greater than zero, then we can't roll this die to get the target sum
            if(n==1 and k < target and target > 0)
            {
                return 0;
            }
            
            //If we have only one die remaining, the largest value of the die is greater than or equal to the target sum, and the target sum is greater than zero, it is possible to roll the die one way to get the target sum
            if(n==1 and k >= target and target > 0)
            {
                return 1;
            }
            
            //If we've already computed the state identified by n and target, just return it from our cache
            if(memo[n][target]!=-1)
            {
                return memo[n][target];
            }
            
            //The solution to the problem at the current level of recursion
            int subproblemSolution=0;
            
            //Iterate through all the sides of the die
            for(int side=1;side<=k;side++)
            {
                //Add subtract the die side value from target, reduce the number of dice by 1, and recurse
                //Add the result of the smaller subproblem to this solution for the current level of recursion
                subproblemSolution+=dfs(n - 1, k, target - side);
                
                //Do the modulo part
                subproblemSolution=subproblemSolution % MOD;
            }
            
            //Add the solution to this level of recursion to our cache so we don't have to recompute it later
            memo[n][target]=subproblemSolution;
            
            return subproblemSolution;
        }
};