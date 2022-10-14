#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <vector>
using namespace std;

/*
Solutions: inspired by this post --> https://leetcode.com/problems/last-stone-weight-ii/discuss/1272897/Simple-Java-implementation-or-Knapsack
*/

/*
Solution 1:

Time complexity: O(2^n)
Space complexity: O(2^n)
*/

class Solution
{
    public:
        int lastStoneWeightII(vector<int> & stones)
        {
            int result=0;
            
            int n=stones.size();
            
            int index=0;
            
            int sum=0;
            
            result=helper(stones, n, sum, index);
            
            return result;
        }
    
        int helper(vector<int> & stones, int n, int sum, int index)
        {
            if(index==n)
            {
                return abs(sum);
            }
            
            int subproblemSolution=numeric_limits<int>::max();
            
            int addStoneWeight=helper(stones, n, sum + stones[index], index + 1);
            
            int subtractStoneWeight=helper(stones, n, sum - stones[index], index + 1);
            
            subproblemSolution=min(addStoneWeight, subtractStoneWeight);
            
            return subproblemSolution;
        }
};

/*
Solution 2:

Time complexity: O(n log(sum))
Space complexity: O(n * sum)
*/

class Solution
{
    public:
        int lastStoneWeightII(vector<int> & stones)
        {
            int result=0;
            
            int n=stones.size();
            
            map<pair<int, int>, int> memo;
            
            int index=0;
            
            int sum=0;
            
            result=helper(stones, memo, n, sum, index);
            
            return result;
        }
    
        int helper(vector<int> & stones, map<pair<int, int>, int> & memo, int n, int sum, int index)
        {
            if(index==n)
            {
                return abs(sum);
            }
            
            if(memo.find({sum, index})!=end(memo))
            {
                return memo[{sum, index}];
            }
            
            int subproblemSolution=numeric_limits<int>::max();
            
            int addStoneWeight=helper(stones, memo, n, sum + stones[index], index + 1);
            
            int subtractStoneWeight=helper(stones, memo, n, sum - stones[index], index + 1);
            
            subproblemSolution=min(addStoneWeight, subtractStoneWeight);
            
            memo.emplace(make_pair(sum, index), subproblemSolution);
            
            return subproblemSolution;
        }
};