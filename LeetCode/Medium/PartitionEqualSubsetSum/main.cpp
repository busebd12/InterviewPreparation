#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool dfs(vector<int> & nums, int sum, int index)
{
    if(index >= nums.size())
    {
        return false;
    }

    if(nums[index]==sum)
    {
        return true;
    }

    if(nums[index] > sum)
    {
        return false;
    }

    return dfs(nums, sum-nums[index], index+1) || dfs(nums, sum, index+1);
}

bool canPartition(vector<int> & nums)
{
    if(nums.empty())
    {
        return false;
    }

    int sum=accumulate(begin(nums), end(nums), 0);

    if(sum%2==1)
    {
        return false;
    }

    sort(nums.rbegin(), nums.rend());

    sum/=2;

    int index=0;

    return dfs(nums, sum, index);
}