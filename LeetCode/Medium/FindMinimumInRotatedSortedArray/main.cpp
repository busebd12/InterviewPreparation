#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findMin(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int answer=nums[0];

    int numsSize=int(nums.size());

    for(int i=1;i<numsSize;++i)
    {
        answer=min(answer, nums[i]);
    }

    return answer;
}