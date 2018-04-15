#include <iostream>
#include <vector>
using namespace std;

void printResult(const vector<vector<int>> & result)
{
    if(result.empty())
    {
        cout << "No results" << endl;
    }
    else
    {
        for(const auto & subset : result)
        {
            for(const auto & element : subset)
            {
                cout << element << " ";
            }

            cout << endl;
        }
    }

    cout << endl;
}

void backtracking(vector<vector<int>> & subsets, vector<int> subset, vector<int> nums, int start)
{
    subsets.emplace_back(subset);

    int numsSize=int(nums.size());

    for(int i=start;i<numsSize;++i)
    {
        subset.emplace_back(nums[i]);

        backtracking(subsets, subset, nums, i+1);

        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> & nums)
{
    vector<vector<int>> subsets;

    sort(begin(nums), end(nums));

    int start=0;

    vector<int> subset;

    backtracking(subsets, subset, nums, start);

    return subsets;
}