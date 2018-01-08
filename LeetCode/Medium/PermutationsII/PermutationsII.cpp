#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<vector<int>> & permutations, vector<int> permutation, vector<bool> & used, vector<int> nums)
{
    if(permutation.size()==nums.size())
    {
        permutations.emplace_back(permutation);
    }
    else
    {
        for(int index=0;index<nums.size();++index)
        {
            if(used[index] || (index > 0 && nums[index]==nums[index-1] && used[index-1]))
            {
                continue;
            }

            used[index]=true;

            permutation.emplace_back(nums[index]);

            backtrack(permutations, permutation, used, nums);

            used[index]=false;

            permutation.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> & nums)
{
    vector<vector<int>> permutations;

    if(nums.empty())
    {
        return permutations;
    }

    if(!is_sorted(begin(nums), end(nums)))
    {
        sort(begin(nums), end(nums));
    }

    vector<int> permutation;

    vector<bool> used(nums.size(), false);

    backtrack(permutations, permutation, used, nums);

    return permutations;
}