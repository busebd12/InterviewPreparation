#include <algorithm>
#include <iostream>

class MountainArray
{
    public:
        int get(int index);
        int length();
};

/*
 * Solution: the algorithm works in three steps
 *
 * 1. Find the peak index using binary search
 *
 * Time complexity: O(log(n)) [where n is the length of the mountain array]
 * Space complexity: O(1)
 *
 * 2. Search for the target element in the left-side of the peak. This search goes from index 0 up to and including the peak index.
 *
 * Time complexity: O(log(n/2))
 * Space complexity: O(1)
 *
 * 3. Search for the target element in the right-side of the peak. This search goes from index peakIndex + 1 till the end of the array.
 *
 * Time complexity: O(log(n/2))
 * Space complexity: O(1)
 *
 * 4. Return the appropriate result. If both the leftSideIndex and rightSideIndex were -1, then the array doesn't contain
 * the target value and we return -1. Else If the leftSideIndex is equal to -1, then we have found the target in the right-side
 * of the peak index and return rightSideIndex. Else If rightSideIndex is equal to -1, then we have found the target in the
 * left-side of the peak index and return leftSideIndex. If both leftSideIndex and rightSideIndex are not -1, then we return
 * the minimum of these two values.
 */
class Solution
{
    public:
        int binarySearchIncreasing(MountainArray & mountainArr, int low, int high, int target)
        {
            while(low <= high)
            {
                int middle=low + (high - low)/2;

                if(mountainArr.get(middle)==target)
                {
                    return middle;
                }
                else if(mountainArr.get(middle) > target)
                {
                    high=middle - 1;
                }
                else
                {
                    low=middle + 1;
                }
            }

            return -1;
        }

        int binarySearchDecreasing(MountainArray & mountainArr, int low, int high, int target)
        {
            while(low <= high)
            {
                int middle=low + (high - low)/2;

                if(mountainArr.get(middle)==target)
                {
                    return middle;
                }
                else if(mountainArr.get(middle) > target)
                {
                    low=middle + 1;
                }
                else
                {
                    high=middle - 1;
                }
            }

            return -1;
        }

        int getPeakIndex(MountainArray & mountainArr, int low, int high)
        {
            while(low <= high)
            {
                int middle=low + (high - low)/2;

                int middleNumber=mountainArr.get(middle);

                int leftNumber=(middle - 1 > 0) ? mountainArr.get(middle - 1) : -1;

                int rightNumber=(middle + 1 < mountainArr.length()) ? mountainArr.get(middle + 1) : -1;

                if(leftNumber < middleNumber && middleNumber > rightNumber)
                {
                    return middle;
                }
                else if(leftNumber < middleNumber)
                {
                    low=middle + 1;
                }
                else if(middleNumber > rightNumber)
                {
                    high=middle - 1;
                }
            }

            return -1;
        }

        int findInMountainArray(int target, MountainArray & mountainArr)
        {
            if(mountainArr.length() < 3)
            {
                return -1;
            }

            int n=int(mountainArr.length());

            int low=0;

            int high=n-1;

            int peakIndex=getPeakIndex(mountainArr, low, high);

            if(peakIndex==-1)
            {
                return -1;
            }

            low=0;

            high=peakIndex;

            int leftSideIndex=binarySearchIncreasing(mountainArr, low, high, target);

            low=peakIndex + 1;

            high=n-1;

            int rightSideIndex=binarySearchDecreasing(mountainArr, low, high, target);

            if(leftSideIndex==-1 && rightSideIndex==-1)
            {
                return -1;
            }
            else if(leftSideIndex==-1)
            {
                return rightSideIndex;
            }
            else if(rightSideIndex==-1)
            {
                return leftSideIndex;
            }

            return std::min(leftSideIndex, rightSideIndex);
        }
};