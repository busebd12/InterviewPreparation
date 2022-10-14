#include <vector>
using namespace std;


/*
Time complexity: O(n * target) [where n is the length of nums]
Space complexity: O(target)
*/

class Solution
{
    public:
        int combinationSum4(vector<int> & nums, int target)
        {
            int result=0;
            
            vector<int> memo(target + 1, -1);
            
            result=dfs(nums, memo, target);
            
            return result;
        }
    
        int dfs(vector<int> & nums, vector<int> & memo, int target)
        {
            if(target==0)
            {
                return 1;
            }
            
            if(memo[target]!=-1)
            {
                return memo[target];
            }
            
            int subproblemSolution=0;

            for(int & number : nums)
            {
                if(number <= target)
                {
                    subproblemSolution+=dfs(nums, memo, target - number);
                }
            }
            
            memo[target]=subproblemSolution;
            
            return subproblemSolution;
        }
};