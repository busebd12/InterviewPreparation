#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Sort the input vector. Then, there are two cases to consider. Either, the maximum
 * product will be the product of the 3 biggest positive values, or the maximum product
 * will be the product of the two largest negative values and the largest positive value.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2) Use from the partial sort algorithm from the STL to put the two smallest numbers
 * in the first two spots of the array. Then, use partial sort, again, to put the three largest
 * numbers in the first three sports in the vector. Then, just apply the same logic as the first
 * solution.
 *
 * Time complexity: O(n log m) [where n is the length of the input vector and m is the distance between the first and middle element]
 * Space complexity: O(1)
 */

int maximumProduct(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    if(n < 3)
    {
        return result;
    }

    sort(nums.begin(), nums.end());

    int first=nums[n-1] * nums[0] * nums[1];

    int second=nums[n-1] * nums[n-2] * nums[n-3];

    return max(first, second);
}

int maximumProduct(vector<int> & nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    if(n < 3)
    {
        return result;
    }

    partial_sort(nums.begin(), nums.begin()+2, nums.end());

    int min1=nums[0];

    int min2=nums[1];

    partial_sort(nums.begin(), nums.begin()+3, nums.end(), greater<>());

    int max1=nums[0];

    int max2=nums[1];

    int max3=nums[2];

    int first=max1 * min1 * min2;

    int second=max1 * max2 * max3;

    return max(first, second);
}