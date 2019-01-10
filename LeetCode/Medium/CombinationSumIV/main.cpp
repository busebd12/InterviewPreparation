#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

int helperDP(vector<int> & nums, vector<int> & dp, int & target)
{
    if(dp[target]!=-1)
    {
        return dp[target];
    }

    int result=0;

    for(int i=0;i<nums.size();++i)
    {
        if(nums[i] <= target)
        {
            int smallerTarget=target-nums[i];

            result+=helperDP(nums, dp, smallerTarget);
        }
    }

    dp[target]=result;

    return result;
}

int helper(vector<int> & nums, int & target)
{
    if(target==0)
    {
        return 1;
    }

    int result=0;

    for(int i=0;i<nums.size();++i)
    {
        if(nums[i] <= target)
        {
            int smallerTarget=target-nums[i];

            result+=helper(nums, smallerTarget);
        }
    }

    return result;
}

int combinationSum4(vector<int> & nums, int target)
{
    if(nums.empty() || target==0)
    {
        return 0;
    }

    vector<int> dp(target+1, -1);

    dp[0]=1;

    int combinations=helper(nums, target);

    //int combinations=helperDP(nums, dp, target);

    return combinations;
}