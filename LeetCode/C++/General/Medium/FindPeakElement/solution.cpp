#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O(log(n))
Space complexity: O(1)
*/

class Solution
{
    public:
        int findPeakElement(vector<int> & nums)
        {   
            int n=nums.size();
            
            if(n==1)
            {
                return 0;
            }
            
            if(n==2)
            {
                return (nums[0] > nums[1]) ? 0 : 1;
            }
            
            int left=0;
            
            int right=n - 1;
            
            while(left <= right)
            {
                int middle=(left + (right - left)/2);
                
                //Case 1: peak element somewhere in the middle of the array
                if(middle > 0 && middle < n-1)
                {   
                    if(nums[middle - 1] < nums[middle] && nums[middle] > nums[middle + 1])
                    {
                        return middle;
                    }
                }
                //Case 2: peak element is the last number in the array
                else if(middle==n-1)
                {   
                    if(nums[middle - 1] < nums[middle])
                    {
                        return middle;
                    }
                }
                //Case 3: peak element is the first number in the array
                else
                {   
                    if(nums[middle] > nums[middle + 1])
                    {
                        return middle;
                    }
                }
                
                //If the number to the right of nums[middle] is larger, than the array is increasing from middle index, so the peak could be to the right
                if(nums[middle] < nums[middle + 1])
                {
                    left=middle + 1;
                }
                //Else, go left
                else
                {
                    right=middle - 1;
                }
            }
            
            return -1;
        }
};