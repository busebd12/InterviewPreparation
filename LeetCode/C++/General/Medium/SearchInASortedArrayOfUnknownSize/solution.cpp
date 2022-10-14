/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

using namespace std;

/*
Solution: use binary search to look for the target in the array.

Time complexity: O(log(n)) [where n is the length of the array]
Space complexity: O(1)
*/

class Solution
{
    public:
        int search(const ArrayReader& reader, int target)
        {
            int result=-1;
            
            int low=0;
            
            int high=10000;
            
            while(low <= high)
            {
                int middle=(low + (high - low)/2);
                
                int value=reader.get(middle);
                
                if(value==target)
                {
                    result=middle;
                    
                    break;
                }
                else if(value < target)
                {
                    low=middle + 1;
                }
                else
                {
                    high=middle - 1;
                }
            }
            
            return result;
        }
};