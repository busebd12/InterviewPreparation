#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: For each number in the input vector, use binary search to find the other number.

Time complexity: O(n log n) [where n is the length of numbers]
Space complexity: O(1)
*/

class Solution
{
    public:
        int binarySearch(vector<int> & numbers, int left, int right, int i, int target)
        {
            int index=-1;
            
            while(left <= right)
            {
                int middle=(left + (right - left)/2);
                
                if(numbers[middle]==target && middle!=i)
                {
                    index=middle;
                    
                    break;
                }
                else if(numbers[middle] > target)
                {
                    right=middle - 1;
                }
                else
                {
                    left=middle + 1;
                }
            }
            
            return index;
        }
    
        vector<int> twoSum(vector<int> & numbers, int target)
        {
            vector<int> result(2, -1);
            
            int n=numbers.size();
            
            for(int i=0;i<n;i++)
            {
                int current=numbers[i];
                
                int desired=target - current;
                
                int j=binarySearch(numbers, 0, n-1, i, desired);
                
                if(j!=-1)
                {
                    //REMEMBER: add +1 to the indices since the input is a one-indexed vector
                    result[0]=min(i + 1, j + 1);
                    
                    result[1]=max(i + 1, j + 1);
                }
            }
            
            return result;
        }
};

/*
Solution 2: two pointer approach.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> twoSum(vector<int> & numbers, int target)
        {
            vector<int> result(2, -1);
            
            int n=numbers.size();
            
            //TWo pointers that will traverse the vector from left-to-right and from right-to-left
            int left=0;
            
            int right=n - 1;
            
            while(left < right)
            {
                int sum=numbers[left] + numbers[right];
                
                //Found the target
                if(sum==target)
                {
                    result[0]=left + 1;
                    
                    result[1]=right + 1;
                    
                    break;
                }
                //If the sum is larger than the target, move the right pointer down one
                //Since the array is sorted, moving the right pointer down one will ensure that numbers[right] points to a smaller number next time
                //This will decrease the overall value of the sum
                else if(sum > target)
                {
                    right-=1;
                }
                //If the sum is less than the target, move the left pointer up one
                //Since the vector is sorted, moving the left pointer up one will ensure that numbers[left] points to a larger number next time
                //This will increase the overall value of the sum
                else
                {
                    left+=1;
                }
            }
            
            return result;
        }
};