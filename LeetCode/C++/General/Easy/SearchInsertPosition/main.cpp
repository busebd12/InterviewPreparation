#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * First, do a linear scan of the vector.
 * If we find the number, set result to the index.
 * If we find a number greater than the target, set result to that index.
 * After the for loop, if we still haven't found the number, then it must be
 * greater than the largest value in the vector.
 * In that case, just make the target the new last number in the array.
 *
 * Time Complexity: O(n) [where n is the size of the input vector]
 *
 * Space Complexity: O(1)
 *
 * Second, use binary search to search the vector for our target.
 * If we find it, return the index.
 * Else, use binary search to search for the number larger than target with the smallest index.
 * If we don't find that index, set the result to be the index of the last number.
 *
 * Time Complexity: O(log n)
 *
 * Space Complexity: O(1)
 */

int searchInsert(vector<int> & nums, int target)
{
    if(nums.empty())
    {
        return 0;
    }

    int result=-1;

    int n=int(nums.size());

    for(int index=0;index<n;++index)
    {
        if(nums[index]==target)
        {
            result=index;

            break;
        }

        if(nums[index] > target)
        {
            if(index==0)
            {
                result=0;

                break;
            }
            else
            {
                result=index;

                break;
            }
        }
    }

    if(nums[n-1] < target)
    {
        result=n;
    }

    return result;
}

int binarySearch(vector<int> & nums, int low, int high, int target)
{
    while(low <= high)
    {
        int middle=(low + ((high-low))/2);

        if(nums[middle]==target)
        {
            return middle;
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

    return -1;
}

void getIndex(vector<int> & nums, int low, int high, int target, int & index)
{
    while(low <= high)
    {
        int middle=low + ((high-low)/2);

        if(nums[middle] > target)
        {
            if(index==-1)
            {
                index=middle;
            }
            else
            {
                if(middle < index)
                {
                    index=middle;
                }
            }

            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }
}

int searchInsert(vector<int> & nums, int target)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size()-1);

    int low=0;

    int high=n;

    int result=binarySearch(nums, low, high, target);

    if(result==-1)
    {
        int index=-1;

        getIndex(nums, low, high, target, index);

        if(index==-1)
        {
            result=n+1;
        }
        else
        {
            result=index;
        }
    }

    return result;
}