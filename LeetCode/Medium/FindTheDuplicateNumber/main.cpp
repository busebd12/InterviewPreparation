#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    if(nums.empty())
    {
        return -1;
    }

    sort(begin(nums), end(nums));

    int numsSize=static_cast<int>(nums.size());

    int answer=-1;

    for(int i=1;i<numsSize;++i)
    {
        if(nums[i]==nums[i-1])
        {
            answer=nums[i];

            break;
        }
    }

    return answer;
}