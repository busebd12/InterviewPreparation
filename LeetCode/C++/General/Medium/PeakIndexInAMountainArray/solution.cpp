#include <vector>
using namespace std;

/*
Solution: binary search.

Time complexity: O(log n) [where n is the length of arr]
Space complexity: O(1)
*/

class Solution
{
    public:
        int peakIndexInMountainArray(vector<int> & arr)
        {
            int result=-1;
            
            int n=arr.size();
            
            int left=0;
            
            int right=n-1;
            
            while(left <= right)
            {
                int middle=(left + (right - left)/2);
                
                if(middle - 1 < 0 and middle + 1 >= 0)
                {
                    left=middle + 1;
                }
                else if(middle - 1 >= 0 and middle + 1 >= n)
                {
                    right=middle - 1;
                }
                else if(middle - 1 >= 0 and middle + 1 <= n - 1)
                {
                    if(arr[middle - 1] < arr[middle] and arr[middle] > arr[middle + 1])
                    {
                        result=middle;
                        
                        break;
                    }
                    else if(arr[middle - 1] < arr[middle] and arr[middle] < arr[middle + 1])
                    {
                        left=middle + 1;
                    }
                    else if(arr[middle - 1] > arr[middle] and arr[middle] > arr[middle + 1])
                    {
                        right=middle - 1;
                    }
                }
            }
            
            return result;
        }
};