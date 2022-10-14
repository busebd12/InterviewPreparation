#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n^2) [where n is the length of arr]
Space complexity: O(1)
*/

class Solution
{
    public:
        int longestMountain(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            if(n < 3)
            {
                return result;
            }
            
            for(int i=1;i<n-1;i++)
            {
                //If index i is the peak for a potential mountain array
                if(arr[i - 1] < arr[i] and arr[i] > arr[i + 1])
                {
                    int length=1;
                    
                    //Add the length of the left side
                    length+=getLeftSideLength(arr, i - 1);
                    
                    //Add the length of the right side
                    length+=getRightSideLength(arr, i + 1);
                    
                    result=max(result, length);
                }
            }
            
            return result;
        }
    
        int getLeftSideLength(vector<int> & arr, int index)
        {
            int leftSideLength=1;
            
            while(index - 1 >= 0 and arr[index] > arr[index - 1])
            {
                leftSideLength+=1;
                
                index-=1;
            }
            
            return leftSideLength;
        }
    
        int getRightSideLength(vector<int> & arr, int index)
        {
            int rightSideLength=1;
            
            while(index + 1 < arr.size() and arr[index] > arr[index + 1])
            {
                rightSideLength+=1;
                
                index+=1;
            }
            
            return rightSideLength;
        }
};