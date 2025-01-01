#include <vector>
using namespace std;

/*
Time complexity: O(n^2) [where n is the length of arr]
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> pancakeSort(vector<int> & arr)
        {
            vector<int> result;

            int n=arr.size();

            int start=0;

            int end=n - 1;

            while(start < end)
            {
                //1) Find the index of the max value
                int maxValueIndex=0;

                int maxValue=0;

                for(int i=0;i<=end;i++)
                {
                    if(arr[i] > maxValue)
                    {
                        maxValue=arr[i];

                        maxValueIndex=i;
                    }
                }

                //2) Reverse the subarray from [start, maxValueIndex]
                int low=start;

                int high=maxValueIndex;

                result.emplace_back((maxValueIndex - start) + 1);

                while(low < high)
                {
                    swap(arr[low], arr[high]);

                    low+=1;

                    high-=1;
                }

                //3)Reverse the entire array
                low=start;

                high=end;

                result.emplace_back((end - start) + 1);

                while(low < high)
                {
                    swap(arr[low], arr[high]);

                    low+=1;

                    high-=1;
                }

                end-=1;
            }

            return result;
        }
};