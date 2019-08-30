#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
 * Approach: As we are looping over the vector, if we see a one, increment our count.
 * If we see a zero, then result will be the max of result and count, and we reset count.
 * After the loop, if the last number we saw was a one, count is greater than zero,
 * but never was compared against result to see if it's bigger, so do one final comparison.
 *
 * Time complexity: O(n) [where n is the input vector size]
 * Space complexity: O(1)
 */

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int result=-1;

    if(nums.empty())
    {
        return 0;
    }

    int count=0;

    for(int number : nums)
    {
        if(number==1)
        {
            count++;
        }
        else
        {
            result=max(result, count);

            count=0;
        }
    }

    result=max(result, count);

    return result;
}