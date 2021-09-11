#include <cmath>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Using depth-first search. The idea is that for each index we consider all the possible
 * indices that we can reach and try reaching the last index from each of those indices.
 * If we can, we return true. Else, we return false.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n) recursive stack space
 *
 * 2. The basic idea is this: at each step, we keep track of the furthest reachable index.
 * The nature of the problem (eg. maximal jumps where you can hit a range of targets instead of singular jumps where you can only hit one target)
 * is that for an index to be reachable, each of the previous indices have to be reachable.
 * Hence, it suffices that we iterate over each index, and if we ever encounter an index that is not reachable, we abort and return false.
 * By the end, we will have iterated to the last index. If the loop finishes, then the last index is reachable.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 */

bool dfs(std::vector<int> & nums, int n, int index)
{
    if(index > n-1)
    {
        return false;
    }

    if(index==n-1)
    {
        return true;
    }

    for(int distance=1;distance<=nums[index];++distance)
    {
        int next=index + distance;

        if(dfs(nums, n, next))
        {
            return true;
        }
    }

    return false;
}

bool canJump(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return false;
    }

    int n=int(nums.size());

    int index=0;

    return dfs(nums, n, index);
}

bool canJump(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return false;
    }

    int n=int(nums.size());

    int reachableIndex=0;

    for(int index=0;index<n;++index)
    {
        if(index > reachableIndex)
        {
            return false;
        }

        reachableIndex=std::max(reachableIndex, index + nums[index]);
    }

    return true;
}