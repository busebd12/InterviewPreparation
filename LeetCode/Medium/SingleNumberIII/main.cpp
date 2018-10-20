#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> singleNumber(vector<int>& nums)
{
    vector<int> result;

    unordered_map<int, int> cache;

    for(const auto & element : nums)
    {
        cache[element]++;
    }

    for(const auto & element : cache)
    {
        if(element.second==1)
        {
            result.emplace_back(element.first);
        }
    }

    return result;
}