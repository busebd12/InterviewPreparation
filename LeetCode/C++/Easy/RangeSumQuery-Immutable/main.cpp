#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Calculate the sum for each range.
 *
 * Time complexity: O(length of the range * number of ranges);
 * Space complexity: O(n)
 *
 * 2) Calculate each partial sum of nums ahead of time.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */


class NumArray
{
    public:
        vector<int> numbers;

        NumArray(vector<int> & nums)
        {
            numbers=nums;
        }

        int sumRange(int i, int j)
        {
            if(i < 0 || j > numbers.size())
            {
                return 0;
            }

            int result=0;

            for(int current=i;current<=j;++current)
            {
                result+=numbers[current];
            }

            return result;
        }
};

class NumArray
{
    public:
        vector<int> partialSums;

        NumArray(vector<int>& nums)
        {
            for(int i=0;i<nums.size();++i)
            {
                if(i==0)
                {
                    partialSums.emplace_back(nums[i]);
                }
                else
                {
                    partialSums.emplace_back(partialSums.back() + nums[i]);
                }
            }
        }

        int sumRange(int i, int j)
        {
            if(i==0)
            {
                return partialSums[j];
            }

            return (partialSums[j] - partialSums[i-1]);
        }
};