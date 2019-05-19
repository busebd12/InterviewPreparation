#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findDuplicatesExtraSpace(vector<int> & nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    unordered_map<int, int> table;

    for(auto & number : nums)
    {
        table[number]++;
    }

    for(auto & element : table)
    {
        if(element.second==2)
        {
            result.emplace_back(element.first);
        }
    }

    return result;
}

vector<int> findDuplicates(vector<int> & nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        int index=abs(nums[i])-1;

        if(nums[index] < 0)
        {
            result.emplace_back(abs(index+1));
        }

        nums[index]=-nums[index];
    }

    return result;
}