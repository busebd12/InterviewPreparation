#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830699/Python-Two-Pointers-Approach-with-Explanation
2) https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/880195/Two-pointers-oror-C%2B%2B

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int findLengthOfShortestSubarray(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            int i=0;
            
            while(i + 1 < n and arr[i] <= arr[i + 1])
            {
                i+=1;
            }
            
            if(i==n-1)
            {
                return 0;
            }
            
            int j=n - 1;
            
            while(j > i and arr[j] >= arr[j - 1])
            {
                j-=1;
            }
            
            int prefixLength=n - i - 1;
            
            int suffixLength=j;
            
            result=min(prefixLength, suffixLength);
            
            int low=0;
            
            int high=j;
            
            while(low <= i and high < n)
            {
                if(arr[low] <= arr[high])
                {
                    int lengthToRemove=high - low - 1;
                    
                    result=min(result, lengthToRemove);
                    
                    low+=1;
                }
                else
                {
                    high+=1;
                }
            }
            
            return result;
        }
};