#include <iostream>
#include <set>
#include <vector>

/*
 * Solutions:
 *
 * 1. We use backtracking to generate the subsets of the powerset and then use an std::set<std::vector<int>> to
 * only store unique values of the powerset.
 *
 * Time complexity: O(2^n * n log n)
 * Space complexity: O(2^n)
 *
 * 2. Similar to first solution but we skip duplicate elements when iterating over the input vector so that we don't have
 * to use an std::set<std::vector<int>> to filter out duplicate subsets.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 */
void backtracking(std::vector<int> nums, std::set<std::vector<int>> & powerset, std::vector<int> subset, int n, int start)
{
    if(!powerset.count(subset))
    {
        powerset.insert(subset);
    }

    for(auto i=start;i<n;++i)
    {
        subset.push_back(nums[i]);

        backtracking(nums, powerset, subset, n, i+1);

        subset.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> & nums)
{
    std::vector<std::vector<int>> result;

    if(nums.empty())
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());

    std::vector<int> subset;

    std::set<std::vector<int>> powerset;

    int start=0;

    int n=int(nums.size());

    backtracking(nums, powerset, subset, n, start);

    for(const auto & subset : powerset)
    {
        result.push_back(subset);
    }

    return result;
}

void backtracking(std::vector<int> nums, std::vector<std::vector<int>> & powerset, std::vector<int> subset, int n, int start)
{
    powerset.push_back(subset);

    for(auto i=start;i<n;++i)
    {
        if(i > start && nums[i]==nums[i-1])
        {
            continue;
        }

        subset.push_back(nums[i]);

        backtracking(nums, powerset, subset, n, i+1);

        subset.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> & nums)
{
    std::vector<std::vector<int>> powerset;

    if(nums.empty())
    {
        return powerset;
    }

    std::sort(nums.begin(), nums.end());

    std::vector<int> subset;

    int start=0;

    int n=int(nums.size());

    backtracking(nums, powerset, subset, n, start);

    return powerset;
}