#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Do a linear scan of the input vector and count the number of times the target number appears.
 * If the target number appears more than N/2 times, return true. Else, return false.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2. Binary search. The special case is if the current number is the target number.
 * If this is the case, then we scan from the current position to the left and right
 * and count the number of times the target element appears. Then, we break out of the loop.
 * Finally, we return whether or not the target element appears more than N/2 times.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

bool isMajorityElement(vector<int>& nums, int target)
{
    if(nums.empty())
    {
        return false;
    }

    auto n=nums.size();

    int majority=n/2;

    for(auto i=0;i<n;)
    {
        int current=nums[i];

        if(current==target)
        {
            int count=0;

            while(i < n && current==nums[i])
            {
                count++;

                i++;
            }

            if(count > majority)
            {
                return true;
            }
        }
        else
        {
            ++i;
        }
    }

    return false;
}

bool isMajorityElement(vector<int>& nums, int target)
{
    if(nums.empty())
    {
        return false;
    }

    auto n=nums.size();

    int majority=n/2;

    auto low=0;

    auto high=n-1;

    int count=0;

    while(low < high)
    {
        auto middle=(low + (high - low)/2);

        if(nums[middle]==target)
        {
            int i=middle;

            bool goneUp=false;

            while(i < n && nums[i]==target)
            {
                count++;

                i++;

                goneUp=true;
            }

            int j=middle;

            bool goneDown=false;

            while(j > 0 && nums[j]==target)
            {
                count++;

                j--;

                goneDown=true;
            }

            if(goneUp && goneDown)
            {
                count--;
            }

            break;
        }
        else if(nums[middle] > target)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }

    return count > majority;
}