#include <iostream>
#include <unordered_set>
#include <vector>

/*
 * Solution: we use backtracking to generate all the permutations. However, since we want our permutations
 * to not have any duplicate numbers, we use an unordered_set<int>, skipIndices, to track which indices
 * we have visited before so we can skip them in the future.
 *
 * Time complexity: O(n!)
 * Space complexity: O(n!)
 */

void backtracking(std::vector<int> & nums, std::vector<std::vector<int>> & permutations, std::vector<int> permutation, std::unordered_set<int> & skipIndices, const int & targetLength, int start)
{
    if(permutation.size()==targetLength)
    {
        permutations.push_back(permutation);
    }

    for(int i=0;i<targetLength;++i)
    {
        if(!skipIndices.count(i))
        {
            permutation.push_back(nums[i]);

            skipIndices.insert(i);

            backtracking(nums, permutations, permutation, skipIndices, targetLength, i+1);

            skipIndices.erase(i);

            permutation.pop_back();
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int> & nums)
{
    std::vector<std::vector<int>> permutations;

    if(nums.empty())
    {
        return permutations;
    }

    int targetLength=int(nums.size());

    std::vector<int> permutation;

    std::unordered_set<int> skipIndices;

    int start=0;

    backtracking(nums, permutations, permutation, skipIndices, targetLength, start);

    return permutations;
}