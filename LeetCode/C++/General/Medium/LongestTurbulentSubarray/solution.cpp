#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int maxTurbulenceSize(vector<int>& arr)
        {
            int result=0;

            int n=arr.size();

            if(n < 2)
            {
                result=n;

                return result;
            }

            //Set result=1 to handle the case of a length two array where both numbers are equal -> answer is 1 in this case
            result=1;

            int start=0;

            int middle=0;

            while(start + 1 < n)
            {
                if(arr[start]==arr[start + 1])
                {
                    start+=1;
                }
                else
                {
                    middle=start + 1;

                    //A "peak" or "valley" will have alternating signs
                    //Examples: [1 < 7 > 2] or [8 > 1 < 9]
                    //So, we just need to keep iterating while we have found a peak or valley in the array
                    while(middle + 1 < n and isPeakOrValley(arr, middle)==true)
                    {
                        middle+=1;
                    }

                    //The subarray length will be from start up to and including the index directly after the last peak or valley
                    int length=(middle - start) + 1;

                    result=max(result, length);

                    start=middle;
                }
            }

            return result;
        }

        bool isPeakOrValley(vector<int> & arr, int middle)
        {
            bool isPeak=(arr[middle - 1] < arr[middle] and arr[middle] > arr[middle + 1]);

            bool isValley=(arr[middle - 1] > arr[middle] and arr[middle] < arr[middle + 1]);
            
            return (isPeak or isValley);
        }
};