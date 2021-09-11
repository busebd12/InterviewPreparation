#include <iostream>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. For each number in the input vector, we form all sub-arrays that start with this number and calculate their sums.
 * If a sub-array sum is k, increment our result integer. Return our result integer.
 *
 * Time complexity: O(n^2) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2. Inspire from this solution: https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */


int subarraySum(std::vector<int> & nums, int k)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    auto n=nums.size();

    for(auto subarrayStart=0;subarrayStart<n;++subarrayStart)
    {
        int subarraySum=nums[subarrayStart];

        if(subarraySum==k)
        {
            result++;
        }

        for(auto i=subarrayStart+1;i<n;++i)
        {
            subarraySum+=nums[i];

            if(subarraySum==k)
            {
                result++;
            }
        }
    }

    return result;
}

int subarraySum(std::vector<int> & nums, int k)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    auto n=nums.size();

    std::unordered_multiset<int> sums;

    int sum=0;

    for(auto i=0;i<n;++i)
    {
        sum+=nums[i];

        if(sum==k)
        {
            result++;
        }

        result+=sums.count(sum - k);

        sums.insert(sum);
    }

    return result;
}