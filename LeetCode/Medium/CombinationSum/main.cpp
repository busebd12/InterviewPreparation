#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution: we use backtracking to generate all possible combinations.
 * Since we want our combination to have a sum of target, as we are
 * choosing numbers to add to our combination, if the current number
 * add to our running sum causes the sum to exceeded the target sum,
 * we skip it (pruning). Otherwise, we add the number to our combination
 * and recurse.
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
            continue;
        }

        sum+=candidates[i];

        combination.push_back(candidates[i]);

        backtracking(candidates, result, combination, target, n, sum, i);

        sum-=candidates[i];

        combination.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> & candidates, int target)
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