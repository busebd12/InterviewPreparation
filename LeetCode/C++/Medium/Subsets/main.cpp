#include <iostream>
#include <vector>

/*
 * Solution: we use recursion + backtracking to generate all subsets of the powerset.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 */

void backtracking(std::vector<int> & nums, std::vector<std::vector<int>> & powerset, std::vector<int> & subset, const int n, int start)
{
    powerset.push_back(subset);

    for(int i=start;i<n;++i)
    {
        subset.push_back(nums[i]);

        backtracking(nums, powerset, subset, n, i+1);

        subset.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> & nums)
{
    std::vector<std::vector<int>> powerset;

    if(nums.empty())
    {
        return powerset;
    }

    const int n=int(nums.size());

    std::sort(nums.begin(), nums.end());

    std::vector<int> subset;

    int start=0;

    backtracking(nums, powerset, subset, n, start);

    return powerset;
}