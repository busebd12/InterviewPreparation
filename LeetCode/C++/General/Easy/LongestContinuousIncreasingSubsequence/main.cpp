#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) For each number in the input vector, find the length of the longest continuous increasing
 * subsequence starting from that position. Take the max of those values.
 *
 * Time complexity: O(n-squared) [where n is the number of elements in our input vector]
 * Space complexity: O(1)
 *
 * 2) Dynamic programming. The two states are the following
 *
 * a) The current element is a part of the longest continuous increasing subsequence, in which case, we add one
 * to the previous length
 *
 * b) The number is the end of the current continuous subsequence. This means that the next subsequence starts at this
 * number and has length 1.
 *
 * Time complexity: O(n) [where n is the number of elements in our input vector]
 * Space complexity: O(n)
 *
 * 3) Same logic as the second solution, except we use the variable count in place of our vector<int>, dp, to keep
 * track of the length of the longest continuous increasing subsequence.
 *
 * Time complexity: O(n) [where n is the number of elements in our input vector]
 * Space complexity: O(1)
 */

int findLengthOfLCIS(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    if(n==1)
    {
        return n;
    }

    for(int i=0;i<n;++i)
    {
        int count=1;

        for(int j=i;j<n;++j)
        {
            if(j+1 < n)
            {
                if(nums[j] < nums[j+1])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }

        result=max(result, count);
    }

    return result;
}

int findLengthOfLCIS(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    if(n==1)
    {
        return n;
    }

    vector<int> dp(n+1, 0);

    dp[0]=1;

    for(int i=1;i<n;++i)
    {
        if(nums[i] > nums[i-1])
        {
            dp[i]=dp[i-1] + 1;
        }
        else
        {
            dp[i]=1;
        }
    }

    result=*(max_element(dp.begin(), dp.end()));

    return result;
}

int findLengthOfLCIS(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    if(n==1)
    {
        return n;
    }

    int count=1;

    for(int i=1;i<n;++i)
    {
        if(nums[i] > nums[i-1])
        {
            count++;
        }
        else
        {
            result=max(result, count);

            count=1;
        }
    }

    result=max(result, count);

    return result;
}