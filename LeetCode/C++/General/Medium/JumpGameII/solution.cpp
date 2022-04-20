#include <algorithm>
#include <deque>
#include <limits>
#include <vector>

/*
Solution 1: Depth-first search recursion. This solution receives Time Limit Exceeded when executed.

Time complexity: O(n^(average value of number in nums)) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int dfs(vector<int> & nums, int n, int index)
        {
            if(index >= n-1)
            {
                return 0;
            }
            
            int subproblemSolution=numeric_limits<int>::max();
            
            for(int jump=nums[index];jump>0;jump--)
            {
                int jumps=dfs(nums, n, index + jump);
                
                if(jumps!=numeric_limits<int>::max())
                {
                    subproblemSolution=min(subproblemSolution, jumps + 1);
                }
            }
            
            return subproblemSolution;
        }
    
        int jump(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            int index=0;
            
            result=dfs(nums, n, index);
            
            return result;
        }
};

/*
Solution 2: Depth-first search recursion + memoization

Time complexity: O(n)
Space complexity: O(n)

*/

class Solution
{
    public:
        int memoization(vector<int> & nums, vector<int> & memo, int n, int index)
        {
            if(index >= n-1)
            {
                return 0;
            }
            
            if(memo[index]!=-1)
            {
                return memo[index];
            }
            
            int subproblemSolution=numeric_limits<int>::max();
            
            for(int jump=nums[index];jump>0;jump--)
            {
                int jumps=memoization(nums, memo, n, index + jump);
                
                if(jumps!=numeric_limits<int>::max())
                {
                    subproblemSolution=min(subproblemSolution, jumps + 1);
                    
                    memo[index]=subproblemSolution;
                }
            }
            
            return subproblemSolution;
        }
    
        int jump(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            vector<int> memo(n, -1);
            
            int index=0;
            
            result=memoization(nums, memo, n, index);
            
            return result;
        }
};

/*
Solution 3: Breadth-first search

Time complexity: O(n)
Space complexity: O(n)

*/
class Solution
{
    public:
        int jump(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            vector<bool> visited(n, false);
            
            deque<int> queue;
            
            visited[0]=true;
            
            queue.emplace_back(0);
            
            while(!queue.empty())
            {
                auto qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto index=queue.front();
                    
                    queue.pop_front();
                    
                    if(index==n-1)
                    {
                        return result;
                    }
                    
                    for(int jump=nums[index];jump>0;jump--)
                    {
                        int next=index + jump;
                        
                        if(next < n)
                        {
                            if(visited[next]==false)
                            {
                                visited[next]=true;

                                queue.emplace_back(next);
                            }
                        }
                    }
                }
                
                result+=1;
            }
            
            return -1;
        }
};