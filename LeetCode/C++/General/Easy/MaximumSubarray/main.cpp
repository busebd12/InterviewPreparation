#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approach:
 *
 * Solved using Kadane’s Algorithm. See the links below for explanations.
 * https://hackernoon.com/kadanes-algorithm-explained-50316f4fd8a6
 * https://en.wikipedia.org/wiki/Maximum_subarray_problem
 * https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 *
 * Space Complexity: O(1)
 */

int maxSubArray(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    if(nums.size()==1)
    {
        return nums[0];
    }

    int maxSum=nums[0];

    int sumEndingHere=nums[0];

    int n=int(nums.size());

    for(int i=1;i<n;++i)
    {
        int current=nums[i];

        sumEndingHere=max((sumEndingHere + current), current);

        maxSum=max(maxSum, sumEndingHere);
    }

    return maxSum;
}