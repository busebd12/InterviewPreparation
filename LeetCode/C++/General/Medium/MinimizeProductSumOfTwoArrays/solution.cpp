#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minProductSum(vector<int> & nums1, vector<int> & nums2)
        {
            int result=0;
            
            int n=nums1.size();
            
            //Sort both the arrays
            sort(begin(nums1), end(nums1));
            
            sort(begin(nums2), end(nums2));
            
            int left=0;
            
            int right=n-1;
            
            //Iterate through the first array from left-to-right and the second array from right-to-left and add the product of nums1[left] and nums2[right] to the sum
            //By doing this, we are multiplying the smallest value from nums1 with the largest value from nums2 during each loop iteration
            while(left < n && right >= 0)
            {
                result+=(nums1[left] * nums2[right]);
                
                left+=1;
                
                right-=1;
            }
            
            return result;
        }
};