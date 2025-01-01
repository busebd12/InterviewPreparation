#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        int findMin(vector<int> & nums)
        {
            int result=numeric_limits<int>::max();

            int n=nums.size();

            if(nums[0] < nums[n - 1])
            {
                return nums[0];
            }

            for(int i=0;i<n;i++)
            {
                result=min(result, nums[i]);
            }

            return result;
        }
};

class Solution
{
    public:
        int findMin(vector<int> & nums)
        {
            int n=nums.size();

            int low=0;

            int high=n - 1;

            //If the first number is less than the last number, then there is no rotation
            //So, just return the first number
            if(nums[low] < nums[high])
            {
                return nums[low];
            }

            //Do binary search
            while(low < high)
            {
                int middle=(low + (high - low)/2);

                //Duplicate number case: just decrement high
                if(nums[middle]==nums[high])
                {
                    high-=1;
                }
                //[middle + 1, high] subarray is the rotated portion
                else if(nums[middle] > nums[high])
                {
                    low=middle + 1;
                }
                //[low, middle] subarray is the rotated portion
                else
                {
                    high=middle;
                }
            }

            return nums[low];
        }
};