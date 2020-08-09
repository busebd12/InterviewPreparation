#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Merge sort. See this video --> https://www.youtube.com/watch?v=TzeBrDU-JaY&t=851s
 *
 * Time complexity: O(n * log(n))
 * Space complexity: O(n)
 *
 * 2. Quicksort. See this video --> https://www.youtube.com/watch?v=7h1s2SojIRw
 *
 * Time complexity: O(n * log(n))
 * Space complexity: O(log(n)) recursive stack space
 */

class Solution
{
    public:
        void mergeHelper(std::vector<int> & nums, std::vector<int> & leftHalf, std::vector<int> & rightHalf)
        {
            int leftHalfSize=int(leftHalf.size());

            int rightHalfSize=int(rightHalf.size());

            int i=0;

            int j=0;

            while(i < leftHalfSize && j < rightHalfSize)
            {
                if(leftHalf[i] <= rightHalf[j])
                {
                    nums.emplace_back(leftHalf[i]);

                    i++;
                }
                else
                {
                    nums.emplace_back(rightHalf[j]);

                    j++;
                }
            }

            while(i < leftHalfSize)
            {
                nums.emplace_back(leftHalf[i]);

                i++;
            }

            while(j < rightHalfSize)
            {
                nums.emplace_back(rightHalf[j]);

                j++;
            }
        }

        void mergeSort(std::vector<int> & nums)
        {
            if(nums.size() < 2)
            {
                return;
            }

            std::vector<int> leftHalf;

            std::vector<int> rightHalf;

            int middle=int(nums.size())/2;

            for(int i=0;i<middle;i++)
            {
                leftHalf.emplace_back(nums[i]);
            }

            for(int j=middle;j<int(nums.size());j++)
            {
                rightHalf.emplace_back(nums[j]);
            }

            mergeSort(leftHalf);

            mergeSort(rightHalf);

            nums.clear();

            mergeHelper(nums, leftHalf, rightHalf);
        }

        std::vector<int> sortArray(std::vector<int> & nums)
        {
            mergeSort(nums);

            return nums;
        }
};

class Solution
{
    public:
        int partition(std::vector<int> & nums, int start, int end)
        {
            int pivot=nums[start];

            int i=start;

            int j=end;

            while(i < j)
            {
                while(i < end && nums[i] <= pivot)
                {
                    i++;
                }

                while(j > 0 && nums[j] > pivot)
                {
                    j--;
                }

                if(i < j)
                {
                    std::swap(nums[i], nums[j]);
                }
            }

            std::swap(nums[start], nums[j]);

            return j;
        }

        void quicksort(std::vector<int> & nums, int start, int end)
        {
            if(start >= end)
            {
                return;
            }

            int partitionIndex=partition(nums, start, end);

            quicksort(nums, start, partitionIndex - 1);

            quicksort(nums, partitionIndex + 1, end);
        }

        std::vector<int> sortArray(std::vector<int> & nums)
        {
            int start=0;

            int end=int(nums.size() - 1);

            quicksort(nums, start, end);

            return nums;
        }
};