#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findPairs(vector<int>& nums, int k)
{
    if(nums.empty() || k < 0)
    {
        return 0;
    }

    unordered_map<int,int> cache;

    unordered_map<int, int> frequency;

    for(const auto & number : nums)
    {
        int target=number+k;

        if(cache.find(target)==end(cache))
        {   
            cache.emplace(target, number);
        }

        frequency[number]++;
    }

    int pairs=0;

    for(auto & element : cache)
    {   
        if(element.first==element.second)
        {
            if(frequency[element.first] > 1)
            {
                ++pairs;

                frequency[element.first]--;
            }
        }
        else
        {
            if(frequency.find(element.first)!=end(frequency))
            {
                ++pairs;
            }
        }
    }

    return pairs;
}