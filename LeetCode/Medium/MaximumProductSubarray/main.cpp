#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxProduct(vector<int> & nums)
{
    int answer=nums[0];

    if(nums.empty())
    {
        return answer;
    }

    int numsSize=int(nums.size());

    int currentMaxProduct=nums[0];

    int currentMinProduct=nums[0];

    int previousMaxProduct=nums[0];

    int previousMinProduct=nums[0];

    for(int i=1;i<numsSize;++i)
    {
        currentMaxProduct = max(previousMaxProduct * nums[i], max(previousMinProduct * nums[i], nums[i]));

        currentMinProduct = min(previousMaxProduct * nums[i], min(previousMinProduct * nums[i], nums[i]));

        answer = max(answer, currentMaxProduct);

        previousMaxProduct = currentMaxProduct;

        previousMinProduct = currentMinProduct;
    }

    return answer;
}