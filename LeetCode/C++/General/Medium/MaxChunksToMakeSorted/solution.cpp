#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/1792243/O(n)-time-complexity-using-sum.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int maxChunksToSorted(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            int sum=0;
            
            int indexSum=0;
            
            for(int index=0;index<n;index++)
            {
                int number=arr[index];
                
                sum+=number;
                
                indexSum+=index;
                
                if(indexSum==sum)
                {
                    result+=1;
                    
                    sum=0;
                    
                    indexSum=0;
                }
            }
            
            return result;
        }
};