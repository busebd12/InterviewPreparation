#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    size_t numsSize=nums.size();

    if(numsSize==1)
    {
        return nums[0];
    }

    if(numsSize==2)
    {
        return max(nums[0], nums[1]);
    }

    if(numsSize==3)
    {
        return max(max(nums[0], nums[1]), max(nums[1], nums[2]));
    }

    int evenHouseTotal=0;

    int oddHouseTotal=0;

    int includeTheFirstHouse=0;

    int excludeTheFirstHouse=0;

    for(size_t i=0;i<numsSize-1;++i)
    {
        if(i%2==0)
        {
            evenHouseTotal=max(evenHouseTotal+nums[i], oddHouseTotal);
        }
        else
        {
            oddHouseTotal=max(oddHouseTotal+nums[i], evenHouseTotal);
        }
    }

    includeTheFirstHouse=max(evenHouseTotal, oddHouseTotal);

    evenHouseTotal=0;

    oddHouseTotal=0;

    for(size_t i=1;i<numsSize;++i)
    {
        if(i%2==0)
        {
            evenHouseTotal=max(evenHouseTotal+nums[i], oddHouseTotal);
        }
        else
        {
            oddHouseTotal=max(oddHouseTotal+nums[i], evenHouseTotal);
        }
    }

    excludeTheFirstHouse=max(evenHouseTotal, oddHouseTotal);

    int answer=max(includeTheFirstHouse, excludeTheFirstHouse);

    return answer;
}