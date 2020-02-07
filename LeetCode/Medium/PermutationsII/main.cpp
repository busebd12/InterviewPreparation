#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Using the same code that generates permutations except that we use a set<vector<int>>, distinct, to make sure that
 * we only have distinct permutations.
 *
 * Time complexity: O(log n * n!)
 * Space complexity: O(n!)
 *
 * 2. We can get rid of the set once we make the following observation:
 *
 * A number which is equal to its previous number can be used only if its previous number has already been used,
 * in this way we can make sure that in the resulting permutations, groups of same numbers will always have the same
 * ordering between them. Thus we no longer have the problems of duplicates resulting permutations.
 *
 * Thus, we don't choose a number if we've used it before or if the duplicate of it that occurs before
 * the current in the vector hasn't been used before.
 *
 * Time complexity: O(n!)
 * Space complexity: O(n! + n)
 */

void backtracking(std::vector<int> & nums, std::set<std::vector<int>> & distinct, std::vector<int> permutation, std::unordered_set<int> & skipIndices, const int & targetLength, int start)
{
    if((int)permutation.size()==targetLength)
    {
        if(!distinct.count(permutation))
        {
            distinct.insert(permutation);
        }
    }

    for(int i=0;i<targetLength;++i)
    {
        if(!skipIndices.count(i))
        {
            permutation.push_back(nums[i]);

            skipIndices.insert(i);

            backtracking(nums, distinct, permutation, skipIndices, targetLength, i+1);

            skipIndices.erase(i);

            permutation.pop_back();
        }
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> & nums)
{
    std::vector<std::vector<int>> permutations;

    if(nums.empty())
    {
        return permutations;
    }

    std::sort(nums.begin(), nums.end());

    int targetLength=int(nums.size());

    std::vector<int> permutation;

    std::set<std::vector<int>> distinct;

    std::unordered_set<int> skipIndices;

    int start=0;

    backtracking(nums, distinct, permutation, skipIndices, targetLength, start);

    for(const auto & permutation : distinct)
    {
        permutations.push_back(permutation);
    }

    return permutations;
}

void backtracking(std::vector<int> & nums, std::vector<std::vector<int>> & permutations, std::vector<int> permutation, std::vector<bool> & used, const int & targetLength, int start)
{
    if((int)permutation.size()==targetLength)
    {
        permutations.push_back(permutation);
    }

    for(int i=0;i<targetLength;++i)
    {
        if(used[i] || (i > 0 && nums[i]==nums[i-1] && !used[i-1]))
        {
            continue;
        }

        permutation.push_back(nums[i]);

        used[i]=true;

        backtracking(nums, permutations, permutation, used, targetLength, i+1);

        used[i]=false;

        permutation.pop_back();
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> & nums)
{
    std::vector<std::vector<int>> permutations;

    if(nums.empty())
    {
        return permutations;
    }

    std::sort(nums.begin(), nums.end());

    int targetLength=int(nums.size());

    std::vector<int> permutation;

    std::vector<bool> used(targetLength, false);

    int start=0;

    backtracking(nums, permutations, permutation, used, targetLength, start);

    return permutations;
}