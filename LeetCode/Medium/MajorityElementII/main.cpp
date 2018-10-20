#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    unordered_map<int, int> frequencies;

    for(const auto & element : nums)
    {
        frequencies[element]++;
    }

    int target=n/3;

    for(const auto & element : frequencies)
    {
        if(element.second > target)
        {
            result.emplace_back(element.first);
        }
    }

    return result;
}