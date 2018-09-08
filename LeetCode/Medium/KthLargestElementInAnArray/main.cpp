#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int findKthLargest(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return -1;
    }

    unordered_map<int, int> table;

    size_t numsSize=nums.size();

    int minimum=nums[0];

    int maximum=nums[0];

    for(size_t i=0;i<numsSize;++i)
    {
        table[nums[i]]++;

        minimum=min(minimum, nums[i]);

        maximum=max(maximum, nums[i]);
    }

    int count=0;

    int answer=maximum+1;

    for(int current=maximum;current>=minimum;--current)
    {
        if(table.count(current))
        {
            count+=table[current];

            if(count >= k)
            {
                answer=current;

                break;
            }
        }
    }

    return answer;
}