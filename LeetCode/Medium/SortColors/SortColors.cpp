#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> & nums)
{
    if(nums.empty())
    {
        return;
    }

    int reds=0;

    int whites=0;

    int blues=0;

    int numsSize=int(nums.size());

    for(int index=0;index<numsSize;++index)
    {
        switch(nums[index])
        {
            case 0:
                ++reds;
                break;
            case 1:
                ++whites;
                break;
            case 2:
                ++blues;
                break;
        }
    }

    int start=0;

    for(int count=0;count<reds;++count,++start)
    {
        nums[start]=0;
    }

    for(int count=0;count<whites;++start,++count)
    {
        nums[start]=1;
    }

    for(int count=0;count<blues;++start,++count)
    {
        nums[start]=2;
    }
}