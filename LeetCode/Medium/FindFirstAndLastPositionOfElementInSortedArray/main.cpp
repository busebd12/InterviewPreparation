#include <iostream>
#include <vector>

/*
 * Solution: We use binary search to find the starting and ending indices for the range of target numbers.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

int findEnd(std::vector<int> & nums, int target)
{
    int index=-1;

    int n=int(nums.size());

    int left=0;

    int right=n-1;

    while(left <= right)
    {
        int middle=(left + (right - left)/2);

        if(nums[middle]==target)
        {
            if(middle==n-1 && n==1)
            {
                index=middle;

                break;
            }
            else if(middle==n-1 && nums[middle-1]==target)
            {
                index=middle;

                break;
            }
            else if(middle > 0 && nums[middle-1]==target && nums[middle+1] > target)
            {
                index=middle;

                break;
            }
            else if(middle==0 && nums[middle+1] > target)
            {
                index=middle;

                break;
            }
            else if(middle==n-1 && nums[middle-1] < target)
            {
                index=middle;

                break;
            }
            else if(middle > 0 && middle < n-1 && nums[middle-1] < target && target < nums[middle+1])
            {
                index=middle;

                break;
            }
            else
            {
                left=middle+1;
            }
        }
        else if(nums[middle] < target)
        {
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }

    return index;
}

int findStart(std::vector<int> & nums, int target)
{
    int index=-1;

    int left=0;

    int right=int(nums.size()-1);

    while(left <= right)
    {
        int middle=(left + (right - left)/2);

        if(nums[middle]==target)
        {
            if(middle==0 || nums[middle] > nums[middle-1])
            {
                index=middle;

                break;
            }
            else
            {
                if(middle > 0)
                {
                    right=middle-1;
                }
            }
        }
        else if(nums[middle] < target)
        {
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }

    return index;
}

std::vector<int> searchRange(std::vector<int> & nums, int target)
{
    std::vector<int> result(2, -1);

    if(nums.empty())
    {
        return result;
    }

    int startIndex=findStart(nums, target);

    if(startIndex==-1)
    {
        return result;
    }

    int endIndex=findEnd(nums, target);

    if(endIndex==-1)
    {
        return result;
    }

    result[0]=startIndex;

    result[1]=endIndex;

    return result;
}