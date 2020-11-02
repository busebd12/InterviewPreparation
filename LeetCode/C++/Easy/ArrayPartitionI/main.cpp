#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Approach: sort the input vector and sum up the the numbers at even indices in the vector.
 *
 * Time complexity: O(n log n) [where n is the length of numbers in the input vector]
 * Space complexity: O(1)
 */

int arrayPairSum(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    sort(nums.begin(), nums.end());

    for(int i=0;i<n;++i)
    {
        if(i%2==0)
        {
            result+=nums[i];
        }
    }

    return result;
}