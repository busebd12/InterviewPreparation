#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Approach: calculate the maximum number in the nums vector. Then, check each number in the nums
 * vector that is not the maximum element and see if it is twice more than twice as large as the maximum
 * number. If it is, then we know that the maximum number is not at least twice as large as the rest of the
 * number in nums and mark our boolean flag, largestTwiceAsLarge, as false. After we finishing iterating over
 * nums, if the largest number is at least twice as large as the rest of the numbers in nums, calculate the
 * index for the maximum number.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int dominantIndex(vector<int> & nums)
{
    int result=-1;

    if(nums.empty())
    {
        return result;
    }

    auto maxElement=max_element(nums.begin(), nums.end());

    int largest=*maxElement;

    bool largestTwiceAsLarge=true;

    for(int & number : nums)
    {
        if(number!=largest)
        {
            if(number * 2 > largest)
            {
                largestTwiceAsLarge=false;

                break;
            }
        }
    }

    if(largestTwiceAsLarge)
    {
        result=maxElement - nums.begin();
    }

    return result;
}