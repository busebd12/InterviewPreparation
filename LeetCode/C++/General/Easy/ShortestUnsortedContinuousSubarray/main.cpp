#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approach: Create an extra copy of the input vector and sort it. Then, loop over the sorted and unsorted
 * vectors and if the current element in the sorted vector is not equal to the current element in the
 * unsorted vector, increment our result. While we are looping over these two vectors, we also find the
 * lowest and highest index where the two numbers are not the same. After, our first for loop, if
 * low and high are both greater than -1, then we loop over the the two vectors from indices [low, high]
 * and if the current element in the sorted array and the current element in the unsorted array are the same,
 * then this element is a sorted element in the unsorted subarray and we need to increment our result length.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */

int findUnsortedSubarray(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    vector<int> extra(nums.begin(), nums.end());

    sort(extra.begin(), extra.end());

    int n=int(nums.size());

    int low=-1;

    int high=-1;

    for(int i=0;i<n;++i)
    {
        if(nums[i]!=extra[i])
        {
            if(low==-1)
            {
                low=i;
            }

            if(i > low)
            {
                high=i;
            }

            result++;
        }
    }

    if(low > -1 && high > -1)
    {
        for(int j=low;j<=high;++j)
        {
            if(nums[j]==extra[j])
            {
                result++;
            }
        }
    }

    return result;
}