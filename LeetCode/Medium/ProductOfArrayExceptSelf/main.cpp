#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> & nums)
{
    vector<int> output(nums.size(), 1);

    int product=1;

    const int numsSize=int(nums.size());

    for(int i=0;i<numsSize;++i)
    {
        output[i]=product;

        product*=nums[i];
    }

    product=1;

    for(int i=numsSize-1;i>=0;--i)
    {
        output[i]*=product;

        product*=nums[i];
    }

    return output;
}