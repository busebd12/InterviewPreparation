#include <iostream>
#include <vector>

/*
 * Solution: we find the pivot index of the input vector using binary search and then perform two binary searches,
 * one in the portion of the vector defined as [0, pivot index] and one in the portion [pivot index, end of the vector]
 * for the target number.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

int findPivotIndex(std::vector<int> & nums)
{
    int left=0;

    int right=int(nums.size()-1);

    int pivotIndex=-1;

    while(left <= right)
    {
        int middle=(left + (right - left)/2);

        if(nums[middle] > nums[middle+1])
        {
            pivotIndex=middle+1;

            break;
        }
        else if(nums[middle] < nums[middle-1])
        {
            pivotIndex=middle-1;

            break;
        }
        else if(nums[left] < nums[middle])
        {
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }

    return pivotIndex;
}

void binarySearch(std::vector<int> & nums, int target, int left, int right, int & index)
{
    while(left <= right)
    {
        int middle=(left + (right - left)/2);

        if(nums[middle]==target)
        {
            index=middle;

            break;
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
}

int search(std::vector<int> & nums, int target)
{
    int index=-1;

    if(nums.empty())
    {
        return index;
    }

    int n=int(nums.size());

    if(n==1)
    {
        return (nums[0]==target) ? 0 : -1;
    }

    if(*(nums.begin()) < *(nums.rbegin()))
    {
        binarySearch(nums, target, 0, n-1, index);

        return index;
    }

    int pivotIndex=findPivotIndex(nums);

    bool found=false;

    binarySearch(nums, target, 0, pivotIndex, index);

    if(index!=-1)
    {
        found=true;
    }

    if(!found)
    {
        binarySearch(nums, target, pivotIndex, n-1, index);
    }

    return index;
}