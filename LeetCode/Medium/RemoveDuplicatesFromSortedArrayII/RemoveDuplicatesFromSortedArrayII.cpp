#include <iostream>
#include <vector>
#include <map>
using namespace std;

void helper(const vector<int> & nums, vector<int> & result)
{
    map<int, int> counts;

    int threshold=2;

    for(const auto & number : nums)
    {
        counts[number]++;
    }

    for(auto & element : counts)
    {
        int allowed=element.second;

        if(allowed > threshold)
        {
            int difference=abs(allowed-threshold);

            allowed-=difference;
        }

        for(int count=0;count<allowed;++count)
        {
            result.emplace_back(element.first);
        }
    }
}

int removeDuplicates(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    const int numsSize=int(nums.size());

    if(numsSize==1)
    {
        return numsSize;
    }

    vector<int> result;

    helper(nums, result);

    nums.clear();

    for(const auto & element : result)
    {
        nums.emplace_back(element);
    }

    return int(nums.size());
}