#include <cmath>
#include <iostream>
#include <vector>

/*
 * Solution: we use a "two-pointer" approach. First, we handle some outlier cases.
 *
 * 1) The given vector is empty --> the length is zero.
 * 2) The given vector has one number --> if the number is greater than or equal to s, the length is one.
 * Else, the length is zero.
 * 3) If either of the first two numbers in the vector are greater than or equal to s, the length is one.
 *
 * Then, we move onto the general case. We maintain a sliding-window sum as we iterate through the vector
 * using two pointers. As we iterate through the vector, if the slinding-window sum is less than s, we add
 * another number to the sum (move the front pointer up by one). Else, we subtract the last number in our
 * sliding window from our sum (move the back pointer up by one). When the front pointer reaches the last
 * index in our vector, we can only move the back pointer up until it reaches the end of the vector as well.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 */

int minSubArrayLen(int s, std::vector<int> & nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    auto n=nums.size();

    if(n==1)
    {
        return (nums[0] >= s) ? 1 : result;
    }

    std::size_t front=1;

    std::size_t back=0;

    if(nums[back] >= s || nums[front] >= s)
    {
        return 1;
    }

    int sum=nums[back] + nums[front];

    while(true)
    {
        if(sum >= s)
        {
            int length=static_cast<int>((front - back) + 1);

            if(!result)
            {
                result=length;
            }
            else
            {
                result=std::min(result, length);
            }
        }

        if(front + 1 < n)
        {
            if(sum < s)
            {
                front++;

                sum+=nums[front];
            }
            else
            {
                sum-=nums[back];

                back++;
            }
        }
        else
        {
            if(back==n-1)
            {
                break;
            }

            sum-=nums[back];

            back++;
        }
    }

    return result;
}