#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

bool find132patternBruteForce(vector<int> & nums)
{
    int n=int(nums.size());

    for(int i=0;i<n-2;++i)
    {
        for(int j=i+1;j<n-1;++j)
        {
            for(int k=j+1;k<n;++k)
            {
                if(nums[i] < nums[j] && nums[j] < nums[k])
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool find132pattern(vector<int> & nums)
{
    int n=int(nums.size());

    int firstNumber=numeric_limits<int>::max();

    for(int j=0;j<n-1;++j)
    {
        firstNumber=min(firstNumber, nums[j]);

        for(int k=j+1;k<n;++k)
        {
            if(firstNumber < nums[k] && nums[k] < nums[j])
            {
                return true;
            }
        }
    }

    return false;
}