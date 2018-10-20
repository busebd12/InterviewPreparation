#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    if(nums.size()==1)
    {
        return 1;
    }

    int n=static_cast<int>(nums.size());

    vector<int> dp(n, 1);

    for(int i=1;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(nums[i] > nums[j])
            {
                if(dp[j] + 1 > dp[i])
                {
                    dp[i]=dp[j] + 1;
                }
            }
        }
    }

    return *(max_element(begin(dp), end(dp)));
}