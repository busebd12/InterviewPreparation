#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Treat each index in the vector as a potential pivot index and caclulate the
 * left and right sums. If the left sum equals the right sum, this is a pivot index. We want to
 * return the minimum pivot index.
 *
 * Time complexity: O(n-squared) [where n is the size of the input vector]
 * Space complexity: O(1)
 *
 * 2) Using prefix sums. For each index in the input vector, we calculate the prefix sum for that index.
 * Then, for each index in nums, we derive the left sum and the right sum using the prefix sums.
 * If the left sum equals the right sum, then we have found a pivot index. We want to return the minimum pivot index.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n)
 */

int pivotIndex(vector<int> & nums)
{
    int result=-1;

    size_t n=nums.size();

    for(size_t i=0;i<n;++i)
    {
        int leftSum=0;

        for(size_t left=0;left<i;++left)
        {
            leftSum+=nums[left];
        }

        int rightSum=0;

        for(size_t right=i+1;right<n;++right)
        {
            rightSum+=nums[right];
        }

        if(leftSum==rightSum)
        {
            if(result==-1)
            {
                result=i;
            }
            else
            {
                result=min(result, int(i));
            }
        }
    }

    return result;
}

int pivotIndex(vector<int> & nums)
{
    int result=-1;

    if(nums.empty())
    {
        return result;
    }

    size_t n=nums.size();

    vector<int> prefixSums(n, 0);

    prefixSums[0]=nums[0];

    for(size_t index=1;index<n;++index)
    {
        prefixSums[index]=prefixSums[index-1] + nums[index];
    }

    for(size_t index=0;index<n;++index)
    {
        int leftSum=(index==0) ? 0 : prefixSums[index-1];

        int rightSum=prefixSums[n-1] - prefixSums[index];

        if(leftSum==rightSum)
        {
            result==-1 ? result=index : min(result, int(index));
        }
    }

    return result;
}