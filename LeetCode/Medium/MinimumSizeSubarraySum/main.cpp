#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int minSubArrayLen(int s, vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int sum=0;

    int i=0;

    int j=0;

    int length=numeric_limits<int>::max();

    size_t numsSize=nums.size();

    while(i < numsSize)
    {
        sum+=nums[i++];

        while(sum >= s)
        {
            length=min(length, i-j);

            sum-=nums[j++];
        }
    }

    return ((length==numeric_limits<int>::max()) ? 0 : length);
}