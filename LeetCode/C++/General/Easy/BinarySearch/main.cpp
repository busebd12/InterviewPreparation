#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Binary search, iteratively.
 *
 * Time complexity: O(log(n)) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2) Binary search, recursively
 *
 * Time complexity: O(log(n)) [where n is the length of the input vector]
 * Space complexity: O(log(n)) recursive stack space
 */

int search(vector<int> & nums, int target)
{
    int result=-1;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    int low=0;

    int high=n-1;

    while(low <= high)
    {
        int middle=(low + (high - low)/2);

        if(nums[middle]==target)
        {
            result=middle;

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

    return result;
}

void helper(vector<int> & nums, int low, int high, const int & target, int & result)
{
    if(low > high)
    {
        return;
    }

    int middle=(low + (high - low)/2);

    if(nums[middle]==target)
    {
        result=middle;

        return;
    }
    else if(nums[middle] > target)
    {
        helper(nums, low, middle-1, target, result);
    }
    else
    {
        helper(nums, middle+1, high, target, result);
    }
}

int search(vector<int> & nums, int target)
{
    int result=-1;

    if(nums.empty())
    {
        return -1;
    }

    int n=int(nums.size());

    int low=0;

    int high=n-1;

    helper(nums, low, high, target, result);

    return result;
}