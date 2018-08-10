#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int singleNumber(vector<int> & nums)
{
    unordered_map<int, int> table;

    int numsSize=int(nums.size());

    for(int i=0;i<numsSize;++i)
    {
        table[nums[i]]++;
    }

    for(const auto & element : table)
    {
        if(element.second==1)
        {
            return element.first;
        }
    }
}