#include <vector>
using namespace std;

/*
So, we need to compare the differences between nums[i] and nums[j]

The question also stipulates that, for each pair, index i must be strictly less than j (aka i comes before j)

Okay, well, what's an algorithm that specializes in comparing pairs of numbers while also guaranteeing that one index will always come before the other?

We can use merge sort!

Great, how do we apply merge sort here?

We do the following:

1) Sort the nums vector using merge sort.

As part of the this process, we will recursively divide the nums vector in half each time until we have two halves of size 1.

Then, we will merge each of these sorted halves into a single sorted list.

Awesome, where do we actually count the pairs? We do the counting right before we merge the two sorted halves.

After the counting, we proceed to merge the sorted halves like normal.

2) After doing mergeSort, we simply return the result

Note: this problem is extremely similar to LeetCode 2426 - Number of Pairs Satisfying Inequality.

The only differences are we don't have to manipulate the given inequality and the condition used in counting the number of pairs

Time complexity: O(n log n) [where n=length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int reversePairs(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int low=0;

            int high=n-1;

            mergeSort(nums, result, low, high);

            return result;
        }

        void mergeSort(vector<int> & nums, int & result, int low, int high)
        {
            if(low >= high)
            {
                return;
            }

            int middle=(low + (high - low)/2);

            mergeSort(nums, result, low, middle);

            mergeSort(nums, result, middle + 1, high);

            mergeTwoHalves(nums, result, low, middle, high);
        }

        void mergeTwoHalves(vector<int> & nums, int & result, int low, int middle, int high)
        {
            int extraSpace=(high - low) + 1;

            vector<int> lounge(extraSpace);

            int i=low;

            int j=middle + 1;

            //Here's where we will actually count the pairs while iterating through both of the sorted halves
            while(i <= middle and j <= high)
            {
                //This is the condition satisfying the inequality
                //Note: we need to cast the expression 2 * nums[j] to a long to handle overlfow since nums[j] can be equal to the largest or smallest interger value
                if(nums[i] > (long)2*nums[j])
                {
                    //Since the two halves are in sorted order, all numbers that come after nums[i] will be greater than or equal to nums[i]
                    //So, if 2 * nums[j] is already less than nums[i], then 2 * nums[j] will definitely be less than values larger than nums[i] (aka values that come after nums[i])
                    //How many total pairs is that? Since i is iterating from low to middle, the number of values in that range is (middle - i) + 1
                    int pairs=(middle - i) + 1;

                    result+=pairs;

                    j+=1;
                }
                else
                {
                    i+=1;
                }
            }

            //We are done with counting the pairs. Now, just do the normal merging of two sorted arrays
            i=low;

            j=middle + 1;

            int loungeIndex=0;

            while(i <= middle and j <= high)
            {
                if(nums[i] <= nums[j])
                {
                    lounge[loungeIndex]=nums[i];

                    i+=1;
                }
                else
                {
                    lounge[loungeIndex]=nums[j];

                    j+=1;
                }

                loungeIndex+=1;
            }

            while(i <= middle)
            {
                lounge[loungeIndex]=nums[i];

                i+=1;

                loungeIndex+=1;
            }

            while(j <= high)
            {
                lounge[loungeIndex]=nums[j];

                j+=1;

                loungeIndex+=1;
            }

            loungeIndex=0;

            for(int k=low;k<=high;k++)
            {
                nums[k]=lounge[loungeIndex];

                loungeIndex+=1;
            }
        }
};