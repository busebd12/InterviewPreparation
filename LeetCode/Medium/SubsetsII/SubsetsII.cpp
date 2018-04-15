#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtracking(vector<vector<int>> & subsets, vector<int> subset, vector<int> nums, int start)
{
    subsets.emplace_back(subset);

    int numsSize=int(nums.size());

    for(int i=start;i<numsSize;++i)
    {
        if(i==start || nums[i]!=nums[i-1])
        {
            subset.emplace_back(nums[i]);

            backtracking(subsets, subset, nums, i+1);

            subset.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int> & nums)
{
    vector<vector<int>> subsets;

    sort(begin(nums), end(nums));

    int start=0;

    vector<int> subset;

    backtracking(subsets, subset, nums, start);

    return subsets;
}