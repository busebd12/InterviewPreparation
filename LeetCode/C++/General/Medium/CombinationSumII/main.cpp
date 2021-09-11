#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution: we use backtracking together with a running sum to generate all the possible combinations.
 * We also have two cases in which we prune:
 *
 * 1. when we skip duplicate elements
 * 2. when the current number plus our running sum is greater than the target sum, we can return from
 * our current level of recursion since any number after this one will also make our sum too large.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 */

void backtracking(std::vector<int> & candidates, std::vector<std::vector<int>> & result, std::vector<int> combination, const int & target, const int & n, int sum, int start)
{
    if(sum==target)
    {
        result.push_back(combination);

        return;
    }

    for(int i=start;i<n;++i)
    {
        if(sum + candidates[i] > target)
        {
            return;
        }

        if(i > start && candidates[i]==candidates[i-1])
        {
            continue;
        }

        sum+=candidates[i];

        combination.push_back(candidates[i]);

        backtracking(candidates, result, combination, target, n, sum, i+1);

        sum-=candidates[i];

        combination.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> & candidates, int target)
{
    std::vector<std::vector<int>> result;

    if(candidates.empty())
    {
        return result;
    }

    std::sort(candidates.begin(), candidates.end());

    std::vector<int> combination;

    const int n=int(candidates.size());

    int start=0;

    int sum=0;

    backtracking(candidates, result, combination, target, n, sum, start);

    return result;
}